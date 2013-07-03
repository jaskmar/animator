#ifndef _PPaski_H_
#define _PPaski_H_

class PPaski;

#include "../przejscie.h"

class PPaski : public Przejscie
{
	public:
	PPaski();
	virtual ~PPaski();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
