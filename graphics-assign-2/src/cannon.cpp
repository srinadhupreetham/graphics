#include "cannon.h"
#include "main.h"

Cannon::Cannon(float x,float y,float z, float radius,float length,float back)
{
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->rotation2 = 0;
    speed = 1;
    GLfloat vertex_buffer_data[720*3*3];
            int i=0;
            float param = 0.0;
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
            GLfloat vertex_buffer_data2[720*3*3];
                    i=0;
                    param = 0.0;
                    for(i=0;i<720;i++)
                    {
                     if(i%2==0)
                     {
                         vertex_buffer_data2[9*i] = -radius * cos(param * M_PI/180);
                         vertex_buffer_data2[9*i+1] = -length/2;
                         vertex_buffer_data2[9*i+2] = -radius * sin(param * M_PI/180);

                         vertex_buffer_data2[9*i+3] = -radius * cos(param * M_PI/180);
                         vertex_buffer_data2[9*i+4] = length/2;
                         vertex_buffer_data2[9*i+5] = -radius * sin(param * M_PI/180);


                        vertex_buffer_data2[9*i+6] = -radius * cos((param+0.5) * M_PI/180);
                        vertex_buffer_data2[9*i+7] = length/2;
                        vertex_buffer_data2[9*i+8] = -radius * sin((param+0.5) * M_PI/180);
                    }
                     if(i%2==1)
                     {
                         vertex_buffer_data2[9*i] = -radius * cos((param+0.5) * M_PI/180);
                         vertex_buffer_data2[9*i+1] = length/2;
                         vertex_buffer_data2[9*i+2] = -radius * sin((param+0.5) * M_PI/180);

                         vertex_buffer_data2[9*i+3] = -radius * cos((param+0.5) * M_PI/180);
                         vertex_buffer_data2[9*i+4] = -length/2;
                         vertex_buffer_data2[9*i+5] = -radius * sin((param+0.5) * M_PI/180);

        //                param += 0.5;
                        vertex_buffer_data2[9*i+6] = -radius * cos(param * M_PI/180);
                        vertex_buffer_data2[9*i+7] = -length/2;
                        vertex_buffer_data2[9*i+8] = -radius * sin(param * M_PI/180);
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
                                 vertex_buffer_data3[9*i+1] = 0.5;
                                 vertex_buffer_data3[9*i+2] = 0.5;

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
                                 vertex_buffer_data3[9*i+4] = 0.5;
                                 vertex_buffer_data3[9*i+5] = 0.5;


                                vertex_buffer_data3[9*i+6] = 0.5;
                                vertex_buffer_data3[9*i+7] = 0.5;
                                vertex_buffer_data3[9*i+8] = 0.5;}


                           }

//                    static const GLfloat color_buffer_data[] = {
//                        0,0,0,
//                        0.5,0,0,
//                        0.5,0,0,

//                        0,0,0,
//                        0.5,0,0,
//                        0.5,0,0,

//                        0,0,0,
//                        0.5,0,0,
//                        0.5,0,0,

//                        0,0,0,
//                        0.5,0,0,
//                        0.5,0,0,

//                        1,1,-2,
//                        0.5,0,0,
//                        0.5,0,0,

//                        1,1,-2,
//                        0.5,0,0,
//                        0.5,0,0


//                    };
//            this->base = create3DObject(GL_TRIANGLES,)
            this->cannon1 = create3DObject(GL_TRIANGLES, 240*9, vertex_buffer_data, vertex_buffer_data3, GL_FILL);
                    this->cannon2 = create3DObject(GL_TRIANGLES, 240*9, vertex_buffer_data2, vertex_buffer_data3, GL_FILL);

}

void Cannon::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate1 = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
//     glm::mat4 rotate2    = glm::rotate((float) (this->rotation3 * M_PI / 180.0f), glm::vec3(sin(this->rotation*M_PI/180.0), cos(this->rotation1*M_PI/180.0), 0));
//     glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(0, 0, 1));
//    glm::mat4 translate2 = glm::translate (glm::vec3(this->position.x-this->X,this->position.y-this->Y,0));
//    glm::mat4 rotate2    = glm::rotate((float) (this->rotation2 * M_PI / 180.0f), glm::vec3(0, 0, 1));
//    glm::mat4 translate3 = glm::translate (glm::vec3(-(this->position.x-this->X),-(this->position.y-this->Y),0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
//    glm::mat4 translate2 = glm::translate (-this->position);
    Matrices.model *= (translate1 *rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->cannon1);
    draw3DObject(this->cannon2);
}
void Cannon::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}

void Cannon::tick() {
//this->rotation += 1;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
