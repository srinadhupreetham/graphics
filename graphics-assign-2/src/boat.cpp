#include "main.h"
#include "boat.h"

Boat::Boat(float x,float y,float z,float length,float width,float height,color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    float l,w,hn,hf;
    l = length/2;
    w = width/2;
    hn = height/4;\
    hf = height;
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
    this->base = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data_base, COLOR_BROWN, GL_FILL);
    this->right = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_right, COLOR_WHITE, GL_FILL);
    this->left = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_left, COLOR_WHITE, GL_FILL);
    this->basetop = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data_basetop, COLOR_BASETOP, GL_FILL);
    this->frontdom = create3DObject(GL_TRIANGLES,7*3,vertex_buffer_data_frontdom, COLOR_BROWN, GL_FILL);
    this->backdom = create3DObject(GL_TRIANGLES,7*3, vertex_buffer_data_backdom,COLOR_BROWN, GL_FILL);
     this->backdomtop = create3DObject(GL_TRIANGLES,3, vertex_buffer_data_backdomtop,COLOR_BROWN, GL_FILL);
     this->frontdomtop = create3DObject(GL_TRIANGLES,3, vertex_buffer_data_frontdomtop,COLOR_BROWN, GL_FILL);
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
}

void Boat::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}

void Boat::tick() {
//this->rotation += 1;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

