#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "computerscientist.h"

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
    void scientistData(CScientist cSci);
    string getInputGender();
    string getInputName();
    string getInputDob();
    string getInputDod();


};

#endif // PRESENTATION_H
