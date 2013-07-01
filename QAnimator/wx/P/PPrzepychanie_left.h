#ifndef _PPrzepychanie_left_H_
#define _PPrzepychanie_left_H_

class PPrzepychanie_left;

#include "../przejscie.h"

class PPrzepychanie_left : public Przejscie
{
	public:
	PPrzepychanie_left();
	virtual ~PPrzepychanie_left();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
