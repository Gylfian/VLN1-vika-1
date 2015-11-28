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
            else
            {
                c++;
            }
        }
    }
    if(!byAscending)
    {
        reverseList(cSciList);
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
            break;
        }
        else if(strval1 == strval2)
        {
            continue;
        }
        else
        {
            return 2;
            break;
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

