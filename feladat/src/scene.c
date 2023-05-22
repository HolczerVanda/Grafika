
#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float waterPoints[45][45][3];
int wiggleCount = 0;
float hold;

void init_scene(Scene *scene)
{

    glEnable(GL_FOG);
    glFogf(GL_FOG_DENSITY, 0.07f);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    load_model(&(scene->ground), "assets/models/ground.obj");
    scene->ground_texture = load_texture("assets/textures/ground_texture.jpg");
    scene->help_texture_id = load_texture("assets/textures/help_texture.jpg");

    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 10.0;

    scene->light = 1.0f;

    scene->showHelp = 1;

    scene->start=clock();
    
    init_environment(&(scene->environment));
    init_diamond(&(scene->diamond));

    scene->diamond.score = 0;
    scene->show_win=false;


}

void set_lighting(float x)
{
    float ambient_light[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float diffuse_light[] = {x, x, x, 1.0f};
    float specular_light[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float position[] = {0.0f, 0.0f, 10.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material *material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue};

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue};

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene *scene)
{
    set_lighting(scene->light);
    if(scene->diamond.score >9){
        scene->show_win=true;
    }
}

void place_diamond(Scene *scene)
{
    srand(rand());
    float random_x= (float)rand()/(float)(RAND_MAX/14)-7;
    float random_y= (float)rand()/(float)(RAND_MAX/14)-7;
    scene->diamond.diamond_x = random_x;
    scene->diamond.diamond_y= random_y;
    //scene->diamond.diamond_x = 0;
    //scene->diamond.diamond_y=-14;
}

void render_scene(const Scene *scene)
{
    
    // ground
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glBindTexture(GL_TEXTURE_2D, scene->ground_texture);
    glRotated(90, 1, 0, 0);
    draw_model(&(scene->ground));
    glPopMatrix();

    // diamond
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->diamond.diamond_texture);
    glTranslatef(scene->diamond.diamond_x, scene->diamond.diamond_y, scene->diamond.rotation_z);
    glRotated(90, 1, 0, 0);
    glRotatef(scene->diamond.rotation_x,0,1,0);
    draw_model(&(scene->diamond.diamond));  
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glBindTexture(GL_TEXTURE_2D, scene->environment.tree_texture);
    glRotated(90, 1, 0, 0);
    draw_model(&(scene->environment.Tree));
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glBindTexture(GL_TEXTURE_2D, scene->environment.stone_texture);
    glRotated(90, 1, 0, 0);
    draw_model(&(scene->environment.Stone));
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glBindTexture(GL_TEXTURE_2D, scene->environment.bush_texture);
    glRotated(90, 1, 0, 0);
    draw_model(&(scene->environment.Bush));
    glPopMatrix();

    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glBindTexture(GL_TEXTURE_2D, scene->environment.hill_texture);
    glRotated(90, 1, 0, 0);
    draw_model(&(scene->environment.Hill));
    glPopMatrix();

    points(&(scene->diamond));
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void help(GLuint texture)
{
    glDisable(GL_FOG);
    glDisable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3d(-2, 1.5, -3);
    glTexCoord2f(1, 0);
    glVertex3d(2, 1.5, -3);
    glTexCoord2f(1, 1);
    glVertex3d(2, -1.5, -3);
    glTexCoord2f(0, 1);
    glVertex3d(-2, -1.5, -3);
    glEnd();

    glEnable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_FOG);
}

