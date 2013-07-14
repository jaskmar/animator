#include "PPrzenikanie.h"
#include <cstdlib>

PPrzenikanie::PPrzenikanie()
{
	Name = "Przenikanie";
}

PPrzenikanie::~PPrzenikanie()
{

}

uchar* PPrzenikanie::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    int L = percent*256;
    for (int i=0; i<3*W*H; i++) res[i] = (L*Stop[i]>>8) + ((256-L)*Start[i]>>8);
    return res;
}
