#include "PBoks_in.h"
#include <cstdlib>

PBoks_in::PBoks_in()
{
	Name = "Boks wchodzący";
}

PBoks_in::~PBoks_in()
{
}

uchar* PBoks_in::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    float &p=percent;
    float P=1-p;
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
            res[i] = Start[i];
            res[i+1] = Start[i+1];
            res[i+2] = Start[i+2];
        }
        else
        {
            x=Pw + (x-Pw)/p;
            y=Ph + (y-Ph)/p;
            res[i] = Stop[3*(x+y*W)];
            res[i+1] = Stop[3*(x+y*W)];
            res[i+1] = Stop[1+3*(x+y*W)];
            res[i+2] = Stop[2+3*(x+y*W)];
        }
    }
    return res;
}
