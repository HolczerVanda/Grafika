#include "diamond.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void init_diamond(Diamond *diamond)
{
    load_model(&(diamond->diamond), "assets/models/diamondTransparent.obj");
    //diamond->diamond_texture = load_texture("assets/textures/diamond.jpg");

    diamond->diamond_0_texture= load_texture("assets/textures/diamonds_0.jpg");
    diamond->diamond_1_texture= load_texture("assets/textures/diamonds_1.jpg");
    diamond->diamond_2_texture= load_texture("assets/textures/diamonds_2.jpg");
    diamond->diamond_3_texture= load_texture("assets/textures/diamonds_3.jpg");
    diamond->diamond_4_texture= load_texture("assets/textures/diamonds_4.jpg");
    diamond->diamond_5_texture= load_texture("assets/textures/diamonds_5.jpg");
    diamond->diamond_6_texture= load_texture("assets/textures/diamonds_6.jpg");
    diamond->diamond_7_texture= load_texture("assets/textures/diamonds_7.jpg");
    diamond->diamond_8_texture= load_texture("assets/textures/diamonds_8.jpg");
    diamond->diamond_9_texture= load_texture("assets/textures/diamonds_9.jpg");
    diamond->diamond_10_texture= load_texture("assets/textures/diamonds_10.jpg");

    srand(rand());
    float random_x= (float)rand()/(float)(RAND_MAX/7)-3.5;
    float random_y= (float)rand()/(float)(RAND_MAX/7)-3.5;
    //diamond->diamond_x = random_x;
    //diamond->diamond_y= random_y;
    diamond->diamond_x = 0;
    diamond->diamond_y= 0;
    diamond->rotation_x=0.0;
    diamond->rotation_z=0.6;
    diamond->score=0;
    diamond->is_max=false;
    diamond->is_min=true;
}

void points (Diamond *diamond){
    GLuint render_texture;

    switch(diamond->score)
    {
        case 0:
            render_texture=diamond->diamond_0_texture;
            break;
        case 1:
            render_texture=diamond->diamond_1_texture;
            break;
        case 2:
            render_texture=diamond->diamond_2_texture;
            break;
        case 3:
            render_texture=diamond->diamond_3_texture;
            break;
        case 4:
            render_texture=diamond->diamond_4_texture;
            break;
        case 5:
            render_texture=diamond->diamond_5_texture;
            break;
        case 6:
            render_texture=diamond->diamond_6_texture;
            break;
        case 7:
            render_texture=diamond->diamond_7_texture;
            break;
        case 8:
            render_texture=diamond->diamond_8_texture;
            break;
        case 9:
            render_texture=diamond->diamond_9_texture;
            break;
        case 10:
            render_texture=diamond->diamond_10_texture;
            break;
    }

    glDisable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_DEPTH_TEST);
    //glDisable(GL_FOG);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, render_texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3d(1.65, 1.70, -3);
    glTexCoord2f(1, 0);
    glVertex3d(2.33, 1.70, -3);
    glTexCoord2f(1, 1);
    glVertex3d(2.33, 1.13, -3);
    glTexCoord2f(0, 1);
    glVertex3d(1.65, 1.13, -3);
    glEnd();

    glEnable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    //glEnable(GL_FOG);

    glFrustum(
                        -.08, .08,
                        -.06, .06,
                        .1, 6000);
}
