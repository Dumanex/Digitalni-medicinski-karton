#ifndef DATUM_H
#define DATUM_H

using namespace std;
#include <string>

class Datum {
    int _dan;
    string _mesec;
    int _godina;
public:
    Datum(int dan, string mesec, int godina);

    friend class Pacijent;
    friend class Doktor;
};

#endif
