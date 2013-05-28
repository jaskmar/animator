#ifndef _PFarba_H_
#define _PFarba_H_

class PFarba;

#include "../przejscie.h"

class PFarba : public Przejscie
{
	public:
	PFarba();
	virtual ~PFarba();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
