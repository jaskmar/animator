// Class automatically generated by Dev-C++ New Class wizard

#include "PBlur.h" // class's header file
#include <cstdlib>

// class constructor
PBlur::PBlur()
{
	Name = "Blur";
}

// class destructor
PBlur::~PBlur()
{
	// insert your code here
}

uchar* PBlur::generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)
{
    uchar* res = (uchar*) malloc(3*W*H);
    wxImage wxi(W,H,Start,true);
    wxImage wxi2 = wxi.Blur(percent*50);
    uchar *StartB = wxi2.GetData();
    
    wxi.Create(W,H,Stop,true);
    wxImage wxi3 = wxi.Blur((1.0f-percent)*50);
    uchar *StopB = wxi3.GetData();
    for (int i=0; i<W*H*3; i++) res[i]=StartB[i]*(1-percent) + StopB[i]*percent;
    return res;
}
