#ifndef _VPRZEJSCIA_H_
#define _VPRZEJSCIA_H_

class VPrzejscia;

#include <vector>
#include "przejscie.h"
using namespace std;

class VPrzejscia : public vector<Przejscie*>
{
    private:
    VPrzejscia();
    ~VPrzejscia();
    public:
    static VPrzejscia* getPrzejscia();
    private:
    static VPrzejscia *ptr;
};


#endif
