#include "computerscientist.h"

CScientist::CScientist()
{
    name = "";
    gender ="";
    dateBorn =0;
    dateDeath =0;
}

string CScientist::getName(){
    return name;
}

string CScientist::getGender(){
   return gender;
}


int CScientist::getDob(){
   return dateBorn;
}

int CScientist::getDod(){
   return dateDeath;
}

void CScientist::setName(string nameToSet){
    name=nameToSet;
}

void CScientist::setGender(string genderToSet){
    gender=genderToSet;
}
void CScientist::setDob(int dateToSet){
    dateBorn=dateToSet;
}
void CScientist::SetDod(int dateToSet){
    dateDeath=dateToSet;
}

istream & operator >> (istream & input, CScientist & c1){

    cout << "Enter name: ";
    input >> c1.name;
    cout << "Enter gender: ";
    input >> c1.gender;
    cout << "Enter Date of birth: ";
    input >> c1.dateBorn;
    cout << "Enter Date of death: ";
    input >> c1.dateDeath;
    return input;
}

ostream & operator << (ostream & output, const CScientist & c1){
    cout << "Name: " << c1.name << endl;
    cout << "gender: " << c1.gender << endl;
    cout << "Date of birth: " << c1.dateBorn << endl;
    cout << "Date of death: " << c1.dateDeath << endl;

    return output;
}
