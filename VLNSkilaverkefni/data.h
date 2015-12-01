#ifndef DATA_H
#define DATA_H
#include <fstream>
#include <vector>
#include "computerscientist.h"

class Data
{
public:
    Data();
    friend ostream& operator <<(ostream& stream, const CScientist& scientist);
    vector<CScientist> readFromFile(string docName);
    void writeToFile(string docName, vector <CScientist>& scientists);


};

#endif // DATA_H
