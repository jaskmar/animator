///-----------------------------------------------------------------
///
/// @file      AnimatorFrm.h
/// @author    Jaskmar
/// Created:   2012-11-17 11:55:42
/// @section   DESCRIPTION
///            AnimatorFrm class declaration
///
///------------------------------------------------------------------

#ifndef __ANIMATORFRM_H__
#define __ANIMATORFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/filedlg.h>
#include <wx/dirdlg.h>
#include <wx/timer.h>
#include <wx/listbox.h>
#include <wx/gauge.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/statbmp.h>
#include <wx/panel.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef AnimatorFrm_STYLE
#define AnimatorFrm_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

#include "controller.h"
#include "VPrzejscia.h"

class AnimatorFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		AnimatorFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Animator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = AnimatorFrm_STYLE);
		virtual ~AnimatorFrm();
		void WxSlider1Scroll(wxScrollEvent& event);
		void WxSlider1Scroll0(wxScrollEvent& event);
		void SliderFScroll(wxScrollEvent& event);
		void SliderSScroll(wxScrollEvent& event);
		void SliderFpsScroll(wxScrollEvent& event);
		void SliderFSlider(wxCommandEvent& event);
		void WxButton3Click(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void WxButton4Click(wxCommandEvent& event);
		void WxPanel6UpdateUI(wxUpdateUIEvent& event);
		void AnimatorFrmSize(wxSizeEvent& event);
		void WxListBox1Selected(wxCommandEvent& event);
		void AnimatorFrmPaint(wxPaintEvent& event);
		void WxBitmapButton1Click(wxCommandEvent& event);
		void TimerTimer(wxTimerEvent& event);
		void WxButton5Click(wxCommandEvent& event);
		void EasingListSelected(wxCommandEvent& event);
		void WxBitmapButton2Click(wxCommandEvent& event);
		void NawigatorScroll(wxScrollEvent& event);
		void AnimatorFrmKeyDown(wxKeyEvent& event);
		void WxButton6Click(wxCommandEvent& event);
		void WxBitmapButton3Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxFileDialog *WxOpenFileDialog1;
		wxDirDialog *WxDirDialog1;
		wxTimer *Timer;
		wxBitmapButton *WxBitmapButton3;
		wxButton *WxButton6;
		wxButton *WxButton5;
		wxBoxSizer *WxBoxSizer8;
		wxListBox *EasingList;
		wxListBox *PrzejsciaList;
		wxGauge *ProgressBar;
		wxStaticText *LabelFps;
		wxSlider *SliderFps;
		wxStaticText *WxStaticText5;
		wxStaticText *LabelS;
		wxSlider *SliderS;
		wxStaticText *WxStaticText3;
		wxStaticText *LabelF;
		wxSlider *SliderF;
		wxStaticText *WxStaticText1;
		wxFlexGridSizer *WxFlexGridSizer1;
		wxPanel *PFps;
		wxBoxSizer *WxBoxSizer2;
		wxPanel *WxPanel2;
		wxSlider *Nawigator;
		wxBitmapButton *WxBitmapButton2;
		wxBitmapButton *WxBitmapButton1;
		wxBoxSizer *WxBoxSizer3;
		wxPanel *WxPanel3;
		wxButton *WxButton1;
		wxButton *WxButton3;
		wxBoxSizer *WxBoxSizer7;
		wxStaticBitmap *SBitmap2;
		wxStaticBoxSizer *Box2;
		wxStaticBitmap *SBitmap1;
		wxStaticBoxSizer *Box1;
		wxBoxSizer *WxBoxSizer5;
		wxPanel *WxPanel6;
		wxStaticBitmap *Ekran;
		wxBoxSizer *WxBoxSizer4;
		wxPanel *WxPanel1;
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_TIMER = 1052,
			ID_WXBITMAPBUTTON3 = 1070,
			ID_WXBUTTON6 = 1064,
			ID_WXBUTTON5 = 1063,
			ID_EASINGLIST = 1059,
			ID_PRZEJSCIALIST = 1057,
			ID_PROGRESSBAR = 1071,
			ID_LABELFPS = 1021,
			ID_SLIDERFPS = 1020,
			ID_WXSTATICTEXT5 = 1019,
			ID_LABELS = 1018,
			ID_SLIDERS = 1017,
			ID_WXSTATICTEXT3 = 1016,
			ID_LABELF = 1015,
			ID_SLIDERF = 1014,
			ID_WXSTATICTEXT1 = 1013,
			ID_PFPS = 1005,
			ID_WXPANEL2 = 1023,
			ID_NAWIGATOR = 1054,
			ID_WXBITMAPBUTTON2 = 1028,
			ID_WXBITMAPBUTTON1 = 1027,
			ID_WXPANEL3 = 1022,
			ID_WXBUTTON1 = 1068,
			ID_WXBUTTON3 = 1042,
			ID_SBITMAP2 = 1051,
			ID_SBITMAP1 = 1050,
			ID_WXPANEL6 = 1066,
			ID_EKRAN = 1065,
			ID_WXPANEL1 = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		void UpdateLabels();
		void refresh();
		void setSizeOk();
		Controller Controll;
		VPrzejscia *Przejscia;
		wxClientDC *EkranDC;
};

#endif
