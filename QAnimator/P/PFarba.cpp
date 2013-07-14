#include "PFarba.h"
#include <cstdlib>

PFarba::PFarba()
{
    Name = "Zlewająca się farba";
}

PFarba::~PFarba()
{

}

uchar* PFarba::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    srand(324);
    for (int i=0; i<W; i++)
    {
        float s = rand()/(RAND_MAX+1.0f);
        for (int j=0; j<H; j++)
        {
            float P = percent/(1-s);
            if (j>P*H)
            {
                res[(i+j*W)*3]=Start[(i+j*W)*3];
                res[(i+j*W)*3+1]=Start[(i+j*W)*3+1];
                res[(i+j*W)*3+2]=Start[(i+j*W)*3+2];
            }
            else
            {
                res[(i+j*W)*3]=Stop[(i+j*W)*3];
                res[(i+j*W)*3+1]=Stop[(i+j*W)*3+1];
                res[(i+j*W)*3+2]=Stop[(i+j*W)*3+2];
            }
        }
    }

    return res;
}
