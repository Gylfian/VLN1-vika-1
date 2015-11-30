#ifndef DOMAIN_H
#define DOMAIN_H
#include "data.h"
#include <algorithm>

class Domain
{
public:
    Domain();
    vector<CScientist> getScientistList();
    void sortByYear(vector<CScientist> &cSciList, bool byOldest);
    void sortByGender(vector<CScientist> &cSciList, bool byMale, bool byAscending);
    void sortByAlphabet(vector<CScientist> &cSciList, bool byAscending);
    void addToFile(vector<CScientist> &cSciList);
    void deleteScientist(vector<CScientist> &cSciList, int index);
    bool normalizeName(string &name);
private:
    int  decimalValue(char x);
    int  compareString(string str1, string str2);
    void reverseList(vector<CScientist> &cSciList);
    void mergeList(vector<CScientist> &cSciList, vector<CScientist> vec1, vector<CScientist> vec2);
    void swapValues(vector<CScientist> &cSciList, int index1, int index2);
};

#endif // DOMAIN_H
