#include "monster.h"
#include "main.h"

Monster::Monster(float x, float y,float z, color_t color)
{

    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    float radius = 0.35;
    spe = 0.015;
    float w = 1.0,l=1.0,hn=+0.6,hf=-0.6;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data_cone[] = {
        0,0,hn+2.0,
        w,l,hn,
        -w,l,hn,

        0,0,hn+2.0,
        -w,-l,hn,
        -w,l,hn,

        0,0,hn+2.0,
        w,l,hn,
        w,-l,hn,

        0,0,hn+2.0,
        w,-l,hn,
        -w,-l,hn,

    };
    GLfloat vertex_buffer_data[720*3*3];
           int i=0;
           float param = 0.0;
           for(i=0;i<720;i++)
           {
            vertex_buffer_data[9*i] = 0.4f;
            vertex_buffer_data[9*i+1] = w;
            vertex_buffer_data[9*i+2] = 0.2f;

            vertex_buffer_data[9*i+3] = 0.4+radius * cos(param * M_PI/180);
            vertex_buffer_data[9*i+4] = w;
            vertex_buffer_data[9*i+5] = 0.2+radius * sin(param * M_PI/180);

            param += 0.5;
            vertex_buffer_data[9*i+6] = 0.4+radius * cos(param * M_PI/180);
            vertex_buffer_data[9*i+7] = w;
            vertex_buffer_data[9*i+8] = 0.2+radius * sin(param * M_PI/180);
           }
           GLfloat vertex_buffer_dataright[720*3*3];
                  i=0;
                  param = 0.0;
                  for(i=0;i<720;i++)
                  {
                   vertex_buffer_dataright[9*i] = -0.4f;
                   vertex_buffer_dataright[9*i+1] = w;
                   vertex_buffer_dataright[9*i+2] = 0.0f;

                   vertex_buffer_dataright[9*i+3] = -0.4+radius * cos(param * M_PI/180);
                   vertex_buffer_dataright[9*i+4] = w;
                   vertex_buffer_dataright[9*i+5] = radius * sin(param * M_PI/180);

                   param += 0.5;
                   vertex_buffer_dataright[9*i+6] = -0.4+radius * cos(param * M_PI/180);
                   vertex_buffer_dataright[9*i+7] = w;
                   vertex_buffer_dataright[9*i+8] = radius * sin(param * M_PI/180);
                  }
                  GLfloat vertex_buffer_datac[720*3*3];
                         i=0;
                         param = 0.0;
                         for(i=0;i<720;i++)
                         {
                          vertex_buffer_datac[9*i] = -0.4f;
                          vertex_buffer_datac[9*i+1] = w;
                          vertex_buffer_datac[9*i+2] = 0.0f;

                          vertex_buffer_datac[9*i+3] = -0.4+radius * cos(param * M_PI/180);
                          vertex_buffer_datac[9*i+4] = w;
                          vertex_buffer_datac[9*i+5] = radius * sin(param * M_PI/180);

                          param += 0.5;
                          vertex_buffer_datac[9*i+6] = -0.4+radius * cos(param * M_PI/180);
                          vertex_buffer_datac[9*i+7] = w;
                          vertex_buffer_datac[9*i+8] = radius * sin(param * M_PI/180);
                         }
    static const GLfloat vertex_buffer_datam[] = {
        w,l,-hn,
        -w,l,-hn,
        w,-l,-hn,

        -w,l,-hn,
        w,-l,-hn,
        -w,-l,-hn,
        //base top
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
    };
    hf /= 2;
    hn /= 2;
    static const GLfloat vertex_buffer_datar[] = {
        w+2*w,l,-hn-1,
        -w+2*w,l,-hn-1,
        w+2*w,-l,-hn-1,

        -w+2*w,l,-hn-1,
        w+2*w,-l,-hn-1,
        -w+2*w,-l,-hn-1,
        //base top
        w+2*w,l,-hf-1,
        -w+2*w,l,-hf-1,
        w+2*w,-l,-hf-1,

        -w+2*w,l,-hf-1,
        w+2*w,-l,-hf-1,
        -w+2*w,-l,-hf-1,
        //end of bottom face
        w+2*w,l,-hf-1,
        -w+2*w,l,-hf-1,
        w+2*w,l,-hn-1,

        -w+2*w,l,-hn-1,
        -w+2*w,l,-hf-1,
        w+2*w,l,-hn-1,
        //end of back face
        w+2*w,-l,-hf-1,
        -w+2*w,-l,-hf-1,
        w+2*w,-l,-hn-1,

        -w+2*w,-l,-hn-1,
        -w+2*w,-l,-hf-1,
        w+2*w,-l,-hn-1,
        //end of front face
        w+2*w,l,-hf-1,
        w+2*w,-l,-hf-1,
        w+2*w,l,-hn-1,

        w+2*w,-l,-hn-1,
        w+2*w,-l,-hf-1,
        w+2*w,l,-hn-1,
        //end of right face
        -w+2*w,l,-hf-1,
        -w+2*w,-l,-hf-1,
        -w+2*w,l,-hn-1,

        -w+2*w,-l,-hn-1,
        -w+2*w,-l,-hf-1,
        -w+2*w,l,-hn-1
    };
    static const GLfloat vertex_buffer_datal[] = {
        w-2*w,l,-hn-1,
        -w-2*w,l,-hn-1,
        w-2*w,-l,-hn-1,

        -w-2*w,l,-hn-1,
        w-2*w,-l,-hn-1,
        -w-2*w,-l,-hn-1,
        //base top
        w-2*w,l,-hf-1,
        -w-2*w,l,-hf-1,
        w-2*w,-l,-hf-1,

        -w-2*w,l,-hf-1,
        w-2*w,-l,-hf-1,
        -w-2*w,-l,-hf-1,
        //end of bottom face
        w-2*w,l,-hf-1,
        -w-2*w,l,-hf-1,
        w-2*w,l,-hn-1,

        -w-2*w,l,-hn-1,
        -w-2*w,l,-hf-1,
        w-2*w,l,-hn-1,
        //end of back face
        w-2*w,-l,-hf-1,
        -w-2*w,-l,-hf-1,
        w-2*w,-l,-hn-1,

        -w-2*w,-l,-hn-1,
        -w-2*w,-l,-hf-1,
        w-2*w,-l,-hn-1,
        //end of front face
        w-2*w,l,-hf-1,
        w-2*w,-l,-hf-1,
        w-2*w,l,-hn-1,

        w-2*w,-l,-hn-1,
        w-2*w,-l,-hf-1,
        w-2*w,l,-hn-1,
        //end of right face
        -w-2*w,l,-hf-1,
        -w-2*w,-l,-hf-1,
        -w-2*w,l,-hn-1,

        -w-2*w,-l,-hn-1,
        -w-2*w,-l,-hf-1,
        -w-2*w,l,-hn-1
    };
    radius = 0.75;
    this->radius = radius;
    float length = -6;
    this->length = 6;
    GLfloat vertex_buffer_data_1[720*3*3];
            i=0;
            param = 90.0;
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
    GLfloat color_buffer_data[] ={};
    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_datam, color_buffer_data, GL_FILL);
    this->object0 = create3DObject(GL_TRIANGLES, 720*3, vertex_buffer_data, COLOR_WHITE, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 720*3, vertex_buffer_dataright, COLOR_DOM, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 720*3, vertex_buffer_datac, COLOR_WHITE, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_datar, COLOR_GREEN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_datal, COLOR_GREEN, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data_cone, COLOR_DOM, GL_FILL);
    this->barrel1 = create3DObject(GL_TRIANGLES, 240*9, vertex_buffer_data_1, color_buffer_data, GL_FILL);
            this->barrel2 = create3DObject(GL_TRIANGLES, 240*9, vertex_buffer_data_2,color_buffer_data, GL_FILL);
}

void Monster::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object0);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
    draw3DObject(this->barrel1);
    draw3DObject(this->barrel2);
}

void Monster::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
//    this->rotation += 1;
}

void Monster::tick() {
this->rotation += 1;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
bounding_box_t Monster::bounding_box() {
    float x = this->position.x, y = this->position.y;
    float z = this->position.z + (this->length/2);
    float len = this->radius;
    float wid = this->radius;
    float high = this->length+4;
//    float s = this->speedy;
    bounding_box_t bbox = { x, y,z,len,wid,high};
    return bbox;
}
