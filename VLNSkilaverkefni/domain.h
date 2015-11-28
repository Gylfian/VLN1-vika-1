#ifndef DOMAIN_H
#define DOMAIN_H

#include "main.h"
#include "computerscientist.h"
class Domain
{
public:
    Domain(CScientist cSci);
    vector<CScientist> sortByYear(bool byOldest, vector<CScientist> cSciList);
    void sortByAlphabet(vector<CScientist> &cSciList, bool byAscending);
};

#endif // DOMAIN_H
