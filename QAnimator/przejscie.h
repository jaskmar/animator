#ifndef PRZEJSCIE_H
#define PRZEJSCIE_H

class Przejscie;

#include "controller.h"
#include <string>
#include <cmath>
#include <QImage>
#include <QProgressBar>
#include <QObject>
using namespace std;
typedef unsigned char uchar;

class Przejscie : public QObject
{
    Q_OBJECT
    friend class GenerateThreadWorker;
    class TbbGenerateWorker {
    public:
        TbbGenerateWorker(Przejscie*, Controller *);
        void operator() (int) const;
    private:
        Przejscie *_parent;
        Controller* _c;
    };

	public:
    Przejscie();
	virtual ~Przejscie();
	string getName();
    void generate(Controller *C, QProgressBar *ProgressBar);

    signals:
        void afterStep();
        void generatingFinished();
    protected slots:
        void updateProgress();
	
	protected:
    void step();
	virtual uchar* generateFrame(float percent, int W, int H, uchar *Start, uchar *Stop)=0;
    void Img2UcharTab(const QImage &Img, uchar* Out);   //funkcja adaptacyjna
    void UcharTab2Img(const uchar* const In, QImage &Img);   //funkcja adaptacyjna
    int _w, _h, _steps;
    uchar *_start, *_stop;
	string Name;
    QProgressBar *_progress;
    Controller *_c;
};

#endif // PRZEJSCIE_H
