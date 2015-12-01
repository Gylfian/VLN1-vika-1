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
    void alphaAscendingDecending();
    void genderOrder();
    void ascendingDecendingText();
    void scientistData(CScientist& cSci);
    string getInputGender();
    string getInputName();
    string getInputDob();
    string getInputDod();
    void printList(vector <CScientist> scientists);
    void printListOptions();
    void searchOptions();
    void anotherText();
    void listOptionsText();
    void genderOrderText();



};

#endif // PRESENTATION_H
