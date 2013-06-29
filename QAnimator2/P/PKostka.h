#ifndef _PKostka_H_
#define _PKostka_H_

class PKostka;

#include "../przejscie.h"

class PKostka : public Przejscie
{
	public:
	PKostka();
	virtual ~PKostka();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
