#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller;

#include "przejscie.h"
#include <QImage>
#include <QProgressBar>
#include <vector>
using namespace std;

class Controller
{
    friend class Przejscie;
    public:
        Controller();
		~Controller();
		void setFrames(int arg);
		
        QImage& getImg1();
        QImage& getImg2();
        QImage& getOutput(int i);
        void setPrzejscie(Przejscie *arg);
        const vector<string>& getEasings();
        void setEasing(int num);
        int getFrames() const;
        bool isReady();
        void clear();
        void generate(QProgressBar *ProgressBar);
        void generated();
	private:
        float easing (float arg);
        QImage Img1;
        QImage Img2;
        int Frames;
        bool Ready;
        Przejscie *MyPrzejscie;
        vector<QImage*> Output;
        vector<string> Easings;
        int EasingNum;
};

#endif // CONTROLLER_H
