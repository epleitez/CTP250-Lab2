//
// Created by Emely Pleitez on 9/14/22.
//

#include "Company.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

//default constructor
Company::Company(){
    string companyName;
    string tradingSymbol;
    double marketCapValue;
    string country;
    string type;
    int rank;
}

Company::Company(string attributes){
    string companyName = "";
    string tradingSymbol = "";
    string marketCapVal = "";
    double marketCapValue = 0;
    string country = "";
    string type = "";
    string theRank = "";
    int rank = 0;
    string line = "";

    istringstream iss(attributes);

    getline(iss, companyName, ',');
    getline(iss, tradingSymbol, ',');
    getline(iss, marketCapVal, ',');
    marketCapValue = stoi(marketCapVal);
    getline(iss,country, ',' );
    getline(iss, type, ',');
    getline(iss, theRank, ',');
    rank = stoi(theRank);

    attributes = companyName + tradingSymbol + marketCapVal +
                 country + type + theRank;

}

//Setters
/* Sets the company name of the Company to companyName
 * @param companyName The new company name of this Company
 */
void Company::setCompanyName(string companyName ) {
    this->companyName = companyName;
}//end

void Company::setTradingSymbol(string tradingSymbol) {
    this->tradingSymbol = tradingSymbol;
}//end

void Company::setMarketCapValue(double marketCapValue) {
    this->marketCapValue = marketCapValue;
}//end

void Company::setCountry(string country){
    this->country = country;
}//end

void Company::setType(string type){
    this->type = type;
}//end

void Company::setRank(int rank){
    this->rank = rank;
}

//Getters
/* Returns the name of this Company
 * @return the name of this Company
 */
string Company::getCompanyName() {
    return companyName;
}//end

string Company::getTradingSymbol() {
    return tradingSymbol;
}//end

double Company::getMarketCapValue() {
    return marketCapValue;
}//end

string Company::getCountry() {
    return country;
}//end

string Company::getType() {
    return type;
}//end

int Company::getRank() {
    return rank;
}//end

const string Company::toString() const{

    ostringstream s;

    s << "Company Name: " << companyName << "\n"
    << "Trading Symbol: " << tradingSymbol << "\n"
    << "Market Cap Value: " << marketCapValue << "\n"
    << "Country: " << country << "\n"
    << "Type: " << type << "\n"
    << "Rank: " << rank << "\n" << endl;

    return s.str();

}





