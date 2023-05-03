#include <stdio.h>
#include <stdlib.h>
#define RBLAST

typedef struct RB_RENDER
{
    size_t RESOLUTION_X;
    size_t RESOLUTION_Y;
    int ***PIXEL;
} RB_RENDER;

typedef int RB_COLOR[3];



void RB_NEW_RENDER(RB_RENDER *RENDER,size_t RESOLUTION_X,size_t RESOLUTION_Y)
{
    RENDER->RESOLUTION_X = RESOLUTION_X;
    RENDER->RESOLUTION_Y = RESOLUTION_Y;

    RENDER->PIXEL = malloc(sizeof(int) * RESOLUTION_Y);
    for (size_t y = 0; y < RESOLUTION_Y; y++)
    {
        RENDER->PIXEL[y] = malloc(sizeof(int) * RESOLUTION_X);
        for (size_t x = 0; x < RESOLUTION_X; x++)
        {
            RENDER->PIXEL[y][x] = malloc(sizeof(int) * 3);
        }  
    }
}

void RB_REALLOC_RENDER(RB_RENDER *RENDER,size_t RESOLUTION_X,size_t RESOLUTION_Y)
{
    RENDER->RESOLUTION_X = RESOLUTION_X;
    RENDER->RESOLUTION_Y = RESOLUTION_Y;

    RENDER->PIXEL =  realloc(RENDER->PIXEL,sizeof(int) * RESOLUTION_Y);
    for (size_t y = 0; y < RESOLUTION_Y; y++)
    {
        RENDER->PIXEL[y] = realloc(RENDER->PIXEL[y],sizeof(int) * RESOLUTION_X);
        for (size_t x = 0; x < RESOLUTION_X; x++)
        {
            RENDER->PIXEL[y][x] = realloc(RENDER->PIXEL[y][x],sizeof(int) * 3);
        }  
    }
}


void RB_RENDER_SET_ALL_PIXEL(RB_RENDER *RENDER,RB_COLOR COLOR)
{
    for (size_t y = 0; y < RENDER->RESOLUTION_Y; y++)
    {
        for (size_t x = 0; x < RENDER->RESOLUTION_X; x++)
        {
            RENDER->PIXEL[y][x][0] = COLOR[0];
            RENDER->PIXEL[y][x][1] = COLOR[1];
            RENDER->PIXEL[y][x][2] = COLOR[2];
        }
    }
}


void RB_RENDER_SET_PIXEL(RB_RENDER *RENDER,int X,int Y, RB_COLOR COLOR)
{
    RENDER->PIXEL[Y][X][0] = COLOR[0];
    RENDER->PIXEL[Y][X][1] = COLOR[1];
    RENDER->PIXEL[Y][X][2] = COLOR[2];
}