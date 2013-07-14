#include "POdkrywanie_up.h"
#include <cstdlib>

POdkrywanie_up::POdkrywanie_up()
{
	Name = "Odkrywanie do góry";
}

POdkrywanie_up::~POdkrywanie_up()
{

}

uchar* POdkrywanie_up::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar *tmp;
    tmp=Start;
    Start=Stop;
    Stop=tmp;
    
    uchar* res = (uchar*) malloc(3*W*H);
    int L=(1-percent)*H;
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
            res[i*3*W+j] = Start[i*3*W+j];  
        }
    }  

    return res;
}
