#ifndef _PPrzylot_H_
#define _PPrzylot_H_

class PPrzylot;

#include "../przejscie.h"

class PPrzylot : public Przejscie
{
	public:
	PPrzylot();
	virtual ~PPrzylot();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
