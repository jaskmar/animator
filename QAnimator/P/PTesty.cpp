#include "PTesty.h"
#include <cstdlib>

PTesty::PTesty()
{
	Name = "Ring";
}

PTesty::~PTesty()
{

}

uchar* PTesty::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    float p = percent;
    float P = 1-p;
    //float sp = sin(p*M_PI);
    //float spp= sin(M_PI*p*0.5);
    //float sP = sin(M_PI*P);
    //float sPp= sin(M_PI*P*0.5);
    float a = percent*M_PI;
    float sina1 = sin(a);
    float cosa1 = cos(a);
    float cosa1P3 = cos(a+0.15);
    float cosa1M3 = cos(a-0.15);
    float sina2 = -sina1;
    float cosa2 = cos(a+M_PI);
    float cosa2P3 = cos(a+M_PI+0.15);
    float cosa2M3 = cos(a+M_PI-0.15);
    int x, y;
    int xp1, yp1, Hp1, Wp1, Ha1, Hb1, dx1, dy1;
    int xp2, yp2, Hp2, Wp2, Ha2, Hb2, dx2, dy2;
    const float g = 0.9;
    for (int i=0; i<3*W*H; i+=3)
    {
        x=(i/3)%W;
        y=(i/3)/W;

        Wp1=W*cosa1*(1-g*p);
        Ha1=H - g*0.5*(H-H*cosa1P3);
        Hb1=H - g*0.5*(H-H*cosa1M3);
        if (p<0.5) dx1 = -Wp1*0.1*sina1;
        else dx1 = (Wp1-W)*0.5*cosa1 -Wp1*0.1*sina1;
        xp1 = (x-dx1)*float(W)/Wp1;
        Hp1 = Ha1 + (Hb1-Ha1)*float(x-dx1)/Wp1;
        dy1 = (H-Hp1)/4;
        yp1 = (y-dy1)*float(H)/Hp1;
        
        Wp2=W*cosa2*(1-g*P);
        Ha2=H - g*0.5*(H-H*cosa2P3);
        Hb2=H - g*0.5*(H-H*cosa2M3);
        if (P<0.5) dx2 = W-Wp2 -Wp2*0.1*sina2;
        else dx2 = (W-Wp2)*0.5*(1+sina1) -Wp2*0.1*sina2;
        xp2 = (x-dx2)*float(W)/Wp2;
        Hp2 = Ha2 + (Hb2-Ha2)*float(x-dx2)/Wp2;
        dy2 = (H-Hp2)/4;
        yp2 = (y-dy2)*float(H)/Hp2;
        
        bool narysowane = false;
        if (xp1>=0 && xp1<W && yp1>=0 && yp1<H)
        {
            res[i] = Start[3*(xp1+yp1*W)];
            res[i+1] = Start[3*(xp1+yp1*W)+1];
            res[i+2] = Start[3*(xp1+yp1*W)+2];
            narysowane = true;
        }
        if (xp2>=0 && xp2<W && yp2>=0 && yp2<H && !(p<0.5 && xp1>=0 && xp1<W && yp1>=0 && yp1<H))
        {
            res[i] = Stop[3*(xp2+yp2*W)];
            res[i+1] = Stop[3*(xp2+yp2*W)+1];
            res[i+2] = Stop[3*(xp2+yp2*W)+2];
            narysowane = true;
        }
        if (!narysowane)
        {
            res[i] = 0;
            res[i+1] = 0;
            res[i+2] = 0;
        }

    }
    return res;
}
