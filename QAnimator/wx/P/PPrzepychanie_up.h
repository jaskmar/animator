#ifndef _PPRZEPYCHANIE_UP_H_
#define _PPRZEPYCHANIE_UP_H_

class PPrzepychanie_up;

#include "../przejscie.h"

class PPrzepychanie_up : public Przejscie
{
	public:
	PPrzepychanie_up();
	virtual ~PPrzepychanie_up();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
