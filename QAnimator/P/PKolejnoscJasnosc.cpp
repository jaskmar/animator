#include "PKolejnoscJasnosc.h"
#include <cstdlib>

PKolejnoscJasnosc::PKolejnoscJasnosc()
{
	Name = "Najpierw ciemniejsze";
}

PKolejnoscJasnosc::~PKolejnoscJasnosc()
{

}

uchar* PKolejnoscJasnosc::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    float p;
    for (int i=0; i<3*W*H; i+=3)
    {
        p=(Stop[i]+Stop[i+1]+Stop[i+2])/768.;
        if (p>=percent)
        {
            res[i]=Start[i];
            res[i+1]=Start[i+1];
            res[i+2]=Start[i+2];
        }
        else
        {
            res[i]=Stop[i];
            res[i+1]=Stop[i+1];
            res[i+2]=Stop[i+2];
        }
    }
    return res;
}
