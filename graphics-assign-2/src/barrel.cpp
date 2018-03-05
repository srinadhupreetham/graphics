#include "barrel.h"
#include "main.h"

Barrel::Barrel(float x,float y,float z, float radius,float length,float back)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.015;
    GLfloat vertex_buffer_data_1[720*3*3];
            int i=0;
            float param = 90.0;
            for(i=0;i<720;i++)
            {
             if(i%2==0)
             {
                 vertex_buffer_data_1[9*i] = radius * cos(param * M_PI/180);
                 vertex_buffer_data_1[9*i+1] = radius * sin(param * M_PI/180);
                 vertex_buffer_data_1[9*i+2] = 0;

                 vertex_buffer_data_1[9*i+3] = radius * cos(param * M_PI/180);
                 vertex_buffer_data_1[9*i+4] = radius * sin(param * M_PI/180);
                 vertex_buffer_data_1[9*i+5] = length;


                vertex_buffer_data_1[9*i+6] = radius * cos((param+0.5) * M_PI/180);
                vertex_buffer_data_1[9*i+7] = radius * sin((param+0.5) * M_PI/180);
                vertex_buffer_data_1[9*i+8] = length;
            }
             if(i%2==1)
             {
                 vertex_buffer_data_1[9*i] = radius * cos((param+0.5) * M_PI/180);
                 vertex_buffer_data_1[9*i+1] = radius * sin((param+0.5) * M_PI/180);
                 vertex_buffer_data_1[9*i+2] = length;

                 vertex_buffer_data_1[9*i+3] = radius * cos((param+0.5) * M_PI/180);
                 vertex_buffer_data_1[9*i+4] = radius * sin((param+0.5) * M_PI/180);
                 vertex_buffer_data_1[9*i+5] = 0;

//                param += 0.5;
                vertex_buffer_data_1[9*i+6] = radius * cos(param * M_PI/180);
                vertex_buffer_data_1[9*i+7] = radius * sin(param * M_PI/180);
                vertex_buffer_data_1[9*i+8] = 0;
                param += 0.5;
            }

           }
            GLfloat vertex_buffer_data_2[720*3*3];
                    param = 270.0;
                    for(i=0;i<720;i++)
                    {
                     if(i%2==0)
                     {
                         vertex_buffer_data_2[9*i] = radius * cos(param * M_PI/180);
                         vertex_buffer_data_2[9*i+1] = radius * sin(param * M_PI/180);
                         vertex_buffer_data_2[9*i+2] = 0;

                         vertex_buffer_data_2[9*i+3] = radius * cos(param * M_PI/180);
                         vertex_buffer_data_2[9*i+4] = radius * sin(param * M_PI/180);
                         vertex_buffer_data_2[9*i+5] = length;


                        vertex_buffer_data_2[9*i+6] = radius * cos((param+0.5) * M_PI/180);
                        vertex_buffer_data_2[9*i+7] = radius * sin((param+0.5) * M_PI/180);
                        vertex_buffer_data_2[9*i+8] = length;
                    }
                     if(i%2==1)
                     {
                         vertex_buffer_data_2[9*i] = radius * cos((param+0.5) * M_PI/180);
                         vertex_buffer_data_2[9*i+1] = radius * sin((param+0.5) * M_PI/180);
                         vertex_buffer_data_2[9*i+2] = length;

                         vertex_buffer_data_2[9*i+3] = radius * cos((param+0.5) * M_PI/180);
                         vertex_buffer_data_2[9*i+4] = radius * sin((param+0.5) * M_PI/180);
                         vertex_buffer_data_2[9*i+5] = 0;

        //                param += 0.5;
                        vertex_buffer_data_2[9*i+6] = radius * cos(param * M_PI/180);
                        vertex_buffer_data_2[9*i+7] = radius * sin(param * M_PI/180);
                        vertex_buffer_data_2[9*i+8] = 0;
                        param += 0.5;
                    }

                   }
                    GLfloat vertex_buffer_data3[720*3*3];
//                    GLfloat vertex_buffer_data4[720*3*3];
                            i=0;
                            param = 0.0;
                            for(i=0;i<720;i++)
                            {
                                if(i%2==0){
                                 vertex_buffer_data3[9*i] = 0.5;
                                 vertex_buffer_data3[9*i+1] = 0.0;
                                 vertex_buffer_data3[9*i+2] = 0.0;

                                 vertex_buffer_data3[9*i+3] = 0.0;
                                 vertex_buffer_data3[9*i+4] = 0.0;
                                 vertex_buffer_data3[9*i+5] = 0.0;


                                vertex_buffer_data3[9*i+6] = 0.0;
                                vertex_buffer_data3[9*i+7] = 0.0;
                                vertex_buffer_data3[9*i+8] = 0.0;}
                                if(i%2==1){
                                 vertex_buffer_data3[9*i] = 0.0;
                                 vertex_buffer_data3[9*i+1] = 0.0;
                                 vertex_buffer_data3[9*i+2] = 0.0;

                                 vertex_buffer_data3[9*i+3] = 0.5;
                                 vertex_buffer_data3[9*i+4] = 0.0;
                                 vertex_buffer_data3[9*i+5] = 0.0;


                                vertex_buffer_data3[9*i+6] = 0.5;
                                vertex_buffer_data3[9*i+7] = 0.0;
                                vertex_buffer_data3[9*i+8] = 0.0;}


                           }


            this->barrel1 = create3DObject(GL_TRIANGLES, 240*9, vertex_buffer_data_1, vertex_buffer_data3, GL_FILL);
                    this->barrel2 = create3DObject(GL_TRIANGLES, 240*9, vertex_buffer_data_2, vertex_buffer_data3, GL_FILL);

}

void Barrel::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate1 = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    Matrices.model *= (translate1 *rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->barrel1);
    draw3DObject(this->barrel2);
}
void Barrel::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}

void Barrel::tickdown() {
//this->rotation += 1;
    // this->position.x -= speed;
     this->position.z -= speed;
}
void Barrel::tickup() {
    this->position.z += speed;
}
