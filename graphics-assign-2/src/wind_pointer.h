#include "main.h"
#ifndef WIND_POINTER_H
#define WIND_POINTER_H


class Wind_pointer
{
public:
    Wind_pointer() {}
    Wind_pointer(float x, float y,float z, color_t color);
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

#endif // WIND_POINTER_H
