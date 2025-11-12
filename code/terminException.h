#ifndef TERMINEXCEPTION_H
#define TERMINEXCEPTION_H

using namespace std;

#include <exception>

class terminException : public exception {
public:
    const char *what() const throw() override {
        return "\n---------------------------------\n"
               "    GRESKA PRI ZAKAZIVANJU TERMINA   \n"
               "---------------------------------\n"
               "Poruka:   Izabrani termin nije dostupan.\n"
               "---------------------------------\n";
    }
};
#endif

