#ifndef SCENE_H
#define SCENE_H

#include "texture.h"
#include <math.h>
#include <obj/model.h>
#include "diamond.h"
#include "timer.h"
#include "environment.h"
#include <time.h>
typedef struct Scene
{
    Material material;
    Diamond diamond;
    Timer timer;
    int difficulty;
    float fog_strength;

    Model ground;
    GLuint ground_texture;
    float light;
    bool show_win;
    bool show_lose;

    Model skybox;
    GLuint skybox_texture;

    GLuint easy_on;
    GLuint medium_on;
    GLuint hard_on;
    GLuint easy_off;
    GLuint medium_off;
    GLuint hard_off;

    Environment environment;

    GLuint help_texture_id;
    
    int showHelp;

} Scene;

/**
 * Place the diamond on a random spot.
 */
void place_diamond(Scene *scene);

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene *scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(float x);

/**
 * Set the current material.
 */
void set_material(const Material *material);

/**
 * Update the scene.
 */
void update_scene(Scene *scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene *scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void help(GLuint texture);

void restart(Scene *scene);

void draw(GLuint texture, float x1,float y1, float x2,float y2);


#endif /* SCENE_H */
