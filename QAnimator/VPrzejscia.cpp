#include "VPrzejscia.h"
#include "P/PPrzenikanie.h"
#include "P/PPrzepychanie_up.h"
#include "P/PPrzepychanie_down.h"
#include "P/PPrzepychanie_left.h"
#include "P/PPrzepychanie_right.h"
#include "P/PNajazd_up.h"
#include "P/POdkrywanie_up.h"
#include "P/POdswiezanie_up.h"
#include "P/PBoks_in.h"
#include "P/PBoks_out.h"
#include "P/PFarba.h"
#include "P/PPaski.h"
#include "P/POkno.h"
#include "P/POdwrot.h"
#include "P/PKostka.h"
#include "P/PPrzylot.h"
#include "P/PKolejnoscJasnosc.h"
#include "P/PCzern.h"
#include "P/POdlot.h"
#include "P/PRGB.h"
#include "P/PTesty.h"


VPrzejscia *VPrzejscia::ptr = 0;

VPrzejscia* VPrzejscia::getPrzejscia()
{
    if (!ptr) ptr = new VPrzejscia();
    return ptr;
}

VPrzejscia::VPrzejscia()
{
    //tutaj trzeba dodawac wszystkie nowe przejscia
    push_back(new PNajazd_up());
    push_back(new PPrzenikanie());
    push_back(new PKolejnoscJasnosc());
    push_back(new PKostka());
    push_back(new PBoks_in());
    push_back(new PBoks_out());
    push_back(new PTesty());
    push_back(new PRGB());
    
    push_back(new PPrzepychanie_up());
    push_back(new PPrzepychanie_down());
    push_back(new PPrzepychanie_left());
    push_back(new PPrzepychanie_right());
    push_back(new POdkrywanie_up());
    push_back(new POdswiezanie_up());
    push_back(new POkno());
    push_back(new POdwrot());
    push_back(new PPrzylot());
    push_back(new PCzern());
    push_back(new POdlot());
    push_back(new PFarba());
    push_back(new PPaski());
    
}

VPrzejscia::~VPrzejscia()
{
    if (ptr)
    {
        for (unsigned int i=0; i<ptr->size(); i++) delete ptr->at(i);
        delete ptr;
    }
}
