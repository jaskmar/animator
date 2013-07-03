//---------------------------------------------------------------------------
//
// Name:        AnimatorApp.cpp
// Author:      Jaskmar
// Created:     2012-11-17 11:55:42
// Description: 
//
//---------------------------------------------------------------------------

#include "AnimatorApp.h"
#include "AnimatorFrm.h"

IMPLEMENT_APP(AnimatorFrmApp)

bool AnimatorFrmApp::OnInit()
{
    AnimatorFrm* frame = new AnimatorFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int AnimatorFrmApp::OnExit()
{
	return 0;
}
