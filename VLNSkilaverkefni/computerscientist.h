#ifndef CSCIENTIST_H
#define CSCIENTIST_H
#include <string>
using namespace std;

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

    CScientist();
    CScientist(string cName, string cGender, string date1, string date2);
private:

};

#endif // CSCIENTIST_H
