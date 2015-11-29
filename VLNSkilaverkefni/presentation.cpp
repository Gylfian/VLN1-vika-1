#include "main.h"
#include "presentation.h"
#include <stdlib.h>

Presentation::Presentation() {}

void Presentation::mainPage()
{
    cout << "What do you want to do?" << endl;
    cout << "1) Add computer scientists to the list" << endl;
    cout << "2) See the list of computer scientists" << endl;
    cout << "Press any other key to quit" << endl;
    options();
}

void Presentation::options()
{
    char num;
    cin >> num;

    switch (num)
    {
        case ('1'):
            cout << "Flott hja ther" << endl;
            break;
        case ('2'):
            cout << "Dugleg/ur" << endl;
            break;
        default:
            exit (1);
    }
}

bool Presentation::another()
{
    char answer;
    cout << "Do you wish to add another person (y/n)" << endl;
    cin >> answer;

    switch (answer)
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
