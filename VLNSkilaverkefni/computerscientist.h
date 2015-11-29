#ifndef CSCIENTIST_H
#define CSCIENTIST_H

#include "main.h"

class CScientist
{
public:
    string getName();
    string getGender();
    int getDob();
    int getDod();
    void setName(string nameToSet);
    void setGender(string genderToSet);
    void setDob(int dateToSet);
    void SetDod(int dateToSet);
    string name;
    string gender;
    int dateBorn;
    int dateDeath;
    friend istream & operator >> (istream & input, CScientist & c1);
    friend ostream & operator << (ostream & output, const CScientist & c1);
    string getinputName(istream & input);
    string getinputGender(istream & input);
    int getinputDob(istream & input);
    int getinputDod(istream & input);

    CScientist();
private:

};

#endif // CSCIENTIST_H
