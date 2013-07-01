#ifndef _POkno_H_
#define _POkno_H_

class POkno;

#include "../przejscie.h"

class POkno : public Przejscie
{
	public:
	POkno();
	virtual ~POkno();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
