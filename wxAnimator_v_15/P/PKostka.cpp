// Class automatically generated by Dev-C++ New Class wizard

#include "PKostka.h" // class's header file
#include <cstdlib>

// class constructor
PKostka::PKostka()
{
	Name = "Kostka";
}

// class destructor
PKostka::~PKostka()
{
	// insert your code here
}

uchar* PKostka::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    float p = percent;
    float P = 1-p;
    float sp = sin(p*M_PI);
    float spp= sin(M_PI*p*0.5);
    float sP = sin(M_PI*P);
    float sPp= sin(M_PI*P*0.5);
    int x, y;
    int xp1, yp1, Hp1, Wp1, Ha1, Hb1, dx1, dy1;
    int xp2, yp2, Hp2, Wp2, Ha2, Hb2, dx2, dy2;
    for (int i=0; i<3*W*H; i+=3)
    {
        x=(i/3)%W;
        y=(i/3)/W;

        Wp1=W*p + W*0.2*sp;
        Ha1 = H - 0.5*H*sPp;
        Hb1 = H + 0.2*H*sp;
        dx1 = - W*0.2*sp;
        xp1 = (x-dx1)*float(W)/Wp1;
        Hp1 = Ha1 + (Hb1-Ha1)*float(x-dx1)/Wp1;
        dy1 = (H-Hp1)/2;
        yp1 = (y-dy1)*float(H)/Hp1;
        
        Wp2=W*P + W*0.2*sp;
        Ha2 = Hb1;
        Hb2 = H - 0.5*H*spp;
        dx2 = W-Wp2 + W*0.2*sp;
        xp2 = (x-dx2)*float(W)/Wp2;
        Hp2 = Ha2 + (Hb2-Ha2)*float(x-dx2)/Wp2;
        dy2 = (H-Hp2)/2;
        yp2 = (y-dy2)*float(H)/Hp2;
        
        if (xp1>=0 && xp1<W && yp1>=0 && yp1<H)
        {
            res[i] = Stop[3*(xp1+yp1*W)];
            res[i+1] = Stop[3*(xp1+yp1*W)+1];
            res[i+2] = Stop[3*(xp1+yp1*W)+2];
        }
        else if (xp2>=0 && xp2<W && yp2>=0 && yp2<H)
        {
            res[i] = Start[3*(xp2+yp2*W)];
            res[i+1] = Start[3*(xp2+yp2*W)+1];
            res[i+2] = Start[3*(xp2+yp2*W)+2];
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