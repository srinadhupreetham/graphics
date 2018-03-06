#include "main.h"
#ifndef MONSTER_H
#define MONSTER_H


class Monster
{
public:
    Monster() {}
    Monster(float x, float y,float z, color_t color);
    glm::vec3 position;
    float rotation,spe,length,radius;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick(),tickup(),tickdown();
    double speed;
    float angle;
    int health;
    bounding_box_t bounding_box();
private:
    VAO *object;
    VAO *barrel1;
    VAO *barrel2;
};

#endif // MONSTER_H
