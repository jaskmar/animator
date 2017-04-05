#include "przejscie.h"
#include <QMessageBox>
#include <QMutex>
#include <QThread>
#include "generatethreadworker.h"

Przejscie::Przejscie()
{
    connect(this, SIGNAL(afterStep()), this, SLOT(updateProgress()));
}

Przejscie::~Przejscie()
{

}

string Przejscie::getName()
{
    return Name;
}

Przejscie::TbbGenerateWorker::TbbGenerateWorker(Przejscie *parent, Controller *c) {
    _parent = parent;
    _c = c;
}
void Przejscie::TbbGenerateWorker::operator ()(int i) const {
    float percent = _c->easing( (float)i/(_c->Frames-1) );
    uchar *res = _parent->generateFrame(percent, _parent->_w, _parent->_h, _parent->_start, _parent->_stop);

    QImage *Tmp = new QImage(_parent->_w, _parent->_h,QImage::Format_RGB888);
    _parent->UcharTab2Img(res, *Tmp);
    free(res);
    _c->Output.at(i) = Tmp;
    _parent->step();
}

void Przejscie::step() {
    QMutex mutex;
    mutex.lock();
    _steps++;
    mutex.unlock();
    emit afterStep();
}

void Przejscie::updateProgress() {
    _progress->setValue(100*_steps/(_c->Frames-1));
    _progress->parentWidget()->repaint();
}

void Przejscie::generate(Controller *C, QProgressBar *ProgressBar)
{
    _progress = ProgressBar;
    _c = C;
    _w = C->Img1.width() > C->Img2.width() ? C->Img1.width() : C->Img2.width();
    _h = C->Img1.height() > C->Img2.height() ? C->Img1.height() : C->Img2.height();
    _start = new uchar[_w*_h*3];
    _stop = new uchar[_w*_h*3];
    Img2UcharTab(C->Img1.scaled(_w,_h), _start);
    Img2UcharTab(C->Img2.scaled(_w,_h), _stop);
    _steps = 0;
    C->Output.clear();
    C->Output.resize(C->Frames);

    GenerateThreadWorker *threadWorker = new GenerateThreadWorker(this, C, C->Frames);
    QThread *t = new QThread();
    threadWorker->moveToThread(t);
    connect(t, SIGNAL(started()), threadWorker, SLOT(run()));
    connect(threadWorker, SIGNAL(finished()), t, SLOT(quit()));
    connect(threadWorker, SIGNAL(finished()), threadWorker, SLOT(deleteLater()));
    connect(t, SIGNAL(finished()), t, SLOT(deleteLater()));
    t->start();
}
void Przejscie::Img2UcharTab(const QImage &Img, uchar* Out)
{
    int w = Img.width();
    int h = Img.height();
    int ind=0;
    for (int i=0; i<h; i++)
    {
        QRgb* RgbData = (QRgb*) Img.constScanLine(i);
        for (int j=0; j<w; j++)
        {
            Out[ind++] = qRed(RgbData[j]);
            Out[ind++] = qGreen(RgbData[j]);
            Out[ind++] = qBlue(RgbData[j]);
        }
    }
}

void Przejscie::UcharTab2Img(const uchar* const In, QImage &Img)
{
    int w = Img.width();
    int h = Img.height();
    int ind=0;
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            Img.setPixel(j,i,((uint)In[ind]<<16) | ((uint)In[ind+1]<<8) | ((uint)In[ind+2]));
            ind+=3;
        }
    }
}
