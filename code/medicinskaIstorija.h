#ifndef MEDICINSKAISTORIJA_H
#define MEDICINSKAISTORIJA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class medicinskaIstorija {
    vector<string> bolesti;
public:

    void dodajBolest(string bolest);
    vector<string> getBolesti();
    void ispisiIstoriju() const;
};

#endif
