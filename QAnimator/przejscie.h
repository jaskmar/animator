#ifndef PRZEJSCIE_H
#define PRZEJSCIE_H

class Przejscie;

#include "controller.h"
#include <string>
#include <cmath>
#include <QImage>
#include <QProgressBar>
using namespace std;
typedef unsigned char uchar;

class Przejscie
{
	public:
	Przejscie();
	virtual ~Przejscie();
	string getName();
    void generate(Controller *C, QProgressBar *ProgressBar);
	
	protected:
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)=0;
    void Img2UcharTab(const QImage &Img, uchar* Out);   //funkcja adaptacyjna
    void UcharTab2Img(const uchar* const In, QImage &Img);   //funkcja adaptacyjna
	
	string Name;
};

#endif // PRZEJSCIE_H
