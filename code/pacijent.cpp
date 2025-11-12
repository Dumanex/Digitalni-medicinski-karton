#include "pacijent.h"

#include "lekException.h"
#include "terminException.h"

using namespace std;

Pacijent::Pacijent(string ime, string prezime, polOsobe pol, Datum datumRodjenja ,string adresa, string brTelefona) : Osoba(ime, prezime, pol, datumRodjenja, adresa, brTelefona) {}

Pacijent::~Pacijent() {
    cout << "Destruktor za pacijenta." << endl;
}

void Pacijent::prikaziPodatke() const {
    cout << "---------------------------------\n";
    cout << "        PODACI O PACIJENTU       \n";
    cout << "---------------------------------\n";
    cout << "Ime:           " << getIme() << "\n"
         << "Prezime:       " << getPrezime() << "\n"
         << "Pol:           " << prikaziPol() << "\n" 
         << "Datum rođenja: " << getDatumRodjenja()._dan << ". " << getDatumRodjenja()._mesec << " " << getDatumRodjenja()._godina << "." << "\n"
         << "Adresa:        " << getAdresa() << "\n" 
         << "Broj telefona: " << getBrTelefona() << "\n";
    cout << endl;

    istorija.ispisiIstoriju();
    cout << "Lekovi: ";
    for(auto lek : lekovi)
    {
       cout << lek->getNaziv() << " | "; 
    }
    cout << "\n---------------------------------\n";
    cout << endl;
}

void Pacijent::zakaziTermin(Doktor *doktor) {

    cout << "Izabrali ste doktora: " << doktor -> getIme() << " " << doktor -> getPrezime() << " (" << doktor -> getSpecijalnost() << ")" << endl;
    doktor -> prikaziDostupneTermine();

    cout << "Izaberite termin(sati): ";
    int termin;
    cin >> termin;

    if(doktor -> zakaziTermin(termin)) {
        cout << "Termin uspesno zakazan za " << termin << ":00" << endl;
    }
    else {
        throw terminException();
    }
    cout << "---------------------------------\n";
}

void Pacijent::dodajLek( Lek *lek) {
    for(const auto &trenutniLek : lekovi) {
        if(trenutniLek -> getNaziv() == lek -> getNaziv()) {
            return;
        }
    }

    bool lekJeDodat = false;

    for(string bolestPacijenta : istorija.getBolesti()) {
        if(lek -> daLiJeOdgovarajucaBolest(bolestPacijenta)) {
            lekovi.push_back(lek);
            cout << "Lek " << lek -> getNaziv() << " je uspesno dodat pacijentu " << getIme() << " " << getPrezime() << endl;
            lekJeDodat = true;
            break;
        }
        if(lekJeDodat) {
            break;
        }
    }

    if(!lekJeDodat) {
        throw lekException(getIme(), lek -> getNaziv());
    }
}

vector<Lek*> Pacijent::getLek() {
    return lekovi;
}

medicinskaIstorija& Pacijent::getMedicinskaIstorija() {
    return istorija;
}

Pacijent* Pacijent::kreirajPacijenta() {
    string ime, prezime, adresa, brTelefona, bolest;
    polOsobe pol;
    char slovoPola;

    int dan;
    string mesec;
    int godina;

    int brBolesti;

    cout << endl;
    cout << "Unesite ime pacijenta: ";
    getline(cin, ime); // getline se koristi kako bi se pokupio ceo red, dok cin kupi to prve praznine

    cout << "Unesite prezime pacijenta: ";
    getline(cin, prezime);

    cout << "Unesite pol pacijenta (M/Z): ";
    cin >> slovoPola;
    cin.ignore(); // kada bi koristili getline nakon cin >> variabla, ostao bi \n u baferu. Ovim ignore zapravo ignorisemo taj prvi karakter koji je ostao u baferu
    if(slovoPola == 'M' || slovoPola == 'm') {
        pol = polOsobe::M;
    } else if(slovoPola == 'Z' || slovoPola == 'z') {
        pol = polOsobe::Z;
    } else {
        pol = polOsobe::NEPOZNATO;
    }

    cout << "Unesite dan rodjenja pacijenta (dd): ";
    cin >> dan;
    cin.ignore();

    cout << "Unesite mesec rodjenja pacijenta (MESEC): ";
    getline(cin, mesec);

    cout << "Unesite godina rodjenja pacijenta (yyyy): ";
    cin >> godina;
    cin.ignore();

    cout << "Unesite adresu pacijenta: ";
    getline(cin, adresa);

    cout << "Unesite broj telefona pacijenta: ";
    getline(cin, brTelefona);

    Pacijent *noviPacijent = new Pacijent(ime, prezime, pol, {dan, mesec, godina}, adresa, brTelefona);

    cout << "Koliko bolesti ima pacijent? ";
    cin >> brBolesti;
    cin.ignore();

    for(int i = 0; i < brBolesti; i++) {
        cout << "Unesite " << i + 1 << "." << " bolest: ";
        getline(cin, bolest);
        noviPacijent->getMedicinskaIstorija().dodajBolest(bolest);
    }

    return noviPacijent;
}

