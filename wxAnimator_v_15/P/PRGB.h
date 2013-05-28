#ifndef _PRGB_H_
#define _PRGB_H_

class PRGB;

#include "../przejscie.h"

class PRGB : public Przejscie
{
	public:
	PRGB();
	virtual ~PRGB();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
