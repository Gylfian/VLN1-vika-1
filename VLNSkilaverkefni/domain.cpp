#include "domain.h"

Domain::Domain()
{

}

vector<CScientist> Domain::sortByYear(bool byOldest, vector<CScientist> cSciList)
{
    vector<CScientist> sortedList = cSciList;
    if(byOldest)
    {

    }
    else
    {

    }
    return cSciList;
}


void Domain::sortByAlphabet(vector<CScientist> &cSciList, bool byAscending)
{
    int c = 0;
    int strVal = 0;
    int length = cSciList.size();
    while(c < length)
    {
        for(int i = 0; i < length; i++)
        {
            if(i + 1 < length)
                strVal = compareString(cSciList[i].name, cSciList[i+1].name);
            else
                break;

            if(strVal == 2)
            {
                swapValues(cSciList, i, i + 1);
            }
        }
        c++;
    }
    if(!byAscending)
    {
        reverseList(cSciList);
    }
}

void Domain::sortByGender(vector<CScientist> &cSciList, bool byMale, bool byAscending)
{
    vector<CScientist> tmp;
    vector<CScientist> tmp2;
    string searchWord;
    if(byMale)
    {
        searchWord = "Male";
    }
    else
    {
        searchWord = "Female";
    }

    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        if(cSciList[i].gender == searchWord)
        {
            tmp.push_back(cSciList[i]);
        }
        else
        {
            tmp2.push_back(cSciList[i]);
        }
    }

    if(byAscending)
    {
        sortByAlphabet(tmp, true);
        sortByAlphabet(tmp2, true);
    }
   mergeList(cSciList, tmp, tmp2);
}

void Domain::mergeList(vector<CScientist> &cSciList, vector<CScientist> vec1, vector<CScientist> vec2)
{
    cSciList.clear();
    for(unsigned int i = 0; i < vec1.size(); i++)
    {
        cSciList.push_back(vec1[i]);
    }
    for(unsigned int j = 0; j < vec2.size(); j++)
    {
        cSciList.push_back(vec2[j]);
    }
}


void Domain::reverseList(vector<CScientist> &cSciList)
{
    vector<CScientist> tmp = cSciList;
    cSciList.clear();
    for(int i = tmp.size()-1; i >= 0; i--)
    {
        cSciList.push_back(tmp[i]);
    }
}

int Domain::compareString(string str1, string str2)
{
    int strval1 = 0;
    int strval2 = 0;
    int cmp1length = str1.length();
    int cmp1length2 = str2.length();
    int lowerLength = min(cmp1length, cmp1length2);
    for(int i = 0; i < lowerLength; i++)
    {
        strval1 = decimalValue(str1[i]);
        strval2 = decimalValue(str2[i]);
        if(strval1 < strval2)
        {
            return 1;
        }
        else if(strval1 > strval2)
        {
            return 2;
        }
    }
    return 0;
}

void Domain::swapValues(vector<CScientist> &cSciList, int index1, int index2)
{
    CScientist tmpVal1 = cSciList[index1];
    CScientist tmpVal2 = cSciList[index2];
    cSciList[index1] = tmpVal2;
    cSciList[index2] = tmpVal1;
}

int Domain::decimalValue(char x)
{
    x = tolower(x);
    int d = x - '0';
    return d;
}

