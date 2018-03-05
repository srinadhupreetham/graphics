#include "flag.h"
#include "main.h"

Flag::Flag(float x, float y,float z,float length,float width,float radius,int flag,float rotation1)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->flag = flag;
//    if /*(flag ==0)
//    {*/
        static const GLfloat vertex_buffer_data_normal[] = {
            0,width/2,0,
            0,width/2,length,
            0,-width/2,0,

            0,width/2,length,
            0,-width/2,length,
            0,-width/2,0
        };
//    }
    /*if (flag == 1)
    {*/
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
//    }
//    if (flag == -1)
//    {
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
//    }
    this -> straight = create3DObject(GL_TRIANGLES,6,vertex_buffer_data_normal,COLOR_GREEN,GL_FILL);
    this -> left = create3DObject(GL_TRIANGLES,240*9, vertex_buffer_data_1, COLOR_GREEN, GL_FILL);
    this -> right = create3DObject(GL_TRIANGLES,240*9, vertex_buffer_data_2, COLOR_GREEN, GL_FILL);
}

void Flag::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate1 = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
//    glm::mat4 translate2 = glm::translate (-this->position);
    Matrices.model *= (translate1 * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(this->flag == 0)
    draw3DObject(this->straight);
    else if(this->flag == 1)
    draw3DObject(this->left);
    else
    draw3DObject(this->right);
}
void Flag::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}

void Flag::tick() {
//this->rotation += 1;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
