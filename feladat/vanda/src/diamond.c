#include "diamond.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void init_diamond(Diamond *diamond)
{
    load_model(&(diamond->diamond), "assets/models/diamond.obj");
    diamond->diamond_texture = load_texture("assets/textures/coin.jpg");

    srand(rand());
    float random_x= (float)rand()/(float)(RAND_MAX/7)-3.5;
    float random_y= (float)rand()/(float)(RAND_MAX/7)-3.5;
    //diamond->diamond_x = random_x;
    //diamond->diamond_y= random_y;
    diamond->diamond_x = 0;
    diamond->diamond_y= 0;
    diamond->rotation_x=0.0;
    diamond->rotation_z=0.6;
    diamond->is_max=false;
    diamond->is_min=true;
}



