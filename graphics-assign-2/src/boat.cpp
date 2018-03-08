#include "main.h"
#include "boat.h"

Boat::Boat(float x,float y,float z,float length,float width,float height,color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
//    this->rotation2 = 0;
    speed = 0.02;
    this ->velocity = 0.3;
//    speedz = 1.20;
    this->length = length;
    this->width = width;
    this->height = 2*height;
    float l,w,hn,hf;
    l = length/2;
    w = width/2;
    hn = height/4;\
    hf = height;
    float radius = w;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data_base[] = {
        w,l,-hf,
        -w,l,-hf,
        w,-l,-hf,

        -w,l,-hf,
        w,-l,-hf,
        -w,-l,-hf,
        //end of bottom face
        w,l,-hf,
        -w,l,-hf,
        w,l,-hn,

        -w,l,-hn,
        -w,l,-hf,
        w,l,-hn,
        //end of back face
        w,-l,-hf,
        -w,-l,-hf,
        w,-l,-hn,

        -w,-l,-hn,
        -w,-l,-hf,
        w,-l,-hn,
        //end of front face
        w,l,-hf,
        w,-l,-hf,
        w,l,-hn,

        w,-l,-hn,
        w,-l,-hf,
        w,l,-hn,
        //end of right face
        -w,l,-hf,
        -w,-l,-hf,
        -w,l,-hn,

        -w,-l,-hn,
        -w,-l,-hf,
        -w,l,-hn
        //end of left face

    };
    static const GLfloat vertex_buffer_data_right[] = {
      w,l,-hn,
      w,-l,-hn,
      w,l,hf/2,

      w,l,hf/2,
      w,-l,hf/2,
      w,-l,-hn
    };
    static const GLfloat vertex_buffer_data_left[] = {
      -w,l,-hn,
      -w,-l,-hn,
      -w,l,hf/2,

      -w,l,hf/2,
      -w,-l,hf/2,
      -w,-l,-hn
    };
    static const GLfloat vertex_buffer_data_basetop[] = {
        w,l,-hn,
        -w,l,-hn,
        w,-l,-hn,

        -w,l,-hn,
        w,-l,-hn,
        -w,-l,-hn
    };
    float ld = 5*length/5;
    static const GLfloat vertex_buffer_data_frontdomtop[] = {
        0,ld,hf/2,
        -w,l,hf/2,
        w,l,hf/2,
    };
    static const GLfloat vertex_buffer_data_frontdom[] = {
        0,ld,-hf,
        -w,l,-hf,
        w,l,-hf,
        //bottom
        -w,l,hf/2,
        -w,l,-hf,
        w,l,-hf,

        -w,l,hf/2,
        w,l,hf/2,
        w,l,-hf,
        //front
        0,ld,hf/2,
        0,ld,-hf,
        w,l,-hf/2,

        0,ld,hf/2,
        w,l,hf/2,
        w,l,-hf,
        //right
        0,ld,hf/2,
        0,ld,-hf,
        -w,l,-hf,

        0,ld,hf/2,
        -w,l,hf/2,
        -w,l,-hf
    };
    static const GLfloat vertex_buffer_data_backdomtop[] = {
        0,-ld,hf/2,
        -w,-l,hf/2,
        w,-l,hf/2,
    };
    static const GLfloat vertex_buffer_data_backdom[] = {

        0,-ld,-hf,
        -w,-l,-hf,
        w,-l,-hf,
        //bottom
        -w,-l,hf/2,
        -w,-l,-hf,
        w,-l,-hf,

        -w,-l,hf/2,
        w,-l,hf/2,
        w,-l,-hf,
        //front
        0,-ld,hf/2,
        0,-ld,-hf,
        w,-l,-hf,

        0,-ld,hf/2,
        w,-l,hf/2,
        w,-l,-hf,
        //right
        0,-ld,hf/2,
        0,-ld,-hf,
        -w,-l,-hf,

        0,-ld,hf/2,
        -w,-l,hf/2,
        -w,-l,-hf
    };
    GLfloat vertex_buffer_data_1[720*3*3];
            int i=0;
            float param = -90.0;
            for(i=0;i<720;i++)
            {
             if(i%2==0)
             {
                 vertex_buffer_data_1[9*i] = radius * sin(param * M_PI/180);
                 vertex_buffer_data_1[9*i+1] = -length/2;
                 vertex_buffer_data_1[9*i+2] = radius * cos(param * M_PI/180)+1;

                 vertex_buffer_data_1[9*i+3] = radius * sin(param * M_PI/180);
                 vertex_buffer_data_1[9*i+4] = 0;
                 vertex_buffer_data_1[9*i+5] = radius * cos(param * M_PI/180)+1;


                vertex_buffer_data_1[9*i+6] = radius * sin((param+0.5) * M_PI/180);
                vertex_buffer_data_1[9*i+7] = 0;
                vertex_buffer_data_1[9*i+8] = radius * cos((param+0.5) * M_PI/180)+1;
            }
             if(i%2==1)
             {
                 vertex_buffer_data_1[9*i] = radius * sin((param+0.5) * M_PI/180);
                 vertex_buffer_data_1[9*i+1] = 0;
                 vertex_buffer_data_1[9*i+2] = radius * cos((param+0.5) * M_PI/180)+1;

                 vertex_buffer_data_1[9*i+3] = radius * sin((param+0.5) * M_PI/180);
                 vertex_buffer_data_1[9*i+4] = -length/2;
                 vertex_buffer_data_1[9*i+5] = radius * cos((param+0.5) * M_PI/180)+1;

//                param += 0.5;
                vertex_buffer_data_1[9*i+6] = radius * sin(param * M_PI/180);
                vertex_buffer_data_1[9*i+7] = -length/2;
                vertex_buffer_data_1[9*i+8] = radius * cos(param * M_PI/180)+1;
                param += 0.5;
            }

           }
    this->base = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data_base, COLOR_BROWN, GL_FILL);
    this->right = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_right, COLOR_WHITE, GL_FILL);
    this->left = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_left, COLOR_WHITE, GL_FILL);
    this->basetop = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data_basetop, COLOR_BASETOP, GL_FILL);
    this->frontdom = create3DObject(GL_TRIANGLES,7*3,vertex_buffer_data_frontdom, COLOR_BROWN, GL_FILL);
    this->backdom = create3DObject(GL_TRIANGLES,7*3, vertex_buffer_data_backdom,COLOR_BROWN, GL_FILL);
     this->backdomtop = create3DObject(GL_TRIANGLES,3, vertex_buffer_data_backdomtop,COLOR_BROWN, GL_FILL);
     this->frontdomtop = create3DObject(GL_TRIANGLES,3, vertex_buffer_data_frontdomtop,COLOR_BROWN, GL_FILL);
    this->top = create3DObject(GL_TRIANGLES, 240*9, vertex_buffer_data_1, COLOR_BLACK, GL_FILL);
}

void Boat::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate1 = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
//    glm::mat4 translate2 = glm::translate (-this->position);
    Matrices.model *= (translate1 * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->base);
    draw3DObject(this->right);
    draw3DObject(this->left);
    draw3DObject(this->basetop);
    draw3DObject(this->frontdom);
    draw3DObject(this->backdom);
    draw3DObject(this->backdomtop);
    draw3DObject(this->frontdomtop);
    draw3DObject(this->top);

}

void Boat::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}

void Boat::tickdown() {
//this->rotation += 1;
    // this->position.x -= speed;
     this->position.z -= speed;
}
void Boat::tickup() {
    this->position.z += speed;
}
void Boat::tick() {
        speedz = speedz - 0.012;
         this -> position.z += speedz;
}
bounding_box_t Boat::bounding_box() {
    float x = this->position.x, y = this->position.y;
    float z = this->position.z;
    float len = this->length;
    float wid = this->width;
    float high = this->height;
//    float s = this->speedy;
    bounding_box_t bbox = { x, y,z,len,wid,high};
    return bbox;
}
