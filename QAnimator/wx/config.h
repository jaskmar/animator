// Class automatically generated by Dev-C++ New Class wizard

#ifndef CONFIG_H
#define CONFIG_H
#include "AnimatorFrm.h"

/*
 * No description
 */
class Config
{
    private:
        AnimatorFrm *Form;
	public:
		// class constructor
		Config(AnimatorFrm *_Form) : Form(_Form) {};
		// class destructor
		~Config();
		wxBitmap GetBitmap1();
		wxBitmap GetBitmap2();
};

#endif // CONFIG_H
