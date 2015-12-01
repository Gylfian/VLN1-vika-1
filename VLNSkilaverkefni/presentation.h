#ifndef PRESENTATION_H
#define PRESENTATION_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "domain.h"

class Presentation
{
public:

    /*
     * Name: mainPage
     * Parameter/s: None
     * Description: Displays menu of options for the user to opick from and calls another function which gets choice form user
     * Usage: Promts user with two options, Add computer scientists to the list or See the list of computer scientists
     * (int)Output/Return: None
     */
    void mainPage();

private:

    /*
     * Name: addScientist
     * Parameter/s: None
     * Description: Adds scientists to a vector
     * Usage: scientistData(cSci); scientists.push_back(cSci);
     * (int)Output/Return: cSci is now an element inn the vector scientists
     */
    void addScientist();

    /*
     * Name: options
     * Parameter/s: None
     * Description: Calls the function getch() that gets choice from user and calls appropriate function for choice
     * Usage: getch() function returns 1
     * (int)Output/Return: The function calls a function the adds scientists to the list
     */
    void options();

    /*
     * Name: another
     * Parameter/s: None
     * Description: Calls a function that gets choice from user and returns true if he chooses to add another scientist, false otherwise
     * Usage: getch() function returns y
     * (int)Output/Return: The function true
     */
    bool another();

    /*
     * Name: listOptions
     * Parameter/s: None
     * Description: Calls the function getch() that gets choice from user and calls appropriate function for choice
     * Usage: getch() function returns 1
     * (int)Output/Return: The function calls a function the adds scientists to the list
     */
    void listOptions();
    void whichOrder(char pChoice);
    void scientistData(CScientist& cSci);
    string getInputGender();
    string getInputName();
    string getInputDob();
    string getInputDod();
    void printList(vector <CScientist> scientists);
    void printListOptions();
    void searchOptions();
    string getNameSearch();
    string getGenderSearch();
    string getYearSearch();
    void anotherText();
    void listOptionsText();
    void genderOrderText();
    void yearBornText();
    void ascendingDecendingText();

};

#endif // PRESENTATION_H
