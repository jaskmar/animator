#include "PCzern.h"
#include <cstdlib>

PCzern::PCzern()
{
	Name = "Przejście przez czerń";
}

PCzern::~PCzern()
{

}

uchar* PCzern::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    //int L = percent*256;
    
    if(percent<0.5)
    {
        //L = 256*percent*3;
        for (int i=0; i<3*W*H; i+=1) res[i] = (1-percent*2)*Start[i];
    }
    else
    {
        //L = 256*percent*3;
        for (int i=0; i<3*W*H; i+=1) res[i] = (percent-0.5)*2*Stop[i];
    }    
    return res;
}
