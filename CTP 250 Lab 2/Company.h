//
// Created by Emely Pleitez on 9/14/22.
//

#ifndef CTP_250_LAB_2_COMPANY_H
#define CTP_250_LAB_2_COMPANY_H
#include <string>

using namespace std;


class Company {
    private:
        string companyName = "";
        string tradingSymbol = "";
        double marketCapValue = 0;
        string country = "";
        string type = "";
        int rank = 0;

    public:
        //Constructors
        Company();
        /*
        Company(string companyName, string tradingSymbol,
                double marketCapValue, string country, string type, int rank);
        */

        Company(string attributes);

        //Setters
        void setCompanyName(string);
        void setTradingSymbol(string);
        void setMarketCapValue(double);
        void setCountry(string);
        void setType(string);
        void setRank(int);

        //Getters
        string getCompanyName();
        string getTradingSymbol();
        double getMarketCapValue();
        string getCountry();
        string getType();
        int getRank();

        //toString
        const string toString() const;

    protected:

};


#endif //CTP_250_LAB_2_COMPANY_H
