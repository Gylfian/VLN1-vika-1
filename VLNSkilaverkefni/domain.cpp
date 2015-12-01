#include "domain.h"

Domain::Domain()
{

}

/*
 * Name: sortByYear
 * Parameter/s: vector<CScientist> &cSciList, bool byOldest
 * Description: Sortar listann cSciList eftir fæðingarári
 * Usage: sortByYear(cSciList, true)
 * (void)Output/Return: Listi rearranged, cSciList raðast eftir fæðingarári
 */
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
            if(byOldest)
            {
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
            else
            {
                if(older != listYear[i+1])
                {
                    swapIntValues(listYear, i, i+1);
                    swapCounter++;
                }
                else
                {
                    continue;
                }
            }
        }
        if(origSwapCounter == swapCounter)
            break;
    }
    normalizeList(cSciList, listYear);
}

/*
 * Name: sortByAlphabet
 * Parameter/s: vector<CScientist> &cSciList, bool byAscending
 * Description: Sortar listann cSciList í stafrófsröð eða öfugri stafrófsröð
 * Usage: sortByAlphabet(cSciList, true)
 * (void)Output/Return: Listi rearranged, cSciList kemur í réttri stafrófsröð
 */
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

/*
 * Name: sortByGender
 * Parameter/s: vector<CScientist> &cSciList, bool byMale, bool byAscending
 * Description: Sortar listann cSciList eftir kyni, með stafrófsröð eða öfugri stafrófsröð.
 * Usage: sortByGender(cSciList, true, false)
 * (void)Output/Return: Listi rearranged, male koma first en í öfugri stafrófsröð
 */
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

/*
 * Name: deleteScientist
 * Parameter/s: vector<CScientist> &cSciList, int index
 * Description: Eyðir út ákveðnum aðila sem er stjórnað af indexi.
 * Usage: deleteScientist(cSciList, 5);
 * (vector<CScientist>)Output/Return: 5th element eytt út.
 */
void Domain::deleteScientist(vector<CScientist> &cSciList, int index)
{
    cSciList.erase(cSciList.begin()+index); //.begin == index[0]
}

/*
 * Name: getScientistList
 * Parameter/s: none
 * Description: Skilar lista af öllum scientists inn í skrá.
 * Usage: vector<CScientist> list = getScientistList()
 * (vector<CScientist>)Output/Return: list = allScientists
 */
vector<CScientist> Domain::getScientistList()
{
    vector<CScientist> cSciList;
    //Ná í list frá Data
    return cSciList;
}

/*
 * Name: mergeList
 * Parameter/s: vector<CScientist> &cSciList, vector<CScientist> vec1, vector<CScientist> vec2
 * Description: Tekur 3 lista. Fyrsti (pass by reference) er aðal vectorinn og hinir 2 eru settir inn í hann.
 * Usage: compareString(mainList, templist, templist2)
 * (void)Output/Return: mainList = templist + templist2 || temp2list + templist
 */
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

/*
 * Name: compareString
 * Parameter/s: string str1, string str2
 * Description: Ber saman 2 strengi. Skilar 1 ef str1 er fyrr í stafróinu, skilar 2 ef str2 er fyrr í strafróinu. Skilar 0 ef það er jafnt.
 * Usage: compareString("Karl", "Andri")
 * (int)Output/Return: 2
 */
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

/*
 * Name: compareYears
 * Parameter/s: int year1, int year2
 * Description: Ber saman 2 integera og skilar þeim minni
 * Usage: compareYears(2000, 1000)
 * (int)Output/Return: 1000
 */
int Domain::compareYears(int year1, int year2)
{
     if(year1 < year2)
        return year1;
     if(year2 < year1)
        return year2;

     return 0;
}

/*
 * Name: swapValues
 * Parameter/s: vector<CScientist> &cSciList, int index1, int index2
 * Description: Skiptir á values inn í CScientist vector. Hverju er skipt er stjórnað af 2 index breytum.
 * Usage: swapValues(vector, 0, 1)
 * (void)Output/Return: vector[(old)0] -> vector[1] && vector[(old)1] -> vector[0]
 */
void Domain::swapValues(vector<CScientist> &cSciList, int index1, int index2)
{
    CScientist tmpVal1 = cSciList[index1];
    CScientist tmpVal2 = cSciList[index2];
    cSciList[index1] = tmpVal2;
    cSciList[index2] = tmpVal1;
}

/*
 * Name: swapIntValues
 * Parameter/s: vector<int> &cSciList, int index1, int index2
 * Description: Skiptir á values inn í integer vector. Hverju er skipt er stjórnað af 2 index breytum.
 * Usage: swapIntValues(vector, 0, 1)
 * (void)Output/Return: vector[(old)0] -> vector[1] && vector[(old)1] -> vector[0]
 */
void Domain::swapIntValues(vector<int> &cSciList, int index1, int index2)
{
    int tmpVal1 = cSciList[index1];
    int tmpVal2 = cSciList[index2];
    cSciList[index1] = tmpVal2;
    cSciList[index2] = tmpVal1;
}

/*
 * Name: decimalValue
 * Parameter/s: char chr
 * Description: Convertar char yfir í decimal ASCII gildi
 * Usage: decimalValue(a)
 * (int)Output/Return: 49
 */
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

/*
 * Name: normalizeName
 * Description: Notað til þess að laga nöfn sem eru illa eða rangt sett upp.
 * Usage: normalizeName("jÓn bAlduRSsOn")
 * (str)Output/Return: Jón Baldursson
 */
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
 * Name: normalizeList
 * Parameter/s: vector<CScientist>  &cSciList, vector<int> listYear
 * Description: cSciList er normalizaður frá integer vector yfir í CScientist.dateBorn format. Undir function fyrir sortByYear.
 * Usage: normalizeList(cSciList, listYear)
 * (void)Output/Return: Listi rearranged, cSciList er nú með rétt index miðað við listYear
 */
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
    data.writeToFile("scientists.txt", cSciList);
}

