#ifndef PRESENTATION_H
#define PRESENTATION_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "domain.h"

class Presentation
{
public:
    Presentation();
    void mainPage();
private:
    void addScientist();
    void options();
    bool another();
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
