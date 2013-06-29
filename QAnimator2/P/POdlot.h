#ifndef _POdlot_H_
#define _POdlot_H_

class POdlot;

#include "../przejscie.h"

class POdlot : public Przejscie
{
	public:
	POdlot();
	virtual ~POdlot();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
