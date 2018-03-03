#include "main.h"
#ifndef BOAT_H
#define BOAT_H


class Boat
{
public:
    Boat() {}
    Boat(float x,float y, float z,float length,float width,float height,color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
private:
    VAO *base;
    VAO *right;
    VAO *left;
    VAO *basetop;
    VAO *frontdom;
    VAO *backdom;
    VAO *backdomtop;
    VAO *frontdomtop;
};

#endif // BOAT_H
