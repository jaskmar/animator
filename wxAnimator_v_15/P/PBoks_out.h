#ifndef _PBoks_out_H_
#define _PBoks_out_H_

class PBoks_out;

#include "../przejscie.h"

class PBoks_out : public Przejscie
{
	public:
	PBoks_out();
	virtual ~PBoks_out();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
