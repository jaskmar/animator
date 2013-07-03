#ifndef _POdkrywanie_up_H_
#define _POdkrywanie_up_H_

class POdkrywanie_up;

#include "../przejscie.h"

class POdkrywanie_up : public Przejscie
{
	public:
	POdkrywanie_up();
	virtual ~POdkrywanie_up();
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop);
};

#endif // PRZEJSCIE_H
