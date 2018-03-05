#include "rock.h"
#include "main.h"

Rock::Rock(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    this->length = 2;
    this->width = 2;
    this->height = 2;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
//        0,0,0,
//        1,1,-2,
//        1,-1,-2,

//        0,0,0,
//        1,1,-2,
//        -1,1,-2,

//        0,0,0,
//        -1,-1,-2,
//        -1,1,-2,

//        0,0,0,
//        -1,-1,-2,
//        1,-1,-2,

//        1,1,-2,
//        1,-1,-2,
//        -1,-1,-2,

//        1,1,-2,
//        -1,1,-2,
//        -1,-1,-2
        0,0,0,
        1,1,-1,
        1,-1,-1,

        0,0,0,
        1,1,-1,
        -1,1,-1,

        0,0,0,
        -1,-1,-1,
        -1,1,-1,

        0,0,0,
        -1,-1,-1,
        1,-1,-1,

        -1,-1,-1,
        -1,-1,-2,
        1,-1,-2,

         -1,-1,-1,
        1,-1,-2,
        1,-1,-1,

        -1,1,-1,
        -1,1,-2,
        1,1,-2,

         -1,1,-1,
        1,1,-2,
        1,1,-1,

        -1,1,-1,
        -1,1,-2,
        -1,-1,-2,

        -1,1,-1,
        -1,-1,-2,
        -1,-1,-1,


        1,1,-1,
        1,1,-2,
        1,-1,-2,

        1,1,-1,
        1,-1,-2,
        1,-1,-1,
    };
    static const GLfloat color_buffer_data[] = {
        0,0,0,
        0.5,0.5,0.5,
        0.5,0.5,0.5,

        0,0,0,
        0.5,0.5,0.5,
        0.5,0.5,0.5,

        0,0,0,
        0.5,0.5,0.5,
        0.5,0.5,0.5,

        0,0,0,
        0.5,0.5,0.5,
        0.5,0.5,0.5,

        0,0,0,
        0.5,0.5,0.5,
        0.5,0.5,0.5,

        0,0,0,
        0.5,0,0,
        0.5,0,0,
        0,0,0,
        0.5,0,0,
        0.5,0,0,
        0,0,0,
        0.5,0,0,
        0.5,0,0,
        0,0,0,
        0.5,0,0,
        0.5,0,0,
        0,0,0,
        0,0.5,0,
        0,0.5,0,
        0,0,0,
        0,0.5,0,
        0,0.5,0,
        0,0,0,
        0,0.5,0,
        0,0.5,0,

    };

    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void Rock::draw(glm::mat4 VP) {
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

void Rock::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}

void Rock::tick() {
this->rotation += 1;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

bounding_box_t Rock::bounding_box() {
    float x = this->position.x, y = this->position.y;
    float z = this->position.z - 1;
    float len = this->length;
    float wid = this->width;
    float high = this->height;
//    float s = this->speedy;
    bounding_box_t bbox = { x, y,z,len,wid,high};
    return bbox;
}
