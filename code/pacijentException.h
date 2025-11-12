#ifndef PACIJENTEXCEPTION_H
#define PACIJENTEXCEPTION_H

using namespace std;

#include <exception>

class pacijentException : public exception {
public:
    const char *what() const throw() override {
        return "\n---------------------------------\n"
               "     GRESKA PRI IZBORU DOKTORA     \n"
               "---------------------------------\n"
               "Poruka:   Izabrani pacijent ne postoji.\n"
               "---------------------------------\n";
    }
};

#endif

