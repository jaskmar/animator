#include "POdwrot.h"
#include <cstdlib>

POdwrot::POdwrot()
{
	Name = "Odwrót";
}

POdwrot::~POdwrot()
{

}

uchar* POdwrot::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    float p;
    float P;
    uchar *Ak;
    int x, y, xp, yp, Hp, Wp;
    if(percent<0.5)
    {
        Ak=Start;
        P=percent*2;
    }
    else
    {
        Ak=Stop;
        P=1-(percent-0.5)*2;
    }
    p=cos(P*M_PI*0.5);
    P=sin(P*M_PI*0.5);
    for (int i=0; i<3*W*H; i+=3)
    {
        x=(i/3)%W;
        y=(i/3)/W;
        Hp=H + 0.8*P*H*((percent<0.5)-0.5);
        Wp=W*p;
        Hp=(float(W/2-x)/(Wp/2))*Hp + (1.f - float(W/2-x)/(Wp/2))*H;
        xp=W/2 + (x-W/2)/p;
        yp=y*float(H)/Hp + (H - H*float(H)/Hp)/2;
        
        if (xp>=0 && xp<W && yp>=0 && yp<H)
        {
            res[i] = Ak[3*(xp+yp*W)];
            res[i+1] = Ak[3*(xp+yp*W)+1];
            res[i+2] = Ak[3*(xp+yp*W)+2];
        }
        else
        {
            res[i] = 0;
            res[i+1] = 0;
            res[i+2] = 0;
        }
    }
    return res;
}
