#include "RBlast.c"
#include "RBlastConv.c"
#include "time.h"

//random rect


long *data()
{
    long *Data = (long*) malloc(sizeof(long) * 4);
    printf("RESOLUTION X -> ");
    scanf("%zu",&Data[0]);
    printf("RESOLUTION Y -> ");
    scanf("%zu",&Data[1]);
    printf("Seed (to random type 0) -> ");
    scanf("%zu",&Data[2]);
    printf("Rect Cout -> ");
    scanf("%zu",&Data[3]);
    return (long*) Data;
}


int main(void)
{
    long *dat = (long*) malloc(sizeof(long) * 4);
    dat = data();
    long rect_cout = dat[3];
    long resx = dat[0];
    long resy = dat[1];

    time_t seed;

    if(dat[2] == 0) seed = time(NULL);
    else seed = dat[2];
    srand (seed);
    printf("seed is -> %ld\n",seed);



    RB_RENDER rnd;
    RB_NEW_RENDER(&rnd,resx,resy);


    RB_COLOR clr = {0,0,0};

    RB_RENDER_SET_ALL_PIXEL(&rnd,clr);
    for(size_t cout = 0;cout < rect_cout;cout++)
    {
        size_t curent_X = rand() % resx;
        size_t curent_Y = rand() % resy;
        size_t he = rand() % resy;
        size_t wi = rand() % resx;
        if(he + curent_Y > resy) he = resy - curent_Y;
        if(wi + curent_X > resx) wi = resx - curent_X;

        clr[0] = rand() % 255;
        clr[1] = rand() % 255;
        clr[2] = rand() % 255;

        RB_RENDER_DRAW_RECT(&rnd,curent_X,curent_Y,he,wi,clr);
        printf("Curent Rect gen -> %i\n",cout);
    }

    printf("saveing to ppm...");
    
    RBC_RENDER2PPM(&rnd,"yes1.ppm");

    printf(" done!\n");
    getchar();getchar();

    return 0;
}