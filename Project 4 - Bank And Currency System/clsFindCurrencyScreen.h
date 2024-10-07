#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "C:\Users\Abdullrahman\Desktop\Programing\C++\Programming Advices\Course-11\clsString.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\n\t\t\t\t\tCurrency Card:";
        cout << "\n\t\t\t\t\t----------------------------------------\n";
        cout << "\n\t\t\t\t\tCountry  : " << Currency.Country();
        cout << "\n\t\t\t\t\tCode     : " << Currency.CurrencyCode();
        cout << "\n\t\t\t\t\tName     : " << Currency.CurrencyName();
        cout << "\n\t\t\t\t\tRate(1$) : " << Currency.Rate();
        cout << "\n\t\t\t\t\t----------------------------------------\n";
    } 

    static void _ShowResult(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\n\t\t\t\t\tCurrency Found :-)";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\n\t\t\t\t\tCurrency was not Found :-(\n";
        }
    }

    static void _FindCurrencyByCode()
    {
        string Code;
        printf("\n\t\t\t\t\tPlease enter Code: ");
        Code = clsInputValidate::ReadString();

        clsCurrency Currency = clsCurrency::FindByCode(Code);

        _ShowResult(Currency);
    }
    static void _FindCurrencyByCountry()
    {
        string CountryName;
        printf("\n\t\t\t\t\tPlease enter country name: ");
        CountryName = clsInputValidate::ReadString();

        clsCurrency Currency = clsCurrency::FindByCountry(CountryName);

        _ShowResult(Currency);
    }

public:
    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t\tFind Currency Screen", "");

        short Ans;
        cout << "\n\t\t\t\t\tFind By: [1] Code or [2] Country ? ";
        Ans = clsInputValidate::ReadDblNumber();
        //\n\t\t\t\t\t
        switch (Ans) 
        {
        case 1:
            _FindCurrencyByCode();
            break;
        case 2:
            _FindCurrencyByCountry();
            break;
        }

    }


};

