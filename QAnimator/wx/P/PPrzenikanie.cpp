// Class automatically generated by Dev-C++ New Class wizard

#include "PPrzenikanie.h" // class's header file
#include <cstdlib>

// class constructor
PPrzenikanie::PPrzenikanie()
{
	Name = "Przenikanie";
}

// class destructor
PPrzenikanie::~PPrzenikanie()
{
	// insert your code here
}

uchar* PPrzenikanie::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    int L = percent*256;
    for (int i=0; i<3*W*H; i++) res[i] = (L*Stop[i]>>8) + ((256-L)*Start[i]>>8);
    return res;
}
