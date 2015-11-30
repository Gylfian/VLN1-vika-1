#include "computerscientist.h"


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
