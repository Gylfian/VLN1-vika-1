#ifndef DOMAIN_H
#define DOMAIN_H
#include <algorithm>
#include <sstream>
#include "data.h"
class Domain
{
public:
    Domain();

    /*
     * Name: getScientistList
     * Parameter/s: none
     * Description: Skilar lista af öllum scientists inn í skrá.
     * Usage: vector<CScientist> list = getScientistList()
     * (vector<CScientist>)Output/Return: list = allScientists
     */
    vector<CScientist> getScientistList();

    /*
     * Name: searchByName
     * Parameter/s: vector<CScientist> cSciList, string name
     * Description: Used to search in a list for persons by specific name.
     * Usage: vector<CScientist> vec = searchByName(cSciList, "Jón Baldursson"):
     * (vector<CScientist>)Output/Return: Retrieves everyone that is, in this case named "Jón Baldursson".
     */
    vector<CScientist> searchByName(vector<CScientist> cSciList, string name);

    /*
     * Name: searchByGender
     * Parameter/s: vector<CScientist> cSciList, string gender
     * Description: Used to search in a list for persons by specific gender.
     * Usage: vector<CScientist> vec = searchByGender(cSciList, "Male"):
     * (vector<CScientist>)Output/Return: Retrieves everyone that is male.
     */
    vector<CScientist> searchByGender(vector<CScientist> cSciList, string gender);

    /*
     * Name: searchByDateBorn
     * Parameter/s: vector<CScientist> cSciList, string dateBorn
     * Description: Used to search in a list by date of born.
     * Usage: vector<CScientist> vec = searchByDateBorn(cSciList, "1905"):
     * (vector<CScientist>)Output/Return: Retrieves everyone with specific born date, in this case 1905
     */
    vector<CScientist> searchByDateBorn(vector<CScientist> cSciList, string dateBorn);

    /*
     * Name: searchByDateDeath
     * Parameter/s: vector<CScientist> cSciList, int dateDeath
     * Description: Used to search in a list by date of death.
     * Usage: vector<CScientist> vec = searchByDateDeath(cSciList, "1905"):
     * (vector<CScientist>)Output/Return: Retrieves everyone with specific death date, in this case 1905
     */
    vector<CScientist> searchByDateDeath(vector<CScientist> cSciList, string dateDeath);
    void sortBy(vector<CScientist> &cSciList, char pChoice, char cChoice);
    void addToFile(vector<CScientist> &cSciList);
    vector<CScientist> readFile();

    /*
     * Name: deleteScientist
     * Parameter/s: vector<CScientist> &cSciList, int index
     * Description: Eyðir út ákveðnum aðila sem er stjórnað af indexi.
     * Usage: deleteScientist(cSciList, 5);
     * (vector<CScientist>)Output/Return: 5th element eytt út.
     */
    void deleteScientist(vector<CScientist> &cSciList, int index);

    /*
     * Name: normalizeName
     * Description: Notað til þess að laga nöfn sem eru illa eða rangt sett upp.
     * Usage: normalizeName("jÓn bAlduRSsOn")
     * (str)Output/Return: Jón Baldursson
     */
    bool normalizeName(string &name);

    /*
     * Name: sortByYear
     * Parameter/s: vector<CScientist> &cSciList, bool byOldest
     * Description: Sortar listann cSciList eftir fæðingarári
     * Usage: sortByYear(cSciList, true)
     * (void)Output/Return: Listi rearranged, cSciList raðast eftir fæðingarári
     */
    void sortByYear(vector<CScientist> &cSciList, bool byOldest);

    /*
     * Name: sortByGender
     * Parameter/s: vector<CScientist> &cSciList, bool byMale, bool byAscending
     * Description: Sortar listann cSciList eftir kyni, með stafrófsröð eða öfugri stafrófsröð.
     * Usage: sortByGender(cSciList, true, false)
     * (void)Output/Return: Listi rearranged, male koma first en í öfugri stafrófsröð
     */

    void sortByGender(vector<CScientist> &cSciList, bool byMale, bool byAscending);

    /*
     * Name: sortByAlphabet
     * Parameter/s: vector<CScientist> &cSciList, bool byAscending
     * Description: Sortar listann cSciList í stafrófsröð eða öfugri stafrófsröð
     * Usage: sortByAlphabet(cSciList, true)
     * (void)Output/Return: Listi rearranged, cSciList kemur í réttri stafrófsröð
     */
    void sortByAlphabet(vector<CScientist> &cSciList, bool byAscending);

private:
    vector<int> vecStrToInt(vector<CScientist> cSciList);

    /*
     * Name: decimalValue
     * Parameter/s: char chr
     * Description: Convertar char yfir í decimal ASCII gildi
     * Usage: decimalValue(a)
     * (int)Output/Return: 49
     */
    int  decimalValue(char x);

    /*
     * Name: compareString
     * Parameter/s: string str1, string str2
     * Description: Ber saman 2 strengi. Skilar 1 ef str1 er fyrr í stafróinu, skilar 2 ef str2 er fyrr í strafróinu. Skilar 0 ef það er jafnt.
     * Usage: compareString("Karl", "Andri")
     * (int)Output/Return: 2
     */
    int  compareString(string str1, string str2);

    /*
     * Name: compareYears
     * Parameter/s: int year1, int year2
     * Description: Ber saman 2 integera og skilar þeim minni
     * Usage: compareYears(2000, 1000)
     * (int)Output/Return: 1000
     */
    int  compareYears(int year1, int year2);

    /*
     * Name: normalizeList
     * Parameter/s: vector<CScientist>  &cSciList, vector<int> listYear
     * Description: cSciList er normalizaður frá integer vector yfir í CScientist.dateBorn format. Undir function fyrir sortByYear.
     * Usage: normalizeList(cSciList, listYear)
     * (void)Output/Return: Listi rearranged, cSciList er nú með rétt index miðað við listYear
     */
    void normalizeList(vector<CScientist>  &cSciList, vector<int> listYear);
    void reverseList(vector<CScientist> &cSciList);

    /*
     * Name: mergeList
     * Parameter/s: vector<CScientist> &cSciList, vector<CScientist> vec1, vector<CScientist> vec2
     * Description: Tekur 3 lista. Fyrsti (pass by reference) er aðal vectorinn og hinir 2 eru settir inn í hann.
     * Usage: compareString(mainList, templist, templist2)
     * (void)Output/Return: mainList = templist + templist2 || temp2list + templist
     */
    void mergeList(vector<CScientist> &cSciList, vector<CScientist> vec1, vector<CScientist> vec2);
    /*
     * Name: swapValues
     * Parameter/s: vector<CScientist> &cSciList, int index1, int index2
     * Description: Skiptir á values inn í CScientist vector. Hverju er skipt er stjórnað af 2 index breytum.
     * Usage: swapValues(vector, 0, 1)
     * (void)Output/Return: vector[(old)0] -> vector[1] && vector[(old)1] -> vector[0]
     */
    void swapValues(vector<CScientist> &cSciList, int index1, int index2);
    /*
     * Name: swapIntValues
     * Parameter/s: vector<int> &cSciList, int index1, int index2
     * Description: Skiptir á values inn í integer vector. Hverju er skipt er stjórnað af 2 index breytum.
     * Usage: swapIntValues(vector, 0, 1)
     * (void)Output/Return: vector[(old)0] -> vector[1] && vector[(old)1] -> vector[0]
     */
    void swapIntValues(vector<int> &cSciList, int index1, int index2);
};

#endif // DOMAIN_H
