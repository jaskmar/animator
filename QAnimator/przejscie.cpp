// Class automatically generated by Dev-C++ New Class wizard

#include "przejscie.h" // class's header file
#include <QMessageBox>

// class constructor
Przejscie::Przejscie()
{
	// insert your code here
}

// class destructor
Przejscie::~Przejscie()
{
	// insert your code here
}

string Przejscie::getName()
{
    return Name;
}

void Przejscie::generate(Controller *C)
{
    int w = C->Img1.width();
    int h = C->Img1.height();
    uchar *Start=new uchar[w*h*3];
    uchar *Stop=new uchar[w*h*3];
    Img2UcharTab(C->Img1, Start);
    Img2UcharTab(C->Img2, Stop);

    for (int i=0; i<C->Frames; i++)
    {
        float percent = C->easing( (float)i/(C->Frames-1) );
        uchar *res =generateFrame(percent, w, h, Start, Stop);
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
        QRgb* Data = (QRgb*) Img.scanLine(i);
        for (int j=0; j<w; j++)
        {
            //Data[j] = ((uint)In[ind]<<24) | ((uint)In[ind+1]<<16) | ((uint)In[ind+2]<<8);
            //Data[i] = 31;
            Img.setPixel(j,i,((uint)In[ind]<<16) | ((uint)In[ind+1]<<8) | ((uint)In[ind+2]));
            ind+=3;
        }
    }
}
