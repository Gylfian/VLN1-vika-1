#include "domain.h"
#include "data.h"

Domain::Domain()
{

}

void Domain::sortByYear(vector<CScientist> &cSciList, bool byOldest)
{

}


void Domain::sortByAlphabet(vector<CScientist> &cSciList, bool byAscending)
{
    int origSwapCounter = 0, swapCounter = 0, strVal = 0, searchValue = 2;
    if(!byAscending)
    {
        searchValue = 1;
    }
    while(true)
    {
        origSwapCounter = swapCounter;
        for(unsigned int i = 0; i < cSciList.size(); i++)
        {
            if(i + 1 < cSciList.size())
                strVal = compareString(cSciList[i].getName(), cSciList[i+1].getName());
            else
                break;

            if(strVal == searchValue)
            {
                swapValues(cSciList, i, i + 1);
                swapCounter++;
            }
        }
        if(origSwapCounter == swapCounter)
            break;
    }
}

void Domain::sortByGender(vector<CScientist> &cSciList, bool byMale, bool byAscending)
{
    vector<CScientist> tmp, tmp2;
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
        if(cSciList[i].getGender() == searchWord)
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
    else
    {
        sortByAlphabet(tmp, false);
        sortByAlphabet(tmp2, false);
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

int Domain::compareString(string str1, string str2)
{
    int strVal1 = 0, strVal2 = 0;
    size_t cmp1Length = str1.length(), cmp1Length2 = str2.length();
    size_t lowerLength = min(cmp1Length, cmp1Length2);
    for(unsigned int i = 0; i < lowerLength; i++)
    {
        strVal1 = decimalValue(str1[i]);
        strVal2 = decimalValue(str2[i]);
        if(strVal1 < strVal2)
        {
            return 1;
        }
        else if(strVal1 > strVal2)
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

int Domain::decimalValue(char chr)
{
    chr = tolower(chr);
    int decimal = chr - '0';
    return decimal;
}


bool Domain::normalizeName(string &name)
{
    if(name.length() <= 0)
    {
        return false;
    }

    for(unsigned int i = 0; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }
    name[0] = toupper(name[0]);
    for(unsigned int j = 0; j < name.length(); j++)
    {
        if(name[j] == ' ')
        {
            if(name[j+1] != ' ')
            {
               name[j+1] = toupper(name[j+1]);
            }
        }
    }
    return true;
}
/*
void Domain::addToFile(vector<CScientist> &cSciList)
{
    Data data;
    data.writeToFile("scientists.txt", cSciList);

}
*/
