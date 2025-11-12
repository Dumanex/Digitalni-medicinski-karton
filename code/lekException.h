#ifndef LEKEXCEPTION_H
#define LEKEXCEPTION_H

using namespace std;

#include <exception>
#include <string>

class lekException : public exception {
private:
    string poruka;
public:
    lekException(string imePacijenta, string nazivLeka) {
        poruka = "\n---------------------------------\n"
               "     GRESKA PRI DODAVANJU LEKA     \n"
               "---------------------------------\n"
               "Pacijent: " + imePacijenta + "\n"
               "Lek:      " + nazivLeka + "\n"
               "Poruka:   Lek nije odgovarajući za pacijenta.\n"
               "---------------------------------\n";
    }
    const char *what() const throw() override {
        return poruka.c_str();
    }
};
#endif

