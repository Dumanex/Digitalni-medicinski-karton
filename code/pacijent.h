#ifndef PACIJENT_H
#define PACIJENT_H

using namespace std;

#include "osoba.h"
#include "medicinskaIstorija.h"
#include "doktor.h"
#include "lek.h"

class Doktor;

class Pacijent : public Osoba {
    vector<Lek*> lekovi;
    medicinskaIstorija istorija;
public:

    Pacijent(string ime, string prezime, polOsobe pol, Datum datumRodjenja, string adresa, string brTelefona);
    ~Pacijent();

    void prikaziPodatke() const override;
    void zakaziTermin(Doktor *doktor);
    void dodajLek(Lek *lek);
    vector<Lek*> getLek();
    medicinskaIstorija& getMedicinskaIstorija(); // stavili smo medicinskaIstorija& i ovaj ampersent je bitan zato sto ce da vrati referencu na objekat i tako u main mozemo da menjamo njegove podatke
    static Pacijent* kreirajPacijenta(); // koristimo static metodu kako ne bismo morali da pravimo objekat tipa Pacijent
};

#endif
