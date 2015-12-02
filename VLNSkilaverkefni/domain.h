#ifndef DOMAIN_H
#define DOMAIN_H
#include <algorithm>
#include <sstream>
#include "data.h"
class Domain
{
public:

    /*
     * Name: Domain
     * Parameter/s: None
     * Description: Default constructor for Domain class
     * Usage:
     *
     */
    Domain();

    /*
     * Name: getScientistList
     * Parameter/s: none
     * Description: Returns a list of scientists from text file
     * Usage: vector<CScientist> list = getScientistList()
     * Output/Return: list = allScientists
     */
    vector<CScientist> getScientistList();

    /*
     * Name: search
     * Parameter/s: vector<CScientist> cSciList, char searchVal, string searchString
     * Description: Used to pick a search method
     * Usage: search(scientists, name, Charlie);
     * (vector<CScientist>)Output/Return: searches for the name Charlie in the vector scientists
     */
    vector<CScientist> search(vector<CScientist> cSciList, char searchVal, string searchString);

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

    /*
     * Name: sortBy
     * Parameter/s: vector<CScientist> &cSciList, int dateDeath
     * Description: Takes in choice of sorting method from user and salls appropriate sorting function
     * Usage: vector<CScientist> vec = searchByDateDeath(cSciList, "1905"):
     * (vector<CScientist>)Output/Return: Retrieves everyone with specific death date, in this case 1905
     */
    void sortBy(vector<CScientist> &cSciList, char pChoice, char cChoice);

    /*
     * Name: addToFile
     * Parameter/s: vector<CScientist> &cSciList
     * Description: Takes in choice of sorting method from user and salls appropriate sorting function
     * Usage: vector<CScientist> vec = searchByDateDeath(cSciList, "1905"):
     * (vector<CScientist>)Output/Return: Retrieves everyone with specific death date, in this case 1905
     */
    void addToFile(vector<CScientist> &cSciList);

    /*
     * Name: readFile
     * Parameter/s: None
     * Description: Takes in choice of sorting method from user and salls appropriate sorting function
     * Usage: vector<CScientist> vec = searchByDateDeath(cSciList, "1905"):
     * (vector<CScientist>)Output/Return: Retrieves everyone with specific death date, in this case 1905
     */
    vector<CScientist> readFile();

    /*
     * Name: deleteScientist
     * Parameter/s: vector<CScientist> &cSciList, int index
     * Description: Deletes a specific scientist from the list
     * Usage: deleteScientist(cSciList, 5);
     * (vector<CScientist>)Output/Return: 5th element deleted.
     */
    void Domain::deleteScientist(CScientist indexToDelete, vector<CScientist> &cSciList);


    /*
     * Name: normalizeName
     * Description: Fixes names that are badly input
     * Usage: normalizeName("jÓn bAlduRSsOn")
     * (str)Output/Return: Jón Baldursson
     */
    bool normalizeName(string &name);

private:

    /*
     * Name: sortByYear
     * Parameter/s: vector<CScientist> &cSciList, bool byOldest
     * Description: Sorts the list after birthyear
     * Usage: sortByYear(cSciList, true)
     * (void)Output/Return: List rearranged, cSciList sorted after birthyear
     */
    void sortByYear(vector<CScientist> &cSciList, bool byOldest);

    /*
     * Name: sortByGender
     * Parameter/s: vector<CScientist> &cSciList, bool byMale, bool byAscending
     * Description: Sorts the list cSciList by gender, in alphabetic- or reverse alpabetic order
     * Usage: sortByGender(cSciList, true, false)
     * (void)Output/Return: List rearranged, males come first in desending alphabetic order
     */
    void sortByGender(vector<CScientist> &cSciList, bool byMale, bool byAscending);

