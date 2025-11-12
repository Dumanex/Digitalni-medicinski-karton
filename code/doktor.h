#ifndef DOKTOR_H
#define DOKTOR_H

#include "osoba.h"
#include "pacijent.h"
#include "lek.h"
#include <vector>
#include <map>

class Pacijent;
class Lek;

class Doktor : public Osoba {
    string _specijalnost;
    map<int, bool> termini; // map koristimo da bi za odredjeno vreme videli da li ima slobodan termin(int su satnice, npr. 8, a bool je true ili false u zavisnosti da li je ta satnica slobodna ili ne, ako je true onda je slobodna)
public:
    Doktor(string ime, string prezime, polOsobe pol, Datum datumRodjenja, string adresa, string brTelefona, string specijalnost = "Opsta praksa");
    ~Doktor();

    string getSpecijalnost() const;
    void prikaziPodatke() const override;

    void prikaziDostupneTermine() const;
    bool zakaziTermin(int termin);
    void predloziLek(Pacijent *pacijent, Lek *lek);
    static Doktor* kreirajDoktora();
};

#endif
