#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "C:\Users\Abdullrahman\Desktop\Programing\C++\Programming Advices\Course-11\clsString.h"
#include <vector>
#include "clsInputValidate.h"

using namespace std;

class clsCurrencyCalculator : protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrency Currency,string Title)
    {
        cout << "\n\t\t\t\t\t" << Title << endl;
        cout << "\n\t\t\t\t\t----------------------------------------\n";
        cout << "\n\t\t\t\t\tCountry  : " << Currency.Country();
        cout << "\n\t\t\t\t\tCode     : " << Currency.CurrencyCode();
        cout << "\n\t\t\t\t\tName     : " << Currency.CurrencyName();
        cout << "\n\t\t\t\t\tRate(1$) : " << Currency.Rate();
        cout << "\n\t\t\t\t\t----------------------------------------\n";
    }
    static clsCurrency _GetCurrencyCode(string Message)
    {
        string CurrencyCode;
        cout << "\n\t\t\t\t\t" << Message;

        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            printf("\n\t\t\t\t\tCurrency is not found, choose another one: ");
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }

    static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
    {
        _PrintCurrencyCard(CurrencyFrom,"Convert From: ");
        float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

        cout << "\n\t\t\t\t\t" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " USD\n";
        if (CurrencyTo.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\n\t\t\t\t\tConverting from USD to: \n";
        _PrintCurrencyCard(CurrencyTo,"To: ");
        float AmountInCurrency2 = CurrencyFrom.ConvertToOtherCurrency(Amount,CurrencyTo);
        cout << "\n\t\t\t\t\t" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInCurrency2 << " " << CurrencyTo.CurrencyCode() << "\n";

    }

public:

    static void ShowCurrencyCalculatorScreen()
    {
        
        char Continue = 'Y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("CLS");
            _DrawScreenHeader("\t\tCurrency Calculator Screen", "");
            clsCurrency CurrencyFrom = _GetCurrencyCode("Please enter currency1 code:");
            clsCurrency CurrencyTo = _GetCurrencyCode("Please enter currency2 code:");
            float Amount = 0;

            cout << "\n\t\t\t\t\tEnter amount to Exchange: ";
            Amount = clsInputValidate::ReadFloatNumber();

            _PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\t\t\t\t\tDo you want to perform another calculation? y/n? ";
            cin >> Continue;

        }
    }

};

