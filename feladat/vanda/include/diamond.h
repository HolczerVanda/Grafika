#ifndef DIAMOND_H
#define DIAMOND_H

#include "camera.h"
#include "texture.h"
#include <math.h>
#include <obj/model.h>

typedef struct Diamond
{
    Model diamond;
    GLuint diamond_texture;

    float diamond_x;
    float diamond_y;
    float rotation_x;
    float rotation_z;
    int score;
    bool is_max;
    bool is_min;

} Diamond;

void init_diamond(Diamond *diamond);

#endif