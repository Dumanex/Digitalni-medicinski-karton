#include "sistemZdravstva.h"

#include "terminException.h"
#include "pacijentException.h"
#include "doktorException.h"
#include "lekException.h"

sistemZdravstva::~sistemZdravstva() {
    cout << "Destruktor za sistem zdravstva." << endl;

    for(auto &pacijent : pacijenti) {
        delete pacijent;
    }

    for(auto &doktor : doktori) {
        delete doktor;
    }

    for(auto &lek : lekovi) {
        delete lek;
    }
}

void sistemZdravstva::dodajOsobu(Osoba *osoba) {
    osobe.push_back(osoba);
}

void sistemZdravstva::dodajDoktora(Doktor *doktor) {
    doktori.push_back(doktor);
}

void sistemZdravstva::dodajPacijenta(Pacijent *pacijent) {
    pacijenti.push_back(pacijent);
}

void sistemZdravstva::dodajLek(Lek *lek) {
    lekovi.push_back(lek);
}

vector<Pacijent*> sistemZdravstva::getPacijenti() const {
    return pacijenti;
}

vector<Doktor*> sistemZdravstva::getDoktori() const {
    return doktori;
}

vector<Lek*> sistemZdravstva::getLekovi() const {
    return lekovi;
}

void sistemZdravstva::prikaziSveDoktore() const {
    for (size_t i = 0; i < doktori.size(); ++i) {
        cout << i + 1 << ". " << doktori[i] -> getIme() << " " << doktori[i] -> getPrezime()
             << " - Specijalnost: " << doktori[i] -> getSpecijalnost() << "\n";
    }
}

void sistemZdravstva::prikaziSvePacijente() const {
    for(int i = 0; i < pacijenti.size(); ++i) {
        cout << i + 1 << ". " << pacijenti[i] -> getIme() << " " << pacijenti[i] -> getPrezime() << endl;
    }
}

void sistemZdravstva::zakaziTerminZaPacijenta() {
    cout << "\n---------------------------------\n";
    cout << "   ZAKAZIVANJE TERMINA ZA PACIJENTA   \n";
    cout << "---------------------------------\n";
    bool zakazano = false;

    while(!zakazano) {
        prikaziSvePacijente();
        cout << "Izaberite koji pacijent zeli da zakaze termin:";

        int izborPacijenta;
        cin >> izborPacijenta;

        try {
            if(izborPacijenta <= 0 || izborPacijenta > static_cast<int>(pacijenti.size())) {
                throw pacijentException();
            }
        } catch (pacijentException e) {
            cout << e.what() << endl;
            cout << "Pokušajte ponovo.\n";
            continue;
        }
        Pacijent *izabraniPacijent = pacijenti[izborPacijenta - 1];
        
        cout << "Pacijent: " << izabraniPacijent -> getIme() << " " << izabraniPacijent -> getPrezime() << "\n";
        cout << "Izaberite doktora:\n";
        prikaziSveDoktore();

        int izborDoktora;
        cin >> izborDoktora;

        try {
            if (izborDoktora <= 0 || izborDoktora > static_cast<int>(doktori.size())) {
                throw doktorException();
            }
            
            Doktor *izabraniDoktor = doktori[izborDoktora - 1];
            izabraniPacijent -> zakaziTermin(izabraniDoktor);
            zakazano = true;

            for (auto &lek : lekovi) {
                try {
                    izabraniDoktor -> predloziLek(izabraniPacijent, lek);
                } catch (const lekException& e) {
                    cout << e.what() << endl;
                }
            }
        } catch (const terminException& e) {
            cout << e.what() << endl;
            cout << "Pokušajte ponovo.\n";
        } catch (const doktorException& e) {
            cout << e.what() << endl;
            cout << "Pokušajte ponovo.\n";
        } catch (...) {
            cout << "Generalna greška...\n";
            zakazano = true;
        }
    }
    cout << "---------------------------------\n";
}

void sistemZdravstva::zakaziTerminZaSvePacijente() {
    for (auto& pacijent : pacijenti) {
        bool zakazano = false;

        while (!zakazano) {
            cout << "\n---------------------------------\n";
            cout << "   ZAKAZIVANJE TERMINA ZA PACIJENTA   \n";
            cout << "---------------------------------\n";
            cout << "Pacijent: " << pacijent -> getIme() << " " << pacijent -> getPrezime() << "\n";
            cout << "Izaberite doktora:\n";
            prikaziSveDoktore();

            int izborDoktora;
            cin >> izborDoktora;

            try {
                if (izborDoktora <= 0 || izborDoktora > static_cast<int>(doktori.size())) {
                    throw doktorException();
                }
                
                Doktor *izabraniDoktor = doktori[izborDoktora - 1];
                pacijent -> zakaziTermin(izabraniDoktor);
                zakazano = true;

                for (auto &lek : lekovi) {
                    try {
                        izabraniDoktor -> predloziLek(pacijent, lek);
                    } catch (const lekException& e) {
                        cout << e.what() << endl;
                    }
                }
            } catch (const terminException& e) {
                cout << e.what() << endl;
                cout << "Pokušajte ponovo.\n";
            } catch (const doktorException& e) {
                cout << e.what() << endl;
                cout << "Pokušajte ponovo.\n";
            } catch (...) {
                cout << "Generalna greška...\n";
                zakazano = true;
            }
        }
        cout << "---------------------------------\n";
    }
}

void sistemZdravstva::prikaziInformacije() const {
    int brPacijenata = 0;
    int brDoktora = 0;
    int brLekova = 0;
    brPacijenata = pacijenti.size();
    brDoktora = doktori.size();
    brLekova = lekovi.size();

    cout << "\n---------------------------------------------------\n";
    cout << "    PRIKAZIVANJE INFORMACIJA O ZDRAVSTVENOM SISTEMU    ";
    cout << "\n---------------------------------------------------\n";
    cout << "Broj pacijenata: " << brPacijenata << endl;
    cout << "Broj doktora: " << brDoktora << endl;
    cout << "Broj lekova: " << brLekova << endl;
    cout << "   Informacije o osobama u sistemu:   " << endl;
    for(auto &osoba : osobe) {
        osoba -> prikaziPodatke();
    }
    cout << "  Informacije o lekovima u sistemu:  " << endl;
    for(auto &lek : lekovi) {
        lek -> prikaziPodatke();
    }
}

