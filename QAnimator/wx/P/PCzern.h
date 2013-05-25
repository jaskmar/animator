#ifndef _PCzern_H_
#define _PCzern_H_

class PCzern;

#include "../przejscie.h"

class PCzern : public Przejscie
{
	public:
	PCzern();
	virtual ~PCzern();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
