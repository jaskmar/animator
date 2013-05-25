#ifndef _PHsv_H_
#define _PHsv_H_

class PHsv;

#include "../przejscie.h"

class PHsv : public Przejscie
{
	public:
	PHsv();
	virtual ~PHsv();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
