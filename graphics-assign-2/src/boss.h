#include "main.h"
#ifndef BOSS_H
#define BOSS_H


class Boss
{
public:
    Boss() {}
    Boss(float x, float y,float z, color_t color);
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
    VAO * object1;
    VAO * object2;
    VAO *barrel1;
    VAO *barrel2;
};

#endif // BOSS_H
