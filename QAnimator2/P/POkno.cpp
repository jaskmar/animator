// Class automatically generated by Dev-C++ New Class wizard

#include "POkno.h" // class's header file
#include <cstdlib>

// class constructor
POkno::POkno()
{
	Name = "Otwieranie okna";
}

// class destructor
POkno::~POkno()
{
	// insert your code here
}

uchar* POkno::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    float &p=percent;
    float P=1-p;
    int x, y, xp, yp, Hp, Wp;
    for (int i=0; i<3*W*H; i+=3)
    {
        x=(i/3)%W;
        y=(i/3)/W;
        Wp=W*P;
        Hp=H - H*p*0.6f;
        xp=x*float(W)/Wp;
        Hp=(float(x)/Wp)*Hp + (1.f - float(x)/Wp)*H;
        yp=y*float(H)/Hp + (H - H*float(H)/Hp)/2;
        
        if (xp>=0 && xp<W && yp>=0 && yp<H)
        {
            res[i] = Start[3*(xp+yp*W)];
            res[i+1] = Start[3*(xp+yp*W)+1];
            res[i+2] = Start[3*(xp+yp*W)+2];
        }
        else
        {
            res[i] = Stop[i];
            res[i+1] = Stop[i+1];
            res[i+2] = Stop[i+2];
        }
    }
    return res;
}