#include "medicinskaIstorija.h"

void medicinskaIstorija::dodajBolest(string bolest) {
    for(string postojecaBolest : bolesti) {
        if(postojecaBolest == bolest) {
            return;
        }
    }
    bolesti.push_back(bolest);
}

vector<string> medicinskaIstorija::getBolesti() {
    return bolesti;
}

void medicinskaIstorija::ispisiIstoriju() const{
    cout << "Bolesti: ";
    for(auto bolest : bolesti)
    {
       cout << bolest << " | "; 
    }
    
    cout << endl;
}

