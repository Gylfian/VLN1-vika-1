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
    CScientist();
private:
    string name;
    string gender;
    int dateBorn;
    int dateDeath;

};

#endif // CSCIENTIST_H
