#include "main.h"
#include "presentation.h"
#include <stdlib.h>
#include <conio.h>

Presentation::Presentation() {}

void Presentation::mainPage()
{
    cout << " ________________________________________" << endl;
    cout << "|---------What do you want to do?--------|" << endl;
    cout << "| 1) Add computer scientists to the list |" << endl;
    cout << "| 2) See the list of computer scientists |" << endl;
    cout << "| ------Press any other key to quit----- |" << endl;
    cout << "|________________________________________|" << endl;
    options();
}

void Presentation::options()
{
    char ans = getch();
    system("CLS");

    switch (ans)
    {
        case ('1'):
            cout << "Flott hja ther" << endl;
            break;
        case ('2'):
            {
                displayListOptions();
            }
            break;
        default:
            exit (1);
    }
}

bool Presentation::another()
{

    cout << "Do you wish to add another person (y/n) ";
    char ans = getch();

    switch (ans)
    {
        case ('Y'):
        case ('y'):
            return true;
            break;
        case ('N'):
        case ('n'):
            return false;
            break;
        default:
            return false;
    }
}

void Presentation::displayListOptions()
{
    cout << "How do you want the list displayed? " << endl;
    cout << "1) Alphabetically" << endl;
    cout << "2) By gender" << endl;
    cout << "3) By year of birth" << endl;
    cout << "4) By year of death" << endl;
    cout << "Press any other key to go back" << endl;
    listOptions();

}

void Presentation::listOptions()
{
    char ans = getch();
    system("CLS");

    switch(ans)
    {
        case('1'):
        {

        }
        break;
        case ('2'):
        {

        }
        break;
        case ('3'):
        {

        }
        break;
        case ('4'):
        {

        }
        default:
            mainPage();

    }
}

bool Presentation::ascendingDecending()
{
    cout << "In what alphabetical order do you want the list?" << endl;
    cout << "1) Ascending" << endl;
    cout << "2) Decending" << endl;

}
