#include "computerscientist.h"
#include "domain.h"
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

    string enteredName = c1.getinputName(input);
    c1.name=enteredName;
    string enteredGender = c1.getinputGender(input);
    c1.gender=enteredGender;
    int enteredDob = c1.getinputDob(input);
    c1.dateBorn=enteredDob;
    int enteredDod = c1.getinputDod(input);
    c1.dateDeath=enteredDod;
    return input;
}

ostream & operator << (ostream & output, const CScientist & c1){
    cout << "Name: " << c1.name << endl;
    cout << "gender: " << c1.gender << endl;
    cout << "year of birth: " << c1.dateBorn << endl;
    cout << "year of death: " << c1.dateDeath << endl;

    return output;
}

string CScientist::getinputName(istream & input){
string name;
Domain d1;
bool namecheck=false;
cout << "Enter name: ";
    while(namecheck==false){
    getline(input,name);
    namecheck = d1.normalizeName(name);
        if(namecheck==true){
        return name;
        }
        else{
        cout << "Please enter a valid name: ";
        }
    }
return name;
}
string CScientist::getinputGender(istream & input){
string gender;
cout << "Enter gender: ";
input >> gender;
return gender;
}
int CScientist::getinputDob(istream & input){
int Dob;
cout << "Enter year of birth: ";
input >> Dob;
return Dob;
}
int CScientist::getinputDod(istream & input){
int Dod;
cout << "Enter year of death: ";
input >> Dod;
return Dod;
}
