
#include "main.h"
#ifndef ISLAND_H
#define ISLAND_H


class Island
{
public:
    Island() {}
    Island(float x, float y, float z, float length, float breadth, float height, color_t color);
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

#endif // ISLAND_H
