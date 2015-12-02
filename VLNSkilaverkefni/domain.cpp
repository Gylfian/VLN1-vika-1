#include "domain.h"

Domain::Domain()
{

}

void Domain::sortBy(vector<CScientist> &cSciList, char pChoice, char cChoice)
{
    switch(pChoice)
    {
        case('1'):
            if(cChoice == '1')
            {
                sortByAlphabet(cSciList, true);
            }
            else
            {
                sortByAlphabet(cSciList, false);
            }
            break;
        case('2'):
            if(cChoice == '1')
            {
                sortByGender(cSciList, true, true);
            }
            else
            {
                sortByGender(cSciList, false, true);
            }
            break;
        case('3'):
            if(cChoice == '1')
            {
                sortByYear(cSciList, false);
            }
            else
            {
                sortByYear(cSciList, true);
            }
            break;

    }
}

vector<CScientist> Domain::search(vector<CScientist> cSciList, char searchVal, string searchString)
{
    vector<CScientist> searchResult;

    switch(searchVal)
    {
        case('1'):
            searchResult = searchByName(cSciList, searchString);
        break;

        case('2'):
            searchResult = searchByGender(cSciList, searchString);
        break;

        case('3'):
            searchResult = searchByDateBorn(cSciList, searchString);
        break;

        case('4'):
            searchResult = searchByDateDeath(cSciList, searchString);
        break;
    }

    return searchResult;
}

void Domain::sortByYear(vector<CScientist> &cSciList, bool byOldest)
{
    int origSwapCounter = 0, swapCounter = 0;
    vector<int> listYear;
    listYear.reserve(cSciList.size());
    listYear = vecStrToInt(cSciList);
    while(true)
    {
        origSwapCounter = swapCounter;
        for(unsigned int i = 0; i < listYear.size(); i++)
        {
            if(i+1 >= listYear.size())
                break;

            int older = compareYears(listYear[i], listYear[i+1]);
            if(older == listYear[i+1])
            {
                swapIntValues(listYear, i, i+1);
                swapCounter++;
            }
            else
            {
                continue;
            }
          }

        if(origSwapCounter == swapCounter)
            break;
    }
    normalizeList(cSciList, listYear);

    if(!byOldest)
    {
        reverseList(cSciList);
    }

}

void Domain::reverseList(vector<CScientist> &cSciList)
{
    vector<CScientist> tmp;
    tmp = cSciList;
    cSciList.clear();
    for(int i = tmp.size()-1; i >= 0; i--)
    {
        cSciList.push_back(tmp[i]);
    }
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
                strVal = compareString(cSciList[i].getName(), cSciList[i+1].getName()); //Fá streng sem er fyrr í stafrófi
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


vector<CScientist> Domain::searchByName(vector<CScientist> cSciList, string name)
{
    vector<CScientist> searchResults;
    for(unsigned int i = 0; i < cSciList.size(); i++)
    {       
        normalizeName(name);
        if (cSciList[i].getName().find(name) != std::string::npos)
        {
            searchResults.push_back(cSciList[i]);
        }
    }
    return searchResults;
}


vector<CScientist> Domain::searchByGender(vector<CScientist> cSciList, string gender)
{
    vector<CScientist> searchResults;
    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        if(cSciList[i].getGender() == gender)
        {
            searchResults.push_back(cSciList[i]);
        }
    }
    return searchResults;
}


vector<CScientist> Domain::searchByDateBorn(vector<CScientist> cSciList, string dateBorn)
{
    vector<CScientist> searchResults;
    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        if(cSciList[i].getDob() == dateBorn)
        {
            searchResults.push_back(cSciList[i]);
        }
    }
    return searchResults;
}


vector<CScientist> Domain::searchByDateDeath(vector<CScientist> cSciList, string dateDeath)
{
    vector<CScientist> searchResults;
    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        if(cSciList[i].getDod() == dateDeath)
        {
            searchResults.push_back(cSciList[i]);
        }
    }
    return searchResults;
}


void Domain::deleteScientist(CScientist indexToDelete, vector<CScientist> &cSciList)
{
    for(unsigned int j = 0; j < cSciList.size(); j++)
    {
        if(cSciList[j].getName() == indexToDelete.getName())
        {
            cSciList.erase(cSciList.begin()+j);
        }

    }
    Data data;
    data.writeToFile("scientists.txt", cSciList, true);
}


vector<CScientist> Domain::getScientistList()
{
    vector<CScientist> cSciList;
    //Ná í list frá Data
    return cSciList;
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
    size_t cmp1Length = str1.length(), cmp1Length2 = str2.length();  //Fá lengd af strengjum sem eru inní parametrum.
    size_t lowerLength = min(cmp1Length, cmp1Length2);               //lowerLength = minni talan af cmp1Length og cmp2Length
    for(unsigned int i = 0; i < lowerLength; i++)
    {
        //Convert char í ASCII decimal
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


int Domain::compareYears(int year1, int year2)
{
     if(year1 < year2)
        return year1;
     if(year2 < year1)
        return year2;

     return 0;
}


void Domain::swapValues(vector<CScientist> &cSciList, int index1, int index2)
{
    CScientist tmpVal1 = cSciList[index1];
    CScientist tmpVal2 = cSciList[index2];
    cSciList[index1] = tmpVal2;
    cSciList[index2] = tmpVal1;
}


void Domain::swapIntValues(vector<int> &cSciList, int index1, int index2)
{
    int tmpVal1 = cSciList[index1];
    int tmpVal2 = cSciList[index2];
    cSciList[index1] = tmpVal2;
    cSciList[index2] = tmpVal1;
}


int Domain::decimalValue(char chr)
{
    chr = tolower(chr);
    int decimal = chr - '0';
    return decimal;
}

vector<int> Domain::vecStrToInt(vector<CScientist> cSciList)
{
    vector<int> newVec;
    newVec.reserve(cSciList.size());
    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        string strnum = cSciList[i].getDob();
        int result = 0;
        stringstream convert(strnum);
        if ( !(convert >> result) )
            result = 0;

        newVec.push_back(result);
    }
    return newVec;
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

void Domain::normalizeList(vector<CScientist>  &cSciList, vector<int> listYear)
{
    for(unsigned int i = 0; i < listYear.size(); i++)
    {
        for(unsigned int j = 0; j < cSciList.size(); j++)
        {
            string strnum = cSciList[j].getDob();
            int result = 0;
            stringstream convert(strnum);
            if ( !(convert >> result) )
                result = 0;

            if(listYear[i] == result)
            {
                if(cSciList[i].getDob() != cSciList[j].getDob())
                {
                    swapValues(cSciList, i, j);
                }
            }
        }
    }
}



void Domain::addToFile(vector<CScientist> &cSciList)
{
    Data data;
    data.writeToFile("scientists.txt", cSciList, false);
}

vector<CScientist> Domain::readFile()
{
    Data data;
    vector<CScientist> vec = data.readFromFile("scientists.txt");
    return vec;
}
