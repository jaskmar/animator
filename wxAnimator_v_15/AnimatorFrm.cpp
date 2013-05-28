///-----------------------------------------------------------------
///
/// @file      AnimatorFrm.cpp
/// @author    Jaskmar
/// Created:   2012-11-17 11:55:42
/// @section   DESCRIPTION
///            AnimatorFrm class implementation
///
///------------------------------------------------------------------

#include "AnimatorFrm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/AnimatorFrm_WxBitmapButton3_XPM.xpm"
#include "Images/AnimatorFrm_WxBitmapButton2_XPM.xpm"
#include "Images/AnimatorFrm_WxBitmapButton1_XPM.xpm"
////Header Include End
#include <wx/dcbuffer.h>

//----------------------------------------------------------------------------
// AnimatorFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(AnimatorFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(AnimatorFrm::OnClose)
	EVT_KEY_DOWN(AnimatorFrm::AnimatorFrmKeyDown)
	EVT_SIZE(AnimatorFrm::AnimatorFrmSize)
	EVT_PAINT(AnimatorFrm::AnimatorFrmPaint)
	EVT_TIMER(ID_TIMER,AnimatorFrm::TimerTimer)
	EVT_BUTTON(ID_WXBITMAPBUTTON3,AnimatorFrm::WxBitmapButton3Click)
	EVT_BUTTON(ID_WXBUTTON6,AnimatorFrm::WxButton6Click)
	EVT_BUTTON(ID_WXBUTTON5,AnimatorFrm::WxButton5Click)
	EVT_LISTBOX(ID_EASINGLIST,AnimatorFrm::EasingListSelected)
	EVT_LISTBOX(ID_PRZEJSCIALIST,AnimatorFrm::WxListBox1Selected)
	
	EVT_COMMAND_SCROLL(ID_SLIDERFPS,AnimatorFrm::SliderFpsScroll)
	
	EVT_COMMAND_SCROLL(ID_SLIDERS,AnimatorFrm::SliderSScroll)
	
	EVT_COMMAND_SCROLL(ID_SLIDERF,AnimatorFrm::SliderFScroll)
	
	EVT_COMMAND_SCROLL(ID_NAWIGATOR,AnimatorFrm::NawigatorScroll)
	EVT_BUTTON(ID_WXBITMAPBUTTON2,AnimatorFrm::WxBitmapButton2Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON1,AnimatorFrm::WxBitmapButton1Click)
	EVT_BUTTON(ID_WXBUTTON1,AnimatorFrm::WxButton1Click)
	EVT_BUTTON(ID_WXBUTTON3,AnimatorFrm::WxButton3Click)
	
	EVT_UPDATE_UI(ID_WXPANEL6,AnimatorFrm::WxPanel6UpdateUI)
END_EVENT_TABLE()
////Event Table End
//######################################################################################################
AnimatorFrm::AnimatorFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
	wxInitAllImageHandlers();
	SliderF->SetValue(60);
	SliderS->SetValue(2000);
	SliderFps->SetValue(30);
	Box1->GetStaticBox()->SetLabel("Obraz 1:");
	Box2->GetStaticBox()->SetLabel("Obraz 2:");
	Ekran->SetDoubleBuffered(true);
	EkranDC = new wxClientDC(Ekran);
	
	Przejscia = VPrzejscia::getPrzejscia();
	for (int i=Przejscia->size()-1; i>=0; i--)
	{
        wxString tmp = Przejscia->at(i)->getName();
        PrzejsciaList->InsertItems(1, &tmp ,0);
    }
    Controll.setPrzejscie(Przejscia->at(0));
    
    const vector<string> E = Controll.getEasings();
	for (int i=E.size()-1; i>=0; i--)
	{
        wxString tmp = E[i];
        EasingList->InsertItems(1, &tmp ,0);
    }
    
    PrzejsciaList->SetSelection(0);
    EasingList->SetSelection(0);
    WxPanel3->Enable(false);
}
//#######################################################################################################
AnimatorFrm::~AnimatorFrm()
{
    delete EkranDC;
}

void AnimatorFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxBoxSizer1 = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(5, 5), wxSize(786, 239));
	WxPanel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW));
	WxBoxSizer1->Add(WxPanel1, 3, wxEXPAND | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	WxPanel1->SetSizer(WxBoxSizer4);
	WxPanel1->SetAutoLayout(true);

	Ekran = new wxStaticBitmap(WxPanel1, ID_EKRAN, wxNullBitmap, wxPoint(5, 55), wxSize(192, 93) );
	Ekran->SetBackgroundColour(wxColour(000,000,000));
	WxBoxSizer4->Add(Ekran, 7, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxPanel6 = new wxPanel(WxPanel1, ID_WXPANEL6, wxPoint(207, 5), wxSize(240, 194));
	WxBoxSizer4->Add(WxPanel6, 3, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxVERTICAL);
	WxPanel6->SetSizer(WxBoxSizer5);
	WxPanel6->SetAutoLayout(true);

	wxStaticBox* Box1_StaticBoxObj = new wxStaticBox(WxPanel6, wxID_ANY, _(""));
	Box1 = new wxStaticBoxSizer(Box1_StaticBoxObj, wxHORIZONTAL);
	WxBoxSizer5->Add(Box1, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	SBitmap1 = new wxStaticBitmap(WxPanel6, ID_SBITMAP1, wxNullBitmap, wxPoint(10, 20), wxSize(40, 15) );
	SBitmap1->SetBackgroundColour(wxColour(000,000,000));
	Box1->Add(SBitmap1, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	wxStaticBox* Box2_StaticBoxObj = new wxStaticBox(WxPanel6, wxID_ANY, _(""));
	Box2 = new wxStaticBoxSizer(Box2_StaticBoxObj, wxHORIZONTAL);
	WxBoxSizer5->Add(Box2, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	SBitmap2 = new wxStaticBitmap(WxPanel6, ID_SBITMAP2, wxNullBitmap, wxPoint(10, 20), wxSize(40, 15) );
	SBitmap2->SetBackgroundColour(wxColour(000,000,000));
	Box2->Add(SBitmap2, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer5->Add(WxBoxSizer7, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton3 = new wxButton(WxPanel6, ID_WXBUTTON3, _("Wczytaj 1"), wxPoint(5, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton3"));
	WxBoxSizer7->Add(WxButton3, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton1 = new wxButton(WxPanel6, ID_WXBUTTON1, _("Wczytaj 2"), wxPoint(90, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));
	WxBoxSizer7->Add(WxButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxPanel3 = new wxPanel(this, ID_WXPANEL3, wxPoint(201, 254), wxSize(393, 58));
	WxPanel3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW));
	WxBoxSizer1->Add(WxPanel3, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxPanel3->SetSizer(WxBoxSizer3);
	WxPanel3->SetAutoLayout(true);

	wxBitmap WxBitmapButton1_BITMAP (AnimatorFrm_WxBitmapButton1_XPM);
	WxBitmapButton1 = new wxBitmapButton(WxPanel3, ID_WXBITMAPBUTTON1, WxBitmapButton1_BITMAP, wxPoint(0, 2), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton1"));
	WxBoxSizer3->Add(WxBitmapButton1, 0, wxALIGN_CENTER | 0, 0);

	wxBitmap WxBitmapButton2_BITMAP (AnimatorFrm_WxBitmapButton2_XPM);
	WxBitmapButton2 = new wxBitmapButton(WxPanel3, ID_WXBITMAPBUTTON2, WxBitmapButton2_BITMAP, wxPoint(50, 2), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton2"));
	WxBoxSizer3->Add(WxBitmapButton2, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 0);

	Nawigator = new wxSlider(WxPanel3, ID_NAWIGATOR, 0, 0, 10, wxPoint(105, 5), wxSize(274, 45), wxSL_HORIZONTAL | wxSL_SELRANGE , wxDefaultValidator, _("Nawigator"));
	Nawigator->SetRange(0,10);
	Nawigator->SetValue(0);
	WxBoxSizer3->Add(Nawigator, 1, wxALIGN_CENTER | wxALL, 5);

	WxPanel2 = new wxPanel(this, ID_WXPANEL2, wxPoint(72, 322), wxSize(651, 137));
	WxPanel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DSHADOW));
	WxBoxSizer1->Add(WxPanel2, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	WxPanel2->SetSizer(WxBoxSizer2);
	WxPanel2->SetAutoLayout(true);

	PFps = new wxPanel(WxPanel2, ID_PFPS, wxPoint(5, 5), wxSize(307, 104));
	WxBoxSizer2->Add(PFps, 0, wxALIGN_CENTER | wxALL, 5);

	WxFlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	PFps->SetSizer(WxFlexGridSizer1);
	PFps->SetAutoLayout(true);

	WxStaticText1 = new wxStaticText(PFps, ID_WXSTATICTEXT1, _("Klatki:"), wxPoint(62, 6), wxDefaultSize, 0, _("WxStaticText1"));
	WxFlexGridSizer1->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	SliderF = new wxSlider(PFps, ID_SLIDERF, 15, 15, 300, wxPoint(165, 5), wxSize(150, 22), wxSL_HORIZONTAL | wxSL_SELRANGE , wxDefaultValidator, _("SliderF"));
	SliderF->SetRange(15,300);
	SliderF->SetValue(15);
	WxFlexGridSizer1->Add(SliderF, 0, wxALIGN_CENTER | wxALL, 5);

	LabelF = new wxStaticText(PFps, ID_LABELF, _("60f"), wxPoint(340, 6), wxDefaultSize, 0, _("LabelF"));
	WxFlexGridSizer1->Add(LabelF, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(PFps, ID_WXSTATICTEXT3, _("Czas:"), wxPoint(64, 38), wxDefaultSize, 0, _("WxStaticText3"));
	WxFlexGridSizer1->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	SliderS = new wxSlider(PFps, ID_SLIDERS, 500, 500, 10000, wxPoint(165, 37), wxSize(150, 22), wxSL_HORIZONTAL | wxSL_SELRANGE , wxDefaultValidator, _("SliderS"));
	SliderS->SetRange(500,10000);
	SliderS->SetValue(500);
	WxFlexGridSizer1->Add(SliderS, 0, wxALIGN_CENTER | wxALL, 5);

	LabelS = new wxStaticText(PFps, ID_LABELS, _("2000ms  "), wxPoint(325, 38), wxDefaultSize, 0, _("LabelS"));
	WxFlexGridSizer1->Add(LabelS, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText5 = new wxStaticText(PFps, ID_WXSTATICTEXT5, _("Klatki na sekundê"), wxPoint(32, 70), wxDefaultSize, 0, _("WxStaticText5"));
	WxFlexGridSizer1->Add(WxStaticText5, 0, wxALIGN_CENTER | wxALL, 5);

	SliderFps = new wxSlider(PFps, ID_SLIDERFPS, 10, 10, 100, wxPoint(165, 69), wxSize(150, 22), wxSL_HORIZONTAL | wxSL_SELRANGE , wxDefaultValidator, _("SliderFps"));
	SliderFps->SetRange(10,100);
	SliderFps->SetValue(10);
	WxFlexGridSizer1->Add(SliderFps, 0, wxALIGN_CENTER | wxALL, 5);

	LabelFps = new wxStaticText(PFps, ID_LABELFPS, _("30fps"), wxPoint(334, 70), wxDefaultSize, 0, _("LabelFps"));
	WxFlexGridSizer1->Add(LabelFps, 0, wxALIGN_CENTER | wxALL, 5);

	ProgressBar = new wxGauge(PFps, ID_PROGRESSBAR, 100, wxPoint(5, 101), wxSize(150, 17), wxGA_HORIZONTAL, wxDefaultValidator, _("ProgressBar"));
	ProgressBar->Show(false);
	ProgressBar->SetRange(100);
	ProgressBar->SetValue(0);
	WxFlexGridSizer1->Add(ProgressBar, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	wxArrayString arrayStringFor_PrzejsciaList;
	PrzejsciaList = new wxListBox(WxPanel2, ID_PRZEJSCIALIST, wxPoint(322, 9), wxSize(102, 97), arrayStringFor_PrzejsciaList, wxLB_SINGLE);
	WxBoxSizer2->Add(PrzejsciaList, 3, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	wxArrayString arrayStringFor_EasingList;
	EasingList = new wxListBox(WxPanel2, ID_EASINGLIST, wxPoint(434, 9), wxSize(73, 97), arrayStringFor_EasingList, wxLB_SINGLE);
	WxBoxSizer2->Add(EasingList, 2, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxBoxSizer8 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer2->Add(WxBoxSizer8, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxButton5 = new wxButton(WxPanel2, ID_WXBUTTON5, _("Generuj"), wxPoint(5, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton5"));
	WxBoxSizer8->Add(WxButton5, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton6 = new wxButton(WxPanel2, ID_WXBUTTON6, _("Zapisz"), wxPoint(5, 40), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton6"));
	WxBoxSizer8->Add(WxButton6, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap WxBitmapButton3_BITMAP (AnimatorFrm_WxBitmapButton3_XPM);
	WxBitmapButton3 = new wxBitmapButton(WxPanel2, ID_WXBITMAPBUTTON3, WxBitmapButton3_BITMAP, wxPoint(5, 75), wxSize(75, 25), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton3"));
	WxBoxSizer8->Add(WxBitmapButton3, 1, wxALIGN_CENTER | wxALL, 5);

	Timer = new wxTimer();
	Timer->SetOwner(this, ID_TIMER);

	WxDirDialog1 =  new wxDirDialog(this, _("Choose a directory"), _(""));

	WxOpenFileDialog1 =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);

	SetTitle(_("Animator"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
}

void AnimatorFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void AnimatorFrm::SliderFScroll(wxScrollEvent& event)
{
	SliderS->SetValue(event.GetPosition()*1000/SliderFps->GetValue());
	UpdateLabels();
	WxPanel3->Enable(false);
}

/*
 * SliderSScroll
 */
void AnimatorFrm::SliderSScroll(wxScrollEvent& event)
{
	SliderF->SetValue(event.GetPosition()*SliderFps->GetValue()/1000);
	UpdateLabels();
	WxPanel3->Enable(false);
}

/*
 * SliderFpsScroll
 */
void AnimatorFrm::SliderFpsScroll(wxScrollEvent& event)
{
    SliderF->SetValue(event.GetPosition()*SliderS->GetValue()/1000);
    SliderF->SetMax(event.GetPosition()*SliderS->GetMax()/1000);
    SliderF->SetMin(event.GetPosition()*SliderS->GetMin()/1000);
	UpdateLabels();
	WxPanel3->Enable(false);
}

void AnimatorFrm::UpdateLabels()
{
	wxString tmp;
	int v;
	v=SliderF->GetValue();
	tmp << v << "f";
	LabelF->SetLabel(tmp);
	tmp="";
	v=SliderS->GetValue();
	tmp << v << "ms";
	LabelS->SetLabel(tmp);
	tmp="";
	v=SliderFps->GetValue();
	tmp << v << "fps";
	LabelFps->SetLabel(tmp);
	Controll.setFrames(SliderF->GetValue());
}

/*
 * WxButton3Click
 */
void AnimatorFrm::WxButton3Click(wxCommandEvent& event)
{
    WxOpenFileDialog1->SetWildcard("Pliki JPG (*.jpg)|*.jpg");
	if (WxOpenFileDialog1->ShowModal()==wxID_OK)
	{
        Controll.getImg1().LoadFile(WxOpenFileDialog1->GetPath());
        SBitmap1->SetBackgroundColour(wxColour(240,240,240));
        refresh();
        WxPanel3->Enable(false);
    }
}

/*
 * WxButton1Click
 */
void AnimatorFrm::WxButton1Click(wxCommandEvent& event)
{
    WxOpenFileDialog1->SetWildcard("Pliki JPG (*.jpg)|*.jpg");
	if (WxOpenFileDialog1->ShowModal()==wxID_OK)
	{
        Controll.getImg2().LoadFile(WxOpenFileDialog1->GetPath());
        SBitmap2->SetBackgroundColour(wxColour(240,240,240));
        refresh();
        WxPanel3->Enable(false);
    }
}

/*
 * WxButton4Click
 */
void AnimatorFrm::WxButton4Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * WxPanel6UpdateUI
 */
void AnimatorFrm::WxPanel6UpdateUI(wxUpdateUIEvent& event)
{

}

/*
 * AnimatorFrmSize
 */
void AnimatorFrm::AnimatorFrmSize(wxSizeEvent& event)
{
    refresh();
}

void AnimatorFrm::refresh()
{
    wxImage tmp;
    int w, h;
	if (Controll.getImg1().IsOk())
	{
        tmp = Controll.getImg1();
        SBitmap1->GetClientSize(&w, &h);
        tmp.Rescale(w,h);
        SBitmap1->SetBitmap(wxBitmap( tmp ));
    }
	if (Controll.getImg2().IsOk())
	{
        tmp = Controll.getImg2();
        SBitmap2->GetClientSize(&w, &h);
        tmp.Rescale(w,h);
        SBitmap2->SetBitmap(wxBitmap( tmp ));
    }
    if (Controll.isReady())
    {
        int N = Nawigator->GetValue();
        tmp = Controll.getOutput(N);
        Ekran->GetClientSize(&w, &h);
        tmp.Rescale(w,h);
        Ekran->SetBitmap(wxBitmap( tmp ));
    }
    Layout();
}

/*
 * WxListBox1Selected
 */
void AnimatorFrm::WxListBox1Selected(wxCommandEvent& event)
{
	int N = event.GetInt();
	Controll.setPrzejscie(Przejscia->at(N));
	WxPanel3->Enable(false);
}

/*
 * AnimatorFrmPaint
 */
void AnimatorFrm::AnimatorFrmPaint(wxPaintEvent& event)
{
	refresh();
}

/*
 * WxBitmapButton1Click
 */
void AnimatorFrm::WxBitmapButton1Click(wxCommandEvent& event)
{
    if (Nawigator->GetValue()==Nawigator->GetMax()) Nawigator->SetValue(0);
	Timer->Start( 1000.0/SliderFps->GetValue() + 0.5 );
}

/*
 * TimerTimer
 */
void AnimatorFrm::TimerTimer(wxTimerEvent& event)
{
	int N = Nawigator->GetValue();
    Nawigator->SetValue(N+1);
    
    wxImage tmp;
    int w, h;
    tmp = Controll.getOutput(N);
    Ekran->GetClientSize(&w, &h);
    tmp.Rescale(w,h);
    
    wxBitmap MemBitmap(tmp);
    wxMemoryDC memDC;
    memDC.SelectObject(MemBitmap);
    EkranDC->Blit(0,0,MemBitmap.GetWidth(),MemBitmap.GetHeight(),&memDC,0,0);
    memDC.SelectObject(wxNullBitmap);
	if (N>=Nawigator->GetMax())
	{
        Timer->Stop();
        return;
    }
}

/*
 * Przycisk Generuj
 */
void AnimatorFrm::WxButton5Click(wxCommandEvent& event)
{
    if (!Controll.getImg1().IsOk() || !Controll.getImg2().IsOk())
    {
        wxMessageBox("Musisz wybraæ dwa obrazki");
        return;
    }
    setSizeOk();
    Controll.clear();
	Controll.generate();
	Nawigator->SetRange(0, SliderF->GetValue()-1);
    Nawigator->SetValue(0);
	WxPanel3->Enable(true);

    Ekran->SetBackgroundColour(wxColour(240,240,240));
	wxMessageBox("Gotowe");
	refresh();
}

void AnimatorFrm::setSizeOk()
{
    if (!Controll.getImg1().IsOk() || !Controll.getImg2().IsOk() ) return;
    int w1, w2, h1, h2, w, h;
    w1 = Controll.getImg1().GetWidth();
    h1 = Controll.getImg1().GetHeight();
    w2 = Controll.getImg2().GetWidth();
    h2 = Controll.getImg2().GetHeight();
    w = (w1>w2) ? w2 : w1;
    h = (h1>h2) ? h2 : h1;
    if (w1!=w || h1!=h) Controll.getImg1().Rescale(w,h);
    if (w2!=w || h2!=h) Controll.getImg2().Rescale(w,h);
}

/*
 * EasingListSelected
 */
void AnimatorFrm::EasingListSelected(wxCommandEvent& event)
{
	int N = event.GetInt();
	Controll.setEasing(N);
	WxPanel3->Enable(false);
}

/*
 * WxBitmapButton2Click
 */
void AnimatorFrm::WxBitmapButton2Click(wxCommandEvent& event)
{
	Timer->Stop();
}

/*
 * NawigatorScroll
 */
void AnimatorFrm::NawigatorScroll(wxScrollEvent& event)
{
	int N = event.GetPosition();
    wxImage tmp;
    int w, h;
    tmp = Controll.getOutput(N);
    Ekran->GetClientSize(&w, &h);
    tmp.Rescale(w,h);
    
    wxBitmap MemBitmap(tmp);
    wxMemoryDC memDC;
    memDC.SelectObject(MemBitmap);
    EkranDC->Blit(0,0,MemBitmap.GetWidth(),MemBitmap.GetHeight(),&memDC,0,0);
    memDC.SelectObject(wxNullBitmap);
}

/*
 * AnimatorFrmKeyDown
 */
void AnimatorFrm::AnimatorFrmKeyDown(wxKeyEvent& event)
{
	refresh();
}

/*
 * WxButton6Click
 */
void AnimatorFrm::WxButton6Click(wxCommandEvent& event)
{
    if(!Controll.isReady())
    {
        wxMessageBox("Animacja nie zosta³a jeszcze wygenerowana!");
        return;
    }
	if (WxDirDialog1->ShowModal()==wxID_OK)
	{
        wxString Dir = WxDirDialog1->GetPath();
        wxString Path;
        wxDateTime czas;
        czas.SetToCurrent();
        Dir << "\\anim_" << czas.Format("%y-%m-%d_%H-%M-%S") << "_f";
        for (int i=0; i<Controll.getFrames(); i++)
        {
            Path=Dir;
            if (i!=0) Path.Append('0',2-(int)log10(i));
            else Path << "00";
            Path << i << ".jpg";
            bool OK = Controll.getOutput(i).SaveFile(Path);
            if (!OK)
            {
                wxMessageBox("Niepowodzenie przy zapisie plików!");
                return;
            }
        }
    }
    wxMessageBox("Pliki zosta³y zapisane!");
}

/*
 * WxBitmapButton3Click
 */
void AnimatorFrm::WxBitmapButton3Click(wxCommandEvent& event)
{
	wxString info;
	info << "\"Animator\"\n\n";
	info << "Program powsta³ jako projekt zaliczeniowy z przedmiotu\n";
	info << "Podstawy Grafiki Komputerowej\n";
	info << "na wydziale Fizyki i Informatyki Stosowanej AGH.\n\n";
	info << "Autorzy:\n";
	info << "Mariusz Jaskó³ka\nPawe³ Ja³ocha\nOla Maczel";
	wxMessageBox(info);
}
