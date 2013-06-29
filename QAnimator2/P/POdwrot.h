#ifndef _POdwrot_H_
#define _POdwrot_H_

class POdwrot;

#include "../przejscie.h"

class POdwrot : public Przejscie
{
	public:
	POdwrot();
	virtual ~POdwrot();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
