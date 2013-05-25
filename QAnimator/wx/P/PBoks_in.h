#ifndef _PBoks_in_H_
#define _PBoks_in_H_

class PBoks_in;

#include "../przejscie.h"

class PBoks_in : public Przejscie
{
	public:
	PBoks_in();
	virtual ~PBoks_in();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
