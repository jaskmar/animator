#include "controller.h"
#include <cmath>
#define sign(x) (((x)>0)-((x)<0))

Controller::Controller()
{
    Frames=60;
	Ready = false;
	MyPrzejscie = 0;
	Easings.push_back("Liniowy");
	Easings.push_back("Paraboliczny");
	Easings.push_back("Logarytmiczny");
	Easings.push_back("Kauczuk");
	Easings.push_back("Grawitacja");
	Easings.push_back("Szybko-wolno-szybko");
	Easings.push_back("Wolno-szybko-wolno");
}

Controller::~Controller()
{

}

void Controller::setFrames(int arg)
{
	if (arg==Frames) return;
	Frames=arg;
	Ready = false;
}

QImage& Controller::getImg1()
{
	return Img1;
}

QImage& Controller::getImg2()
{
	return Img2;
}
QImage& Controller::getOutput(int i)
{
    return *Output[i];
}

void Controller::setPrzejscie(Przejscie *arg)
{
    MyPrzejscie = arg;
}

int Controller::getFrames() const
{
	return Frames;
}

bool Controller::isReady()
{
    return Ready;
}

void Controller::clear()
{
    while (Output.size())
    {
        delete Output[Output.size()-1];
        Output.pop_back();
    }
    Ready = false;
}

void Controller::generate(QProgressBar *ProgressBar)
{
    if (!MyPrzejscie) return;
    MyPrzejscie->generate(this, ProgressBar);
}

void Controller::generated() {
    Ready = true;
}

float Controller::easing(float arg)
{
    switch (EasingNum)
    {
    case 1:
        return pow(1.0f-cos(arg*M_PI/2.0f),2);
    case 2:
        return 1.0f-pow(1.0f-cos((1.0f-arg)*M_PI/2.0f),2);
    case 3:
        return pow(1.0f-(1.0f-(sqrt(arg)))*fabs(cos(arg*M_PI*4.f)),1.5);
    case 4:    
        if (arg < (1.f/2.75f)) return (7.5625f*arg*arg);
        else if (arg < (2.f/2.75f))
            {
                arg -= (1.5f/2.75f);
                return (7.5625f*arg*arg + .75f);
            }
        else if (arg < (2.5f/2.75f)) {
            arg -= (2.25f/2.75f);
            return (7.5625f*arg*arg + .9375f);
        }
        else {
            arg-=(2.625f/2.75f);
            return (7.5625f*arg*arg + .984375f);
        }
    case 5:
        arg = arg*2-1;
        return (arg*arg*sign(arg)+1)*0.5;
    case 6:
        arg = -16*arg+8;
        return (1.f/(1.f+pow(2,arg))-(1.f/256.f))*256.f/254.f;
    default:
        return arg;
    }
}

const vector<string>& Controller::getEasings()
{
    return Easings;
}

void Controller::setEasing(int num)
{
    EasingNum = num;
}
