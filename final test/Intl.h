#pragma once
// Intl.h

#ifndef GUARD_Intl_h
#define GUARD_Intl_h

#include <iostream>
#include <string>
#include "Core.h"

using namespace std;

class Intl : public Core {
public:
    Intl() : country("Unknown"), visaType("None") { };
    Intl(istream& is) { read(is); };
    double grade() const;
    istream& read(istream&);

private:
    string country;
    string visaType;
    Intl* clone() const { return new Intl(*this); }
};

#endif