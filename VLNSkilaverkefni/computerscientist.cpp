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
