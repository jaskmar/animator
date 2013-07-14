#include "PPrzylot.h"
#include <cstdlib>

PPrzylot::PPrzylot()
{
	Name = "Przylot";
}

PPrzylot::~PPrzylot()
{

}

uchar* PPrzylot::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    float p = percent;
    float P = 1-p;
    int x, y, xp, yp, Hp, Wp, dH, xk;
    for (int i=0; i<3*W*H; i+=3)
    {
        x=(i/3)%W;
        y=(i/3)/W;
        xk=W*p;
        dH=0.4*P*H;
        Wp=W*p;
        Hp=(float(xk-x)/(Wp/2))*(H+dH) + (1.f - float(xk-x)/(Wp/2))*H;
        xp=xk + (x-xk)/p;
        yp=y*float(H)/Hp + (H - H*float(H)/Hp)/2;
        if (xp>=0 && xp<W && yp>=0 && yp<H)
        {
            res[i] = Stop[3*(xp+yp*W)];
            res[i+1] = Stop[3*(xp+yp*W)+1];
            res[i+2] = Stop[3*(xp+yp*W)+2];
        }
        else
        {
            res[i] = Start[3*(x+y*W)];
            res[i+1] = Start[3*(x+y*W)+1];
            res[i+2] = Start[3*(x+y*W)+2];
        }
    }
    return res;
}
