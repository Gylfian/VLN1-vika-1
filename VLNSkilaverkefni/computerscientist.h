#ifndef CSCIENTIST_H
#define CSCIENTIST_H

<<<<<<< HEAD
#include "data.h"
=======
#include <iostream>


using namespace std;
>>>>>>> afd31be918322aafe4e466c49db8b71706cec942

class CScientist
{
public:
    string getName() const;
    string getGender() const;
    string getDob() const;
    string getDod() const;
    void setName(string nameToSet);
    void setGender(string genderToSet);
    void setDob(string dateToSet);
    void SetDod(string dateToSet);
    string name;
    string gender;
    string dateBorn;
    string dateDeath;
    friend istream & operator >> (istream & input, CScientist & c1);
    friend ostream & operator << (ostream & output, const CScientist & c1);
    string getinputName(istream & input);
    string getinputGender(istream & input);
    string getinputDob(istream & input);
    string getinputDod(istream & input);

    CScientist();
private:

};

#endif // CSCIENTIST_H
