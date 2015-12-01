#include "computerscientist.h"


CScientist::CScientist()
{
    name = "";
    gender ="";
    dateBorn = "";
    dateDeath = "";
}
/*
 * Name: getName
 * Parameter/s: none
 * Description: skilar nafni tölvunarfræðings
 * Usage: getName()
 * (string)Output/Return: Strengurinn sem er inn í meðlimabreytunni name í klasanum
 */
string CScientist::getName() const{
    return name;
}
/*
 * Name: getGender
 * Parameter/s: none
 * Description: skilar kyni tölvunarfræðings
 * Usage: getGender()
 * (string)Output/Return: Strengurinn sem er inn í meðlimabreytunni gender í klasanum
 */
string CScientist::getGender() const{
   return gender;
}
/*
 * Name: getDob
 * Parameter/s: none
 * Description: skilar fæðingarári tölvunarfræðings
 * Usage: getDob()
 * (string)Output/Return: Strengurinn sem er inn í meðlimabreytunni dateBorn í klasanum
 */
string CScientist::getDob() const{
   return dateBorn;
}
/*
 * Name: getDod
 * Parameter/s: none
 * Description: skilar dánarári tölvunarfræðings
 * Usage: getName()
 * (string)Output/Return: Strengurinn sem er inn í meðlimabreytunni dateDeath í klasanum
 */
string CScientist::getDod() const{
   return dateDeath;
}
/*
 * Name: setName
 * Parameter/s: string nameToSet
 * Description: Breytir nafni tölvunarfræðings
 * Usage: setName(string)
 * (string)Output/Return: Meðlimabreytunni name breytt
 */
void CScientist::setName(string nameToSet){
    name=nameToSet;
}
/*
 * Name: setGender
 * Parameter/s: string genderToSet
 * Description: Breytir kyni tölvunarfræðings
 * Usage: setGender(string)
 * (string)Output/Return: Meðlimabreytunni gender breytt
 */
void CScientist::setGender(string genderToSet){
    gender=genderToSet;
}
/*
 * Name: setDob
 * Parameter/s: string dateToSet
 * Description: Breytir fæðingarári tölvunarfræðings
 * Usage: setDob(string)
 * (string)Output/Return: Meðlimabreytunni dateBorn breytt
 */
void CScientist::setDob(string dateToSet){
    dateBorn=dateToSet;
}
/*
 * Name: setDod
 * Parameter/s: string dateToSet
 * Description: Breytir dánarári tölvunarfræðings
 * Usage: setDob(string)
 * (string)Output/Return: Meðlimabreytunni dateDeath breytt
 */
void CScientist::SetDod(string dateToSet){
    dateDeath=dateToSet;
}
