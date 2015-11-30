#ifndef DATA_H
#define DATA_H
#include "computerscientist.h"
#include <fstream>
#include <vector>
using namespace std;




class Data
{
public:
    Data();
    void readFromFile(string docName, vector <CScientist>& scientists);
    void writeToFile(string docName, vector <CScientist>& scientists);
    friend ostream& operator <<(ostream& stream, const CScientist& scientist);
};

#endif // DATA_H
