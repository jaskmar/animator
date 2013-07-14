#include "PPrzepychanie_right.h"
#include <cstdlib>

PPrzepychanie_right::PPrzepychanie_right()
{
	Name = "Przepychanie z prawej";
}

PPrzepychanie_right::~PPrzepychanie_right()
{

}

uchar* PPrzepychanie_right::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar *tmp;
    tmp=Start;
    Start=Stop;
    Stop=tmp;
    
    uchar* res = (uchar*) malloc(3*W*H);
    int L=(1.0-percent)*W;
    for (int i=0; i<L; i++)
    {
        for (int j=0; j<H; j++)
        {
            res[j*3*W+3*i+0] =Stop[j*3*W+3*(i+W-L)+0];
            res[j*3*W+3*i+1] =Stop[j*3*W+3*(i+W-L)+1];
            res[j*3*W+3*i+2] =Stop[j*3*W+3*(i+W-L)+2]; 
        }
    }
    
    for (int i=L; i<W; i++)
    {
        for (int j=0; j<H; j++)
        {
            res[j*3*W+3*i+0] =Start[j*3*W+3*(i-L)+0];           
            res[j*3*W+3*i+1] =Start[j*3*W+3*(i-L)+1];
            res[j*3*W+3*i+2] =Start[j*3*W+3*(i-L)+2]; 
        }
    }
    
    return res;
}