    /*
     * Name: sortByAlphabet
     * Parameter/s: vector<CScientist> &cSciList, bool byAscending
     * Description: Sorts the list cSciList in alphabetic- or reverse alpabetic order
     * Usage: sortByAlphabet(cSciList, true)
     * (void)Output/Return: List rearranged, cSciList comes in alphabetic order
     */
    void sortByAlphabet(vector<CScientist> &cSciList, bool byAscending);

    /*
     * Name: vecStrToInt
     * Parameter/s: vector<CScientist> cSciList
     * Description: Sorts the list cSciList in alphabetic- or reverse alpabetic order
     * Usage: sortByAlphabet(cSciList, true)
     * (void)Output/Return: List rearranged, cSciList comes in alphabetic order
     */
    vector<int> vecStrToInt(vector<CScientist> cSciList);

    /*
     * Name: decimalValue
     * Parameter/s: char chr
     * Description: Converts char to decimal ASCII values
     * Usage: decimalValue(a)
     * (int)Output/Return: 49
     */
    int  decimalValue(char x);

    /*
     * Name: compareString
     * Parameter/s: string str1, string str2
     * Description: Compares two strings. Returns 1 if str1 comes before str2 in the alphabet, returns 2 ef str2 comes before. Returns 0 if strings are equal.
     * Usage: compareString("Karl", "Andri")
     * (int)Output/Return: 2
     */
    int  compareString(string str1, string str2);

    /*
     * Name: compareYears
     * Parameter/s: int year1, int year2
     * Description: Compares two integers, returns smaller
     * Usage: compareYears(2000, 1000)
     * (int)Output/Return: 1000
     */
    int  compareYears(int year1, int year2);

    /*
     * Name: normalizeList
     * Parameter/s: vector<CScientist>  &cSciList, vector<int> listYear
     * Description: cSciList is normalized from integer to vector to CScientist.dateBorn format. Underfunction for sortByYear.
     * Usage: normalizeList(cSciList, listYear)
     * (void)Output/Return: Listi rearranged, cSciList is now right indexed in comparision to listYear
     */
    void normalizeList(vector<CScientist>  &cSciList, vector<int> listYear);


    /*
     * Name: reverseList
     * Parameter/s: vector<CScientist>  &cSciList, vector<int> listYear
     * Description: cSciList is normalized from integer to vector to CScientist.dateBorn format. Underfunction for sortByYear.
     * Usage: normalizeList(cSciList, listYear)
     * (void)Output/Return: Listi rearranged, cSciList is now right indexed in comparision to listYear
     */
    void reverseList(vector<CScientist> &cSciList);

    /*
     * Name: mergeList
     * Parameter/s: vector<CScientist> &cSciList, vector<CScientist> vec1, vector<CScientist> vec2
     * Description: Takes in three lists. First (pass by reference) is the main list and the other two lists are added to it
     * Usage: compareString(mainList, templist, templist2)
     * (void)Output/Return: mainList = templist + templist2 || temp2list + templist
     */
    void mergeList(vector<CScientist> &cSciList, vector<CScientist> vec1, vector<CScientist> vec2);
    /*
     * Name: swapValues
     * Parameter/s: vector<CScientist> &cSciList, int index1, int index2
     * Description: Swaps values in CScientist vector. What is swapped is is controlled by two index variables
     * Usage: swapValues(vector, 0, 1)
     * (void)Output/Return: vector[(old)0] -> vector[1] && vector[(old)1] -> vector[0]
     */

    void swapValues(vector<CScientist> &cSciList, int index1, int index2);
    /*
     * Name: swapIntValues
     * Parameter/s: vector<int> &cSciList, int index1, int index2
     * Description: Swaps values in an integer vector. What is swapped is is controlled by two index variables
     * Usage: swapIntValues(vector, 0, 1)
     * (void)Output/Return: vector[(old)0] -> vector[1] && vector[(old)1] -> vector[0]
     */
    void swapIntValues(vector<int> &cSciList, int index1, int index2);
};

#endif // DOMAIN_H
