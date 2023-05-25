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
    float position_z;
    int score;
    GLuint diamond_0_texture;
    GLuint diamond_1_texture;
    GLuint diamond_2_texture;
    GLuint diamond_3_texture;
    GLuint diamond_4_texture;
    GLuint diamond_5_texture;
    GLuint diamond_6_texture;
    GLuint diamond_7_texture;
    GLuint diamond_8_texture;
    GLuint diamond_9_texture;
    GLuint diamond_10_texture;

} Diamond;

void init_diamond(Diamond *diamond);

#endif