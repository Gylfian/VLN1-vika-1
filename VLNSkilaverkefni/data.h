#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "computerscientist.h"



class Data
{
public:
    Data();
    void readFromFile(string docName, vector <CScientist>& scientists);
    void writeToFile(string docName, vector <CScientist>& scientists);
    friend ostream& operator <<(ostream& stream, const CScientist& scientist);
};

#endif // DATA_H
