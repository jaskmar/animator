#ifndef _PPrzepychanie_right_H_
#define _PPrzepychanie_right_H_

class PPrzepychanie_right;

#include "../przejscie.h"

class PPrzepychanie_right : public Przejscie
{
	public:
	PPrzepychanie_right();
	virtual ~PPrzepychanie_right();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
