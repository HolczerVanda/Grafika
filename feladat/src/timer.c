#include "timer.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void init_timer(Timer *timer)
{
    timer->timer_0_texture= load_texture("assets/textures/clocks_5.jpg");
    timer->timer_1_texture= load_texture("assets/textures/clocks_4.jpg");
    timer->timer_2_texture= load_texture("assets/textures/clocks_3.jpg");
    timer->timer_3_texture= load_texture("assets/textures/clocks_2.jpg");
    timer->timer_4_texture= load_texture("assets/textures/clocks_1.jpg");
    timer->timer_5_texture= load_texture("assets/textures/clocks_0.jpg");

    timer->max_time;
}

void clocks(Timer *timer){
    GLuint render_texture;

    float elapsed_time = (float)(timer->end - timer->start) / CLOCKS_PER_SEC;

    if(elapsed_time < timer->max_time*0.2)
    {
        render_texture=timer->timer_0_texture;
    }
    else if(elapsed_time < timer->max_time*0.4 && elapsed_time > timer->max_time*0.2)
    {
        render_texture=timer->timer_1_texture;
    }
    else if(elapsed_time < timer->max_time*0.6 && elapsed_time > timer->max_time*0.4)
    {
        render_texture=timer->timer_2_texture;
    }
    else if(elapsed_time < timer->max_time*0.8 && elapsed_time > timer->max_time*0.6)
    {
        render_texture=timer->timer_3_texture;
    }
    else if(elapsed_time > timer->max_time*0.8)
    {
        render_texture=timer->timer_4_texture;
    }
    if(elapsed_time > timer->max_time)
    {
        render_texture=timer->timer_5_texture;
    }

    glDisable(GL_LIGHTING);
    //glDisable(GL_FOG);
    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, render_texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3d(-2.33, 1.70, -3);
    glTexCoord2f(1, 0);
    glVertex3d(-1.55, 1.70, -3);
    glTexCoord2f(1, 1);
    glVertex3d(-1.55, 1.43, -3);
    glTexCoord2f(0, 1);
    glVertex3d(-2.33, 1.43, -3);
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