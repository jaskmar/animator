// Class automatically generated by Dev-C++ New Class wizard

#include "przejscie.h" // class's header file

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
    for (int i=0; i<C->Frames; i++)
    {
        float percent = C->easing( (float)i/(C->Frames-1) );
        int w, h;
        w = C->Img1.GetWidth();
        h = C->Img1.GetHeight();
        uchar *res =generateFrame(percent, w, h, C->Img1.GetData(), C->Img2.GetData());
        wxImage *Tmp = new wxImage(w,h);
        Tmp->SetData(res);
        C->Output.push_back(Tmp);
    }
}
/*

golbal vector<wxbitmap*> vec
global klatki
global fps

przejscie::generuj()
{
 jakis switch ? 
// pobranie nazwy przejscia
 easing = pobranie nazwy easingu    
for i = 0 to klatki
i*easing

   
}

przejscie::zapisz()
{
    for liczba klatek
    save(vec[i])
    
    
}

timer()
{
    if !koniec
    slider.value++
}

slider_change()
{
    draw(value)
    if value = value_max 
    bool koniec=true;
    
}
global przejscie wsk*
generuj_click()
{
delete wsk; poprzednie kasujemy;
if lista.selected=="z gory" // lub fabryka;
wsk = new przejscie_zgory;

}








*/