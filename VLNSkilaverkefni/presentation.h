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
    void getAns();
    void addScientist();
    void options();
    bool another();
    void listOptions();
    void displayListOptions();
    void alphaAscendingDecending();
    void genderOrder();
    void ascendingDecendingText();
    void scientistData(CScientist &cSci);
    string getInputGender();
    string getInputName();
    string getInputDob();
    string getInputDod();
    void printList(vector <CScientist> scientists);


};

#endif // PRESENTATION_H
