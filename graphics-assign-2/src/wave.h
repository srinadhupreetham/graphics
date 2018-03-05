#include "main.h"
#ifndef WAVE_H
#define WAVE_H


class Wave
{
public:
    Wave() {}
    Wave(float x,float y,float z, float radius,float length,float back);
    float rotation;
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    void tickdown();
    void tickup();
    double speed;
    double speedz;
private:
    VAO *object;
};

#endif // WAVE_H
