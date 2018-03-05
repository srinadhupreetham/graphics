#include "wave.h"
#include "main.h"

Wave::Wave(float x,float y,float z, float radius,float length,float back)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.05;
    speedz = 0.01;
    GLfloat vertex_buffer_data[720*3*3];
            int i=0;
            float param = 90.0;
            for(i=0;i<720;i++)
            {
             if(i%2==0)
             {
                 vertex_buffer_data[9*i] = radius * cos(param * M_PI/180);
                 vertex_buffer_data[9*i+1] = -length/2;
                 vertex_buffer_data[9*i+2] = radius * sin(param * M_PI/180);

                 vertex_buffer_data[9*i+3] = radius * cos(param * M_PI/180);
                 vertex_buffer_data[9*i+4] = length/2;
                 vertex_buffer_data[9*i+5] = radius * sin(param * M_PI/180);


                vertex_buffer_data[9*i+6] = radius * cos((param+0.5) * M_PI/180);
                vertex_buffer_data[9*i+7] = length/2;
                vertex_buffer_data[9*i+8] = radius * sin((param+0.5) * M_PI/180);
            }
             if(i%2==1)
             {
                 vertex_buffer_data[9*i] = radius * cos((param+0.5) * M_PI/180);
                 vertex_buffer_data[9*i+1] = length/2;
                 vertex_buffer_data[9*i+2] = radius * sin((param+0.5) * M_PI/180);

                 vertex_buffer_data[9*i+3] = radius * cos((param+0.5) * M_PI/180);
                 vertex_buffer_data[9*i+4] = -length/2;
                 vertex_buffer_data[9*i+5] = radius * sin((param+0.5) * M_PI/180);

//                param += 0.5;
                vertex_buffer_data[9*i+6] = radius * cos(param * M_PI/180);
                vertex_buffer_data[9*i+7] = -length/2;
                vertex_buffer_data[9*i+8] = radius * sin(param * M_PI/180);
                param += 0.5;
            }

           }
//            GLfloat vertex_buffer_data2[720*3*3];
//                    i=0;
//                    param = 0.0;
//                    for(i=0;i<720;i++)
//                    {
//                     if(i%2==0)
//                     {
//                         vertex_buffer_data2[9*i] = -radius * cos(param * M_PI/180);
//                         vertex_buffer_data2[9*i+1] = -length/2;
//                         vertex_buffer_data2[9*i+2] = -radius * sin(param * M_PI/180);

//                         vertex_buffer_data2[9*i+3] = -radius * cos(param * M_PI/180);
//                         vertex_buffer_data2[9*i+4] = length/2;
//                         vertex_buffer_data2[9*i+5] = -radius * sin(param * M_PI/180);


//                        vertex_buffer_data2[9*i+6] = -radius * cos((param+0.5) * M_PI/180);
//                        vertex_buffer_data2[9*i+7] = length/2;
//                        vertex_buffer_data2[9*i+8] = -radius * sin((param+0.5) * M_PI/180);
//                    }
//                     if(i%2==1)
//                     {
//                         vertex_buffer_data2[9*i] = -radius * cos((param+0.5) * M_PI/180);
//                         vertex_buffer_data2[9*i+1] = length/2;
//                         vertex_buffer_data2[9*i+2] = -radius * sin((param+0.5) * M_PI/180);

//                         vertex_buffer_data2[9*i+3] = -radius * cos((param+0.5) * M_PI/180);
//                         vertex_buffer_data2[9*i+4] = -length/2;
//                         vertex_buffer_data2[9*i+5] = -radius * sin((param+0.5) * M_PI/180);

//        //                param += 0.5;
//                        vertex_buffer_data2[9*i+6] = -radius * cos(param * M_PI/180);
//                        vertex_buffer_data2[9*i+7] = -length/2;
//                        vertex_buffer_data2[9*i+8] = -radius * sin(param * M_PI/180);
//                        param += 0.5;
//                    }


//            this->base = create3DObject(GL_TRIANGLES,)
            this->object = create3DObject(GL_TRIANGLES, 120*9, vertex_buffer_data/*+120*9*/, COLOR_WAVE, GL_FILL);

}

void Wave::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate1 = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (90.0f * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
//    glm::mat4 translate2 = glm::translate (-this->position);
    Matrices.model *= (translate1 * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}
void Wave::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}

void Wave::tick() {
//this->rotation += 1;
    // this->position.x -= speed;
     this->position.y += speed;
}
void Wave::tickdown() {
//this->rotation += 1;
    // this->position.x -= speed;
     this->position.z -= speedz;
}
void Wave::tickup() {
    this->position.z += speedz;
}


