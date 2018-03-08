#include "main.h"

#ifndef BALLBULLET_H
#define BALLBULLET_H


class BallBullet {
public:
    BallBullet() {}
    BallBullet(float x, float y,float z, color_t color);
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

#endif // BALL_H
