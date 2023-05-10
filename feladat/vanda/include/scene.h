#ifndef SCENE_H
#define SCENE_H

#include "texture.h"
#include <math.h>
#include <obj/model.h>
#include "diamond.h"
#include "environment.h"

typedef struct Scene
{
    Material material;
    Diamond diamond;

    Model ground;
    GLuint ground_texture;
    float light;
    int score;
    bool show_win;

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

#endif /* SCENE_H */
