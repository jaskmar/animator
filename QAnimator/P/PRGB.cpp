#include "PRGB.h"
#include <cstdlib>

PRGB::PRGB()
{
	Name = "Przejście po RGB";
}

PRGB::~PRGB()
{

}

uchar* PRGB::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    int L = percent*256;
    
    if(percent<0.33)
    {
        L = 256*percent*3;
        for (int i=0; i<3*W*H; i+=3) res[i] = (L*Stop[i]>>8) + ((256-L)*Start[i]>>8);
        for (int i=1; i<3*W*H; i+=3) res[i] = Start[i]; 
        for (int i=2; i<3*W*H; i+=3) res[i] = Start[i];    
    }
    else if(percent<0.67 && percent>=0.33)
    {
        L = 256*(percent-0.33)*3;
        for (int i=0; i<3*W*H; i+=3) res[i] = Stop[i]; 
        for (int i=1; i<3*W*H; i+=3) res[i] = (L*Stop[i]>>8) + ((256-L)*Start[i]>>8);
        for (int i=2; i<3*W*H; i+=3) res[i] = Start[i];  
    }
    else
    {
        L = 256*(percent-0.67)*3;
        for (int i=0; i<3*W*H; i+=3) res[i] = Stop[i];  
        for (int i=1; i<3*W*H; i+=3) res[i] = Stop[i];  
        for (int i=2; i<3*W*H; i+=3) res[i] = (L*Stop[i]>>8) + ((256-L)*Start[i]>>8); 
    }
    
    
    return res;
}
