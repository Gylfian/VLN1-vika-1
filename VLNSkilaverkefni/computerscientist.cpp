#include "computerscientist.h"
#include "domain.h"
CScientist::CScientist()
{
    name = "";
    gender ="";
    dateBorn = "";
    dateDeath = "";
}

string CScientist::getName() const{
    return name;
}

string CScientist::getGender() const{
   return gender;
}


string CScientist::getDob() const{
   return dateBorn;
}

string CScientist::getDod() const{
   return dateDeath;
}

void CScientist::setName(string nameToSet){
    name=nameToSet;
}

void CScientist::setGender(string genderToSet){
    gender=genderToSet;
}
void CScientist::setDob(string dateToSet){
    dateBorn=dateToSet;
}
void CScientist::SetDod(string dateToSet){
    dateDeath=dateToSet;
}

istream & operator >> (istream & input, CScientist & c1){

    string enteredName = c1.getinputName(input);
    c1.name=enteredName;
    string enteredGender = c1.getinputGender(input);
    c1.gender=enteredGender;
    string enteredDob = c1.getinputDob(input);
    c1.dateBorn=enteredDob;
    string enteredDod = c1.getinputDod(input);
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
cout << "Is the scientist [m]ale or [f]emale ? " << endl;
char ans = getch();
    switch (ans)
    {
        case ('M'):
        case ('m'):
        {
        gender = "Male";
        }break;
        case ('F'):
        case ('f'):
        {
        gender = "Female";
        }break;
    default:{
        cout << "Please select either male or female"<<endl;
        this->getinputGender(input);
    }


}
    cout << gender<<" selected"<< endl;
    return gender;
}
string CScientist::getinputDob(istream & input){
string Dob;
cout << "Enter year of birth: ";
input >> Dob;
return Dob;
}
string CScientist::getinputDod(istream & input){
string Dod;
cout << "Enter year of death: ";
input >> Dod;
return Dod;
}
