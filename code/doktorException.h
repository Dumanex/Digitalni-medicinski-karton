#ifndef DOKTOREXCEPTION_H
#define DOKTOREXCEPTION_H

using namespace std;

#include <exception>

class doktorException : public exception {
public:
    const char *what() const throw() override {
        return "\n---------------------------------\n"
               "     GRESKA PRI IZBORU DOKTORA     \n"
               "---------------------------------\n"
               "Poruka:   Izabrani doktor ne postoji.\n"
               "---------------------------------\n";
    }
};

#endif

