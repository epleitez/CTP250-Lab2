/** @author Emely Pleitez
 * @file tag "companiesMarketCap.csv"
 *
 * A recursive function that determines if string has an equal number of
 * < and > characters
 *
 * Class defined Company, class defines attributes for the name of company,
 * trading symbol, market cap value, the county, type of company, and
 * rank. various methods written in order to read and sort the data in class Company
*/

#include <iostream>
#include <string>
#include "Company.h"
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>


string getInputAndCheck();
//builds the vector
void readFile(vector<Company> &);
void displayAll(vector<Company>);
void getRange(vector<Company>);
void getWealthiest(vector<Company>);
void getUS(vector<Company>);


using namespace std;

int main() {

    //getInputAndCheck();

    vector<Company> companies;
    readFile(companies);
    displayAll(companies);
    getRange(companies);
    getWealthiest(companies);
    getUS(companies);

    return 0;
}

/* Prompts user for a string, reads string, and outputs the string entered and
 * if the string includes an equal number of the characters "<" ">"
 */
string getInputAndCheck() {

    string str;
    char x = '<';
    char y = '>';
    // bool found = false;
    int countX = 0;
    int countY = 0;


    cout << "Enter string here: ";
    getline(cin, str);
    cout << "You entered: " << str << endl;

    for (int i = 0; i < str.size(); i ++){
        if (str.at(i) == x)
            countX++;
        else if (str.at(i) == y)
            countY++;
    }

    if (countX == countY)
        cout << "Equal number of < and > characters" << endl;
    else
        cout << "Not equal number of < and > characters" << endl;

    //substring

}

/* data is read from the file "companiesMarketCap.txt"
 * an object is created for each line in data file
 * @param vector<Company> &companies is the vector in which the objects created are placed in
 */
void readFile(vector<Company> &companies){
    ifstream infile;
    infile.open("companiesMarketCap.txt");

    string line = "";

    if(!infile.is_open()){
        cout << "File not open... program terminating" << endl;
        exit(0);
    }

    while(getline(infile, line)) {

        Company c(line);

        companies.push_back(c);
    }
    infile.close();
}//end readFile

/* displays all the objects in the vector companies
 * @param vector<Company> companies is the vector in which objects are stored.
 */
void displayAll(vector<Company> companies){
    for (auto c: companies) {
        cout << c.toString();
    }
}//end displayAll()

/* gets the range of the market cap value by reading each market cap value in each object and comparing
 * outputs the largest and smallest market cap value
 * @param vector<Company> companies is the vector in which objects are stored.
*/
void getRange(vector<Company> companies){
    int highest = 0;
    int lowest = 0;

    for (auto c: companies) {
        if (c.getMarketCapValue() > highest) {
            highest = c.getMarketCapValue();
        }
    }
    cout << "Largest Market Cap Value: " << highest << endl;

    for (auto c: companies) {
        lowest = c.getMarketCapValue();
        if (c.getMarketCapValue() < lowest) {
            lowest = c.getMarketCapValue();
        }
    }
    cout << "Smallest Market Cap Value: " << lowest << endl;

}//end getRange()

/*gets the highest market cap value reading each market cap value in each object and comparing
 * outputs the object with the highest market cap value
 * @param vector<Company> companies is the vector in which objects are stored.
*/
void getWealthiest(vector<Company> companies){
    int highest = 0;
    int position = 0;

    for (auto c: companies) {
        if (c.getMarketCapValue() > highest) {
            highest = c.getMarketCapValue();
            position++;
        }
    }
}//end getWealthiest()

/*returns a count of the number of company objects that are in the US
 * @param vector<Company> companies is the vector in which objects are stored.
*/
void getUS(vector<Company> companies){
    string str = "US";
    int count = 0;

    for (auto c: companies) {
        if (c.getCountry() == str) {
            count++;
            cout << c.toString() << endl;
        }
    }

    cout << "Number of Companies in the US: " << count << endl;

}//end getUS




