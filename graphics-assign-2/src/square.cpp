#include "square.h"
#include "main.h"
Square::Square(float x,float y,float z,float l,color_t color)
{
    this->position = glm::vec3(x, y, z);
    float d = 0.0;
    static const GLfloat vertex_buffer_data[] = {
        2.5,2.5,0,
        2.5,-2.5,0,
        -2.5,-2.5,0,

        2.5,2.5,0,
        -2.5,2.5,0,
        -2.5,-2.5,0,
//        5,5,0,
//        5,-5,0,
//        -5,-5,0,

//        5,5,0,
//        -5,5,0,
//        -5,-5,0,
    };
    color = {51,255,255};
    this->object = create3DObject(GL_TRIANGLES, 3*3, vertex_buffer_data, color, GL_FILL);
}

void Square::draw(glm::mat4 VP) {
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

void Square::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}
