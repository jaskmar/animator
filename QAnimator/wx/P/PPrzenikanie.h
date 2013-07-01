#ifndef _PPRZENIKANIE_H_
#define _PPRZENIKANIE_H_

class PPrzenikanie;

#include "../przejscie.h"

class PPrzenikanie : public Przejscie
{
	public:
	PPrzenikanie();
	virtual ~PPrzenikanie();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
