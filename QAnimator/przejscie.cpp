#include "przejscie.h"
#include <QMessageBox>

Przejscie::Przejscie()
{

}

Przejscie::~Przejscie()
{

}

string Przejscie::getName()
{
    return Name;
}

void Przejscie::generate(Controller *C, QProgressBar *ProgressBar)
{
    int w = C->Img1.width() > C->Img2.width() ? C->Img1.width() : C->Img2.width();
    int h = C->Img1.height() > C->Img2.height() ? C->Img1.height() : C->Img2.height();
    uchar *Start=new uchar[w*h*3];
    uchar *Stop=new uchar[w*h*3];
    Img2UcharTab(C->Img1.scaled(w,h), Start);
    Img2UcharTab(C->Img2.scaled(w,h), Stop);

    for (int i=0; i<C->Frames; i++)
    {
        float percent = C->easing( (float)i/(C->Frames-1) );
        uchar *res =generateFrame(percent, w, h, Start, Stop);

        ProgressBar->setValue(100*i/(C->Frames-1));
        //ProgressBar->parentWidget()->repaint();

        QImage *Tmp = new QImage(w,h,QImage::Format_RGB888);
        UcharTab2Img(res, *Tmp);
        free(res);
        C->Output.push_back(Tmp);
    }

    delete[] Start;
    delete[] Stop;
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
        //QRgb* Data = (QRgb*) Img.scanLine(i);
        for (int j=0; j<w; j++)
        {
            Img.setPixel(j,i,((uint)In[ind]<<16) | ((uint)In[ind+1]<<8) | ((uint)In[ind+2]));
            ind+=3;
        }
    }
}
