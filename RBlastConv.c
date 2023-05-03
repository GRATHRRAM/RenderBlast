#include <stdio.h>

#ifndef RBLAST
#include "RBlast.c"
#define RBLAST
#endif

int RBC_RENDER2PPM(RB_RENDER *RENDER,char *path)
{
    FILE *ppm = fopen(path,"w");

    if(!ppm) return 1;

    fprintf(ppm,"P3 %zu %zu 255\n",RENDER->RESOLUTION_X,RENDER->RESOLUTION_Y);

    for(size_t y = 0; y < RENDER->RESOLUTION_Y;y++)
    {
        for(size_t x = 0; x < RENDER->RESOLUTION_X;x++)
        {
            fprintf(ppm,"%i %i %i\n",RENDER->PIXEL[y][x][0],RENDER->PIXEL[y][x][1],RENDER->PIXEL[y][x][2]);
        }
    }
    
    fclose(ppm);
}