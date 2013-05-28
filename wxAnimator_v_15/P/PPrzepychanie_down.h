#ifndef _PPrzepychanie_down_H_
#define _PPrzepychanie_down_H_

class PPrzepychanie_down;

#include "../przejscie.h"

class PPrzepychanie_down : public Przejscie
{
	public:
	PPrzepychanie_down();
	virtual ~PPrzepychanie_down();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
