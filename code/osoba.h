#ifndef OSOBA_H
#define OSOBA_H

#include <iostream>
using namespace std;

#include "datum.h"

enum polOsobe {M, Z, NEPOZNATO};

class Osoba {
    string _ime;
    string _prezime;
    polOsobe _pol;
    Datum _datumRodjenja;
    string _adresa;
    string _brTelefona;
public:
    Osoba(string ime, string prezime, polOsobe pol, Datum datumRodjenja, string adresa, string brTelefona);
    virtual ~Osoba();

    virtual void prikaziPodatke() const = 0;

    string getIme() const;
    string getPrezime() const;
    polOsobe getPol() const;
    string prikaziPol() const;
    Datum getDatumRodjenja() const;
    string getAdresa() const;
    string getBrTelefona() const;
};

#endif
