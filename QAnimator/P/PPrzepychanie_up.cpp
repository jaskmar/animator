#include "PPrzepychanie_up.h"
#include <cstdlib>

PPrzepychanie_up::PPrzepychanie_up()
{
	Name = "Przepychanie z góry";
}

PPrzepychanie_up::~PPrzepychanie_up()
{

}

uchar* PPrzepychanie_up::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    int L=percent*H;
    for (int i=0; i<L; i++)
    {
        for (int j=0; j<3*W; j++)
        {
            res[i*3*W+j] = Stop[(H-L+i)*3*W+j];  
        }
    }
    
    for (int i=L; i<H; i++)
    {
        for (int j=0; j<3*W; j++)
        {
            res[i*3*W+j] = Start[(-L+i)*3*W+j];  
        }
    }  

    return res;
}
