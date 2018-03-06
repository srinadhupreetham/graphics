#include "main.h"
#ifndef SQUARE_H
#define SQUARE_H


class Square
{
public:
    Square() {}
    Square(float x, float y,float z, float l,color_t color);
    glm::vec3 position;
    float rotation,spe;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick(),tickup(),tickdown();
    double speed;
    float angle;
private:
    VAO *object;
};

#endif // SQUARE_H
