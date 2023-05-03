#include "RBlast.c"
#include "RBlastConv.c"

//4k color noise!
#define resx 3840
#define resy 2140
#define max resx * resy

int main(void)
{
    RB_RENDER rnd;
    RB_NEW_RENDER(&rnd,resx,resy);

    RB_COLOR clr;

    int counter = 0,cout2 = 0;
    for (int y = 0; y < rnd.RESOLUTION_Y; y++)
    {
        for (int x = 0; x < rnd.RESOLUTION_X; x++)
        {
            clr[0] = rand() % 255;
            clr[1] = rand() % 255;
            clr[2] = rand() % 255;
            RB_RENDER_SET_PIXEL(&rnd,x,y,clr);
            counter++;
            if(counter > 550)
            {
                printf("progres -> %i / %i\n",cout2,max);
                cout2 += counter;
                counter = 0;
            }
        }
    }
    
    printf("saveing to ppm...");
    
    RBC_RENDER2PPM(&rnd,"yes1.ppm");

    printf("done!\n");
    getchar();getchar();

    return 0;
}
