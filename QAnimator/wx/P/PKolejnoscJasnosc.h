#ifndef _PKolejnoscJasnosc_H_
#define _PKolejnoscJasnosc_H_

class PKolejnoscJasnosc;

#include "../przejscie.h"

class PKolejnoscJasnosc : public Przejscie
{
	public:
	PKolejnoscJasnosc();
	virtual ~PKolejnoscJasnosc();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
