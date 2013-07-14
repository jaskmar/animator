#include "PBoks_out.h"
#include <cstdlib>

PBoks_out::PBoks_out()
{
	Name = "Boks wychodzący";
}

PBoks_out::~PBoks_out()
{

}

uchar* PBoks_out::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    float &P=percent;
    float p=1.0f-P;
    float pp = 1.0f+p;
    int x, y;
    int Pw=W>>1;
    int Ph=H>>1;
    for (int i=0; i<3*W*H; i+=3)
    {
        x=(i/3)%W;
        y=(i/3)/W;
        if (p!=1.0 && ( x<=int(Pw*P) || x>int(Pw*pp) || y<=int(Ph*P) || y>int(Ph*pp) ) )
        {
            res[i] = Stop[i];
            res[i+1] = Stop[i+1];
            res[i+2] = Stop[i+2];
        }
        else
        {
            x=Pw + (x-Pw)/p;
            y=Ph + (y-Ph)/p;
            res[i] = Start[3*(x+y*W)];
            res[i+1] = Start[1+3*(x+y*W)];
            res[i+2] = Start[2+3*(x+y*W)];
        }
    }
    return res;
}
