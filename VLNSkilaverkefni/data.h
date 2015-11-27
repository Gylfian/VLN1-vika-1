#ifndef DATA_H
#define DATA_H
#include "main.h"
#include "computerscientist.h"
#include "presentation.h"
#include "domain.h"
#include "data.h"


class Data
{
public:
    Data();
    void readFromFile(string docName, vector <CScientist>& scientists);
    void writeToFile(string docName, vector <CScientist>& scientists);
    ostream& operator <<(ostream& stream, const CScientist& scientist);
};

#endif // DATA_H
