#include "main.h"
#ifndef FLAG_H
#define FLAG_H


class Flag
{
public:
    Flag() {}
    Flag(float x, float y,float z,float length,float width,float radius,int flag,float rotation1);
    float rotation;
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    int flag;
private:
    VAO *straight;
    VAO *left;
    VAO *right;
};

#endif // FLAG_H
