#ifndef CSCIENTIST_H
#define CSCIENTIST_H
#include <string>
using namespace std;

class CScientist
{
public:

    /*
     * Name: getName
     * Parameter/s: None
     * Description: Returns name of the scientist
     * Usage: cout << scientist.getName();
     * (int)Output/Return: The scientist name is written out to console
     */
    string getName() const;

    /*
     * Name: getGender
     * Parameter/s: None
     * Description: Returns gender of the scientist
     * Usage: cout << scientist.getGender();
     * (int)Output/Return: The scientist gender is written out to console
     */
    string getGender() const;

    /*
     * Name: getDob
     * Parameter/s: None
     * Description: Returns bith year of the scientist
     * Usage: cout << scientist.getDob();
     * (int)Output/Return: The scientist bith year is written out to console
     */

    string getDob() const;

    /*
     * Name: getDod
     * Parameter/s: None
     * Description: Returns the scientists' year of death
     * Usage: cout << scientist.getDod();
     * (int)Output/Return: The scientist death year is written out to console
     */
    string getDod() const;

    /*
     * Name: setName
     * Parameter/s: string nameToSet
     * Description: Sets the parameter nameToSet as the scientists' name
     * Usage: scientist1.setName(Charlie Brown)
     * (int)Output/Return: The scientist name is now Charlie
     */
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
