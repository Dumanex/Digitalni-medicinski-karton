#ifndef LEK_H
#define LEK_H

using namespace std;

#include <string>
#include <vector>
#include "medicinskaIstorija.h"

class Lek {
private:
    string _naziv;
    vector<string> _odgovarajuceBolesti;
public:
    Lek(string naziv, vector<string> odgovarajuceBolesti);
    ~Lek();

    string getNaziv() const;
    vector<string> getOdgocarajuceBolesti() const;
    void prikaziPodatke() const;
    bool daLiJeOdgovarajucaBolest(string bolest) const;
    static Lek* kreirajLek();
};

#endif
