#ifndef CSCIENTIST_H
#define CSCIENTIST_H

#include "main.h"

class CScientist
{
public:
    string getname();
    string getgender();
    int getDOB();
    int getDOD();
    void setname(string nametoset);
    void setgender(string gendertoset);
    void setDOB(int datetoset);
    void SetDOD(int datetoset);
    string name;
    string gender;
    int dateBorn;
    int dateDeath;

    CScientist();
private:

};

#endif // CSCIENTIST_H
