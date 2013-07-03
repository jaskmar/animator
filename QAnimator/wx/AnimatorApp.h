//---------------------------------------------------------------------------
//
// Name:        AnimatorApp.h
// Author:      Jaskmar
// Created:     2012-11-17 11:55:42
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __ANIMATORFRMApp_h__
#define __ANIMATORFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class AnimatorFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
