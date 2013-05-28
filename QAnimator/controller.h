// Class automatically generated by Dev-C++ New Class wizard

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller;

#include "przejscie.h"
#include <QImage>
#include <vector>
using namespace std;

/*
 * No description
 */
class Controller
{
    friend class Przejscie;
	public:
		// class constructor
		Controller();
		// class destructor
		~Controller();
		void setFrames(int arg);
		//void setPrzejscie();
		
        QImage& getImg1();
        QImage& getImg2();
        QImage& getOutput(int i);
        void setPrzejscie(Przejscie *arg);
        const vector<string>& getEasings();
        void setEasing(int num);
        int getFrames() const;
        bool isReady();
        void clear();
        void generate();
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