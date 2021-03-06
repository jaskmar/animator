#include "POdlot.h"
#include <cstdlib>

POdlot::POdlot()
{
    Name = "Odlot";
}

POdlot::~POdlot()
{

}

uchar* POdlot::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
	uchar* res = (uchar*) malloc(3*W*H);
    float P=percent;
    float p=1.0f-P;
    float pp = 1.0f+p;
    int x, y;
    int Pw=W>>1;
    int Ph=H>>1;
    for (int i=0; i<3*W*H; i+=3)
    {
        x=(i/3)%W;
        y=(i/3)/W;
        if(percent<0.5)
        {
            P=percent*2;
            p=1.0f-percent*2;
            pp = 1.0f+p;
            if (p!=1.0 && ( x<=int(Pw*P) || x>int(Pw*pp) || y<=int(Ph*P) || y>int(Ph*pp) ) )
            {
                res[i]=0;
                res[i+1]=0;
                res[i+2]=0;
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
        else
        {
            P=1-(percent-0.5)*2;
            p=(percent-0.5)*2;
            pp = 1.0f+p;
            if (p!=1.0 && ( x<=int(Pw*P) || x>int(Pw*pp) || y<=int(Ph*P) || y>int(Ph*pp) ) )
            {
                res[i]=0;
                res[i+1]=0;
                res[i+2]=0;
            }
            else
            {
                x=Pw + (x-Pw)/p;
                y=Ph + (y-Ph)/p;
                res[i] = Stop[3*(x+y*W)];
                res[i+1] = Stop[1+3*(x+y*W)];
                res[i+2] = Stop[2+3*(x+y*W)];
            }
        }
        
    }
    return res;
}
