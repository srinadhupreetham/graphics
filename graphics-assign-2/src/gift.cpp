#include "gift.h"
#include "main.h"
Gift::Gift(float x, float y,float z, color_t color)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    spe = 0.015;
    float w = 0.4,l=0.4,hn=0.6,hf=-0.6;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
//        w,l,-hn,
//        -w,l,-hn,
//        w,-l,-hn,

//        -w,l,-hn,
//        w,-l,-hn,
//        -w,-l,-hn,
        w,l,-2*hn,
        -w,l,-2*hn,
        0,0,-2*hn,

        -w,-l,-2*hn,
        w,-l,-2*hn,
        0,0,-2*hn,

        -w,l,-2*hn,
        -w,-l,-2*hn,
        0,0,-2*hn,

        -w,l,-2*hn,
        w,l,-2*hn,
        0,0,-2*hn,

        w,l,2*hn,
        -w,l,2*hn,
        0,0,2*hn,

        -w,-l,2*hn,
        w,-l,2*hn,
        0,0,2*hn,

        -w,l,2*hn,
        -w,-l,2*hn,
        0,0,2*hn,

        -w,l,2*hn,
        w,l,2*hn,
        0,0,2*hn,
        //base top
//        w,l,-hf,
//        -w,l,-hf,
//        w,-l,-hf,

//        -w,l,-hf,
//        w,-l,-hf,
//        -w,-l,-hf,
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
    };
//    color = {rand()%128+50,rand()%128+50,rand()%128};
    GLfloat color_data[] = {
        w,l,-2*hn,
        -w,l,-2*hn,
        1,1,-2*hn,

        -w,-l,-2*hn,
        w,-l,-2*hn,
        1,1,-2*hn,

        -w,l,-2*hn,
        -w,-l,-2*hn,
        1,1,-2*hn,

        -w,l,-2*hn,
        w,l,-2*hn,
        1,1,-2*hn,

        w,l,2*hn,
        -w,l,2*hn,
        1,1,2*hn,

        -w,-l,2*hn,
        w,-l,2*hn,
        1,1,2*hn,

        -w,l,2*hn,
        -w,-l,2*hn,
        1,1,2*hn,

        -w,l,2*hn,
        w,l,2*hn,
        1,1,2*hn,
        //base top
//        w,l,-hf,
//        -w,l,-hf,
//        w,-l,-hf,

//        -w,l,-hf,
//        w,-l,-hf,
//        -w,-l,-hf,
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
    };
    this->object = create3DObject(GL_TRIANGLES, 16*3, vertex_buffer_data, color_data, GL_FILL);
}

void Gift::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Gift::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}

void Gift::tick() {
this->rotation += 1;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
