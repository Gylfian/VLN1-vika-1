#ifndef DOMAIN_H
#define DOMAIN_H
#include "data.h"

<<<<<<< HEAD
=======
#include "computerscientist.h"
#include <string>
#include <vector>

>>>>>>> afd31be918322aafe4e466c49db8b71706cec942
class Domain
{
public:
    Domain();
    void sortByYear(vector<CScientist> &cSciList, bool byOldest);
    void sortByGender(vector<CScientist> &cSciList, bool byMale, bool byAscending);
    void sortByAlphabet(vector<CScientist> &cSciList, bool byAscending);
    bool normalizeName(string &name);
    void addToFile(CScientist sci);
private:
    int  decimalValue(char x);
    int  compareString(string str1, string str2);
    void reverseList(vector<CScientist> &cSciList);
    void mergeList(vector<CScientist> &cSciList, vector<CScientist> vec1, vector<CScientist> vec2);
    void swapValues(vector<CScientist> &cSciList, int index1, int index2);
};

#endif // DOMAIN_H
