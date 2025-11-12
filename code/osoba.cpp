#include "osoba.h"

Osoba::Osoba(string ime, string prezime, polOsobe pol, Datum datumRodjenja, string adresa, string brTelefona ) : _ime(ime), _prezime(prezime), _pol(pol), _datumRodjenja(datumRodjenja), _adresa(adresa), _brTelefona(brTelefona) {
}

Osoba::~Osoba() {
    cout << "Destruktor za osobu." << endl;
}

string Osoba::getIme() const {
    return _ime;
}

string Osoba::getPrezime() const {
    return _prezime;
}

polOsobe Osoba::getPol() const {
    return _pol;
}

string Osoba::prikaziPol() const {
    if(_pol == polOsobe::M) {
        return "Muski";
    } else if(_pol == polOsobe::Z){
        return "Zenski";
    } else {
        return "Nepoznat";
    }
}

Datum Osoba::getDatumRodjenja() const {
    return _datumRodjenja;
}

string Osoba::getAdresa() const {
    return _adresa;
}

string Osoba::getBrTelefona() const {
    return _brTelefona;
}

