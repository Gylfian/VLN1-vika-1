#ifndef DOMAIN_H
#define DOMAIN_H

#include "main.h"
#include "computerscientist.h"
class Domain
{
public:
    Domain(CScientist cSci);
    vector<CScientist> sortByYear(bool byOldest, vector<CScientist> cSciList);
    vector<CScientist> sortByAlphabet(bool byAscending);
};

#endif // DOMAIN_H
