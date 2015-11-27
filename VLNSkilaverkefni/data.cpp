#include "data.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "main.h"
#include "computerscientist.h"
#include "presentation.h"
#include "domain.h"
#include "data.h"

void Data::readFromFile(string docName, vector <CScientist> scientists)
{
    ifstream inStream;
    scientists temp;
    instream.open(docName.c_str());
    while(!inStream.eof())
    {
        inStream >> temp.name;
        inStream >> temp.gender;
        inStream >> temp.dateBorn;
        inStream >> temp.dateDeath;

        scientists.push_back(next);
    }
}

void Data::writeToFile(string docName, vector <CScientist> scientists)
{
    ofstream outStream;
    outStream.open(docName.c_str());

    for(unsigned int i = 0; i<scientists.size(); i++)
    {
        outStream << scientists[i];
    }
}

ostream& operator <<(ostream& stream, const CScientist& scientist)
{
    stream << scientist.name << " ";
    stream << scientist.gender << " ";
    stream << scientist.dateBorn << " ";
    stream << scientist.dateDeath << endl;
    return stream;
}
