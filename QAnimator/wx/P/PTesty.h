#ifndef _PTesty_H_
#define _PTesty_H_

class PTesty;

#include "../przejscie.h"

class PTesty : public Przejscie
{
	public:
	PTesty();
	virtual ~PTesty();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
