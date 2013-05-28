#ifndef _PNajazd_up_H_
#define _PNajazd_up_H_

class PNajazd_up;

#include "../przejscie.h"

class PNajazd_up : public Przejscie
{
	public:
	PNajazd_up();
	virtual ~PNajazd_up();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
