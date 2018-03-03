#include "main.h"
#ifndef WATER_H
#define WATER_H


class Water
{
public:
    Water() {}
    Water(float x, float y, float z, float length, float breadth, float height, color_t color);
    float water_dist_from_origin;
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
private:
    VAO *object;

};

#endif // WATER_H
