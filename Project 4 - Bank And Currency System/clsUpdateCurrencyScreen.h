#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyScreen : protected clsScreen
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

    static void UpdateRate(clsCurrency Currency)
    {
        float NewRate;
        printf("\n\t\t\t\t\tUpdate Currency Rate:");
        printf("\n\t\t\t\t\t----------------------------------------\n");
        
        printf("\n\t\t\t\t\tEnter New Rate: ");
        NewRate = clsInputValidate::ReadFloatNumber();

        Currency.UpdateRate(NewRate);
        printf("\n\t\t\t\t\tCurrency Rate Updated Succeefullu :-)\n");
        _PrintCurrency(Currency);
    }

public:
    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("\t\tUpdate Currency Screen", "");

        string CurrencyCode = "";
        
        printf("\n\t\t\t\t\tPlease enter currency code: ");
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            printf("\n\t\t\t\t\tPlease enter currency code: ");
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        char Answer = 'y';
        printf("\n\t\t\t\t\tAre you sure you want yo update the rate of this Currency? y/n? ");
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            UpdateRate(Currency);
        }


    }


};

