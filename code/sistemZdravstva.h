#ifndef SISTEMZDRAVSTVA_H
#define SISTEMZDRAVSTVA_H

#include <vector>
#include "doktor.h"
#include "pacijent.h"
#include "lek.h"

class sistemZdravstva {
    vector<Osoba*> osobe;
    vector<Pacijent*> pacijenti;
    vector<Doktor*> doktori;
    vector<Lek*> lekovi;
public:
    ~sistemZdravstva();

    void dodajOsobu(Osoba *osoba);
    void dodajPacijenta(Pacijent *pacijent);
    void dodajDoktora(Doktor *doktor);
    void dodajLek(Lek *lek);

    vector<Pacijent*> getPacijenti() const;
    vector<Doktor*> getDoktori() const;
    vector<Lek*> getLekovi() const;

    void prikaziSveDoktore() const;
    void prikaziSvePacijente() const;
    void zakaziTerminZaPacijenta();
    void zakaziTerminZaSvePacijente();
    void prikaziInformacije() const;
};

#endif
