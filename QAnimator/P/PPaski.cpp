#include "PPaski.h"
#include <cstdlib>

PPaski::PPaski()
{
	Name = "Paski";
}

PPaski::~PPaski()
{

}

uchar* PPaski::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    srand(324);
    for (int i=0; i<W; i++)
    {
        float s = rand()/(RAND_MAX+1.0f);
        s*=0.9;
        for (int j=0; j<H; j++)
        {
            float P = (percent-s)/(1-s);
            if (i>P*W)
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
