#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsCurrency.h"
#include "clsScreen.h"

using namespace std;

class clsCurrencyListScreen : protected clsScreen
{
private:
    static void _PrintCurrenciesRecordLine(clsCurrency Currency)
    {
        cout << "| " << left << setw(35) << Currency.Country();
        cout << "| " << left << setw(8) << Currency.CurrencyCode();
        cout << "| " << left << setw(45) << Currency.CurrencyName();
        cout << "| " << left << setw(10) << Currency.Rate();
        cout << endl;
    }

public:
    static void ShowCurrenciesListScreen()
    {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();
        string Title = "\t\tCurrencies List Screen";
        string SubTitle = "\t\t (" + to_string(vCurrency.size()) + ") Currency";
        _DrawScreenHeader(Title, SubTitle);
        cout << "\n______________________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(35) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)" << endl;
        cout << "\n______________________________________________________________________________________________________________\n";

        if (vCurrency.size() == 0)
        {
            cout << "\n\t\t\t\t\tNo Currency Available In The System!";
        }
        else
        {
            for (clsCurrency & C : vCurrency)
            {
                _PrintCurrenciesRecordLine(C);
            }
        }


        cout << "\n______________________________________________________________________________________________________________\n";
    }
};

