#include "lek.h"

Lek::Lek(string naziv, vector<string> odgovarajuceBolesti) : _naziv(naziv), _odgovarajuceBolesti(odgovarajuceBolesti) {}

Lek::~Lek() {
    cout << "Destruktor za lek" << endl;
}

string Lek::getNaziv() const {
    return _naziv;
}

vector<string> Lek::getOdgocarajuceBolesti() const {
    return _odgovarajuceBolesti;
}

void Lek::prikaziPodatke() const {
    cout << "\n---------------------------------\n";
    cout << "        PODACI O LEKU            \n";
    cout << "---------------------------------\n";
    cout << "Naziv: " << getNaziv() << endl;
    cout << "Bolesti koje leci lek: ";
    for(auto &bolest : _odgovarajuceBolesti) {
        cout << bolest << " | ";
    }
}

bool Lek::daLiJeOdgovarajucaBolest(string bolest) const {
    for(string bolestLeka : _odgovarajuceBolesti) {
        if(bolest == bolestLeka) {
            return true;
        }
    }
    return false;
}

Lek* Lek::kreirajLek() {
    string naziv;
    int brojBolesti;
    vector<string> bolesti;

    cout << "Unesite naziv leka: ";
    getline(cin, naziv);

    cout << "Koliko bolesti leči ovaj lek? ";
    cin >> brojBolesti;
    cin.ignore();

    for (int i = 0; i < brojBolesti; i++) {
        string bolest;
        cout << "Unesite naziv bolesti: ";
        getline(cin, bolest);
        bolesti.push_back(bolest);
    }

    Lek *noviLek = new Lek(naziv, bolesti);
    
    return noviLek;
}

