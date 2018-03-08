#include "main.h"

#ifndef CANNON_H
#define CANNON_H


class Cannon
{
public:
    Cannon() {}
    Cannon(float x,float y,float z, float radius,float length,float back);
    float rotation,rotation2,rotation3;
    float rotation1;
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    float X,Y;
    double speed;
private:
    VAO *cannon1;
    VAO *cannon2;
};

#endif // CANNON_H
