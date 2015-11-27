#include "computerscientist.h"

CScientist::CScientist()
{
    name = "";
    gender ="";
    dateBorn =0;
    dateDeath =0;
}

string CScientist::getname(){
    return name;
}

string CScientist::getgender(){
   return gender;
}


int CScientist::getDOB(){
   return dateBorn;
}

int CScientist::getDOD(){
   return dateDeath;
}

void CScientist::setname(string nametoset){
    name=nametoset;
}

void CScientist::setgender(string gendertoset){
    gender=gendertoset;
}
void CScientist::setDOB(int datetoset){
    dateBorn=datetoset;
}
void CScientist::SetDOD(int datetoset){
    dateDeath=datetoset;
}
