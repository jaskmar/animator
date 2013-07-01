#ifndef _PBlur_H_
#define _PBlur_H_

class PBlur;

#include "../przejscie.h"

class PBlur : public Przejscie
{
	public:
	PBlur();
	virtual ~PBlur();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
