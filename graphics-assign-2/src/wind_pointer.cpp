#include "main.h"
#include "wind_pointer.h"

Wind_pointer::Wind_pointer(float x,float y,float z,color_t color)
{
this->position = glm::vec3(x, y, z);
    static const GLfloat vertex_buffer_data[] = {
        -0.5,0,0,
        0.5,0,0,
        0,-1,0,

        -0.25,1,0,
        -0.25,0,0,
        0.25,0,0,

        -0.25,1,0,
        0.25,1,0,
        0.25,0,0
    };
    this->object = create3DObject(GL_TRIANGLES, 3*3, vertex_buffer_data, color, GL_FILL);
}

void Wind_pointer::draw(glm::mat4 VP) {
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

void Wind_pointer::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}
