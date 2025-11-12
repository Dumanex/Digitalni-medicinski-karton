#include "doktor.h"

#include "lekException.h"

Doktor::Doktor(string ime, string prezime, polOsobe pol, Datum datumRodjenja, string adresa, string brTelefona, string specijalnost) : Osoba(ime, prezime, pol, datumRodjenja, adresa, brTelefona), _specijalnost(specijalnost) {
    //inicijalizacija termina od 08:00 do 13:00h
    for(int i = 8; i < 13; i++) {
        termini[i] = true; // svi termini su slobodni na pocetku
    }
}

Doktor::~Doktor() {
    cout << "Destruktor za doktora." << endl;
}

string Doktor::getSpecijalnost() const{
    return _specijalnost;
}

void Doktor::prikaziPodatke() const {
    cout << "\n---------------------------------\n";
    cout << "        PODACI O DOKTORU        \n";
    cout << "---------------------------------\n";
    cout << "Ime:           " << getIme() << "\n"
         << "Prezime:       " << getPrezime() << "\n"
         << "Pol:           " << prikaziPol() << "\n" 
         << "Datum rođenja: " << getDatumRodjenja()._dan << ". " << getDatumRodjenja()._mesec << " " << getDatumRodjenja()._godina << "." << "\n"
         << "Adresa:        " << getAdresa() << "\n" 
         << "Broj telefona: " << getBrTelefona() << "\n"
         << "Specijalnost:  " << getSpecijalnost() << "\n";
    cout << "---------------------------------\n";
    cout << endl;
}

void Doktor::prikaziDostupneTermine() const {
   cout << "\n---------------------------------\n";
    cout << "   DOSTUPNI TERMINI ZA DOKTORA   \n";
    cout << "---------------------------------\n";
    for (const auto& termin : termini) {
        cout << "Termin: " << termin.first << ":00 - " 
             << (termin.second ? "Dostupno" : "Zauzeto") << "\n";
    }
    cout << "---------------------------------\n";
}

bool Doktor::zakaziTermin(int termin) {
    if(termini.find(termin) != termini.end() && termini[termin]) {
        termini[termin] = false;
        return true;
    }
    return false;
}

void Doktor::predloziLek(Pacijent *pacijent, Lek *lek) {
    try {
        pacijent -> dodajLek(lek);
    } catch (lekException e) {
        cout << e.what() << endl;
    }
}

Doktor* Doktor::kreirajDoktora() {
    string ime, prezime, adresa, brTelefona, bolest, specijalnost;
    polOsobe pol;
    char slovoPola;

    int dan;
    string mesec;
    int godina;

    int brBolesti;

    cout << endl;
    cout << "Unesite ime doktora: ";
    getline(cin, ime); // getline se koristi kako bi se pokupio ceo red, dok cin kupi to prve praznine

    cout << "Unesite prezime doktora: ";
    getline(cin, prezime);

    cout << "Unesite pol doktora (M/Z): ";
    cin >> slovoPola;
    cin.ignore(); // kada bi koristili getline nakon cin >> variabla, ostao bi \n u baferu. Ovim ignore zapravo ignorisemo taj prvi karakter koji je ostao u baferu
    if(slovoPola == 'M' || slovoPola == 'm') {
        pol = polOsobe::M;
    } else if(slovoPola == 'Z' || slovoPola == 'z') {
        pol = polOsobe::Z;
    } else {
        pol = polOsobe::NEPOZNATO;
    }

    cout << "Unesite dan rodjenja doktora (dd): ";
    cin >> dan;
    cin.ignore();

    cout << "Unesite mesec rodjenja doktora (MESEC): ";
    getline(cin, mesec);

    cout << "Unesite godina rodjenja doktora (yyyy): ";
    cin >> godina;
    cin.ignore();

    cout << "Unesite adresu doktora: ";
    getline(cin, adresa);

    cout << "Unesite broj telefona doktora: ";
    getline(cin, brTelefona);

    cout << "Unesite specijalnost doktora: ";
    getline(cin, specijalnost);
    if(specijalnost == "") {
        specijalnost = "Opsta praksa";
    }

    Doktor *noviDoktor = new Doktor(ime, prezime, pol, {dan, mesec, godina}, adresa, brTelefona, specijalnost);

    return noviDoktor;
}

