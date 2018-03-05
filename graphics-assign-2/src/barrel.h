#include "main.h"
#ifndef BARREL_H
#define BARREL_H


class Barrel
{
public:
    Barrel() {}
    Barrel(float x,float y,float z, float radius,float length,float back);
    float rotation;
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick(),tickup(),tickdown();
    double speed;
private:
    VAO *barrel1;
    VAO *barrel2;
};

#endif // BARREL_H
