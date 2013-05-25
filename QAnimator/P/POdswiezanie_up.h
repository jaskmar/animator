#ifndef _POdswiezanie_up_H_
#define _POdswiezanie_up_H_

class POdswiezanie_up;

#include "../przejscie.h"

class POdswiezanie_up : public Przejscie
{
	public:
	POdswiezanie_up();
	virtual ~POdswiezanie_up();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
