#ifndef DOMAIN_H
#define DOMAIN_H
#include <string>
#include <vector>
#include <algorithm>
#include "data.h"
#include "computerscientist.h"

class Domain
{
public:
    Domain();
    void sortByYear(vector<CScientist> &cSciList, bool byOldest);
    void sortByGender(vector<CScientist> &cSciList, bool byMale, bool byAscending);
    void sortByAlphabet(vector<CScientist> &cSciList, bool byAscending);
    bool normalizeName(string &name);
    void addToFile(vector<CScientist> &cSciList);
private:
    int  decimalValue(char x);
    int  compareString(string str1, string str2);
    void reverseList(vector<CScientist> &cSciList);
    void mergeList(vector<CScientist> &cSciList, vector<CScientist> vec1, vector<CScientist> vec2);
    void swapValues(vector<CScientist> &cSciList, int index1, int index2);
};

#endif // DOMAIN_H
