#include <iostream>

#include "osoba.h"
#include "medicinskaIstorija.h"
#include "pacijent.h"
#include "doktor.h"
#include "sistemZdravstva.h"
#include "lek.h"

using namespace std;


int main(int argc, char const *argv[])
{
    sistemZdravstva *sistem = new sistemZdravstva();

    /* Pacijent *p1 = new Pacijent("Vladimir", "Dumanovic", M, {20, "Novembar", 2003}, "Vojislava Tankosica 10/5", "0604567063");
    p1 -> getMedicinskaIstorija().dodajBolest("Grip");
    p1 -> getMedicinskaIstorija().dodajBolest("Upala");
    sistem -> dodajPacijenta(p1);
    sistem -> dodajOsobu(p1);

    Doktor *obicanDoktor = new Doktor("Milovan", "Glisic", M, {23, "Jun", 2003}, "Nikole Pasica 5/2", "0601234567");
    sistem -> dodajDoktora(obicanDoktor);
    sistem -> dodajOsobu(obicanDoktor);

    Lek *aspirin = new Lek("Aspirin",{"Grip", "Glavobolja"});
    sistem -> dodajLek(aspirin); */

    int opcija = 0;

    while (opcija != 7) {
        cout << "\n---------------------------------\n";
        cout << "\n   DIGITALNI MEDICINSKI KARTON   \n";
        cout << "\n---------------------------------\n";
        cout << "1. Dodaj pacijenta\n";
        cout << "2. Dodaj doktora\n";
        cout << "3. Dodaj lek\n";
        cout << "4. Zakazi termin za pacijenta\n";
        cout << "5. Zakazi termin za sve pacijente\n";
        cout << "6. Prikazi informacije o sistemu zdravstva\n";
        cout << "7. Izlaz\n";
        cout << "------------------------------\n";
        cout << "Izaberite opciju: ";
        cin >> opcija;
        cin.ignore();

        switch(opcija) {
            case 1: {
                Pacijent *pomPacijent = Pacijent::kreirajPacijenta();
                sistem -> dodajPacijenta(pomPacijent);
                sistem -> dodajOsobu(pomPacijent);
                break;
            }
            case 2: {
                Doktor *pomDoktor = Doktor::kreirajDoktora();
                sistem -> dodajDoktora(pomDoktor);
                sistem -> dodajOsobu(pomDoktor);
                break;
            }
            case 3: {
                Lek *pomLek = Lek::kreirajLek();
                sistem -> dodajLek(pomLek);
                break;
            }
            case 4: {
                if(sistem -> getPacijenti().empty()) {
                    cout << "Nema pacijenata u sistemu da biste zakazali termin." << endl;
                    break;
                }
                sistem -> zakaziTerminZaPacijenta();
                break;
            }
            case 5: {
                if (sistem -> getPacijenti().empty() || sistem -> getDoktori().empty()) {
                    cout << "Nema pacijenata ili doktora u sistemu za zakazivanje termina.\n";
                    break;
                }

                sistem -> zakaziTerminZaSvePacijente();
                break;
            }

            case 6:
                sistem -> prikaziInformacije();
                break;
            case 7:
                cout << "\nIzlaz iz programa.\n" << endl;
                delete sistem;
                break;
            default:
                cout << "Nepoznata opcija. Pokusajte ponovo.\n";
                break;
        }
    }
    return 0;
}