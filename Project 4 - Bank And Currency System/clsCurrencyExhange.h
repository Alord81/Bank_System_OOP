#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculator.h"

using namespace std;

class clsCurrencyExhange : protected clsScreen
{
private:
	enum _enCurrenciesMainMenueOptions
	{
		ListCurrencies = 1,
		FindCurrency = 2,
		UpdateRate = 3,
		CurrencyCalculator = 4,
		MainMenue = 5
	};
	static _enCurrenciesMainMenueOptions ReadMainMenueOption(string Message)
	{
		short Choice;
		cout << Message;
		Choice = clsInputValidate::ReadIntNumberBetween(1, 5);

		_enCurrenciesMainMenueOptions TheOpt = (_enCurrenciesMainMenueOptions)Choice;
		return TheOpt;
	}
	static void _ShowListCurrencies()
	{
		//cout << "Here the code of " << "List Currencies\n";
		clsCurrencyListScreen::ShowCurrenciesListScreen();
	}	
	static void _ShowFindCurrency()
	{
		//cout << "Here the code of " << "Find Currency\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRate()
	{
		//cout << "Here the code of " << "Update Rate\n";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculator()
	{
		//cout << "Here the code of " << "Currency Calculator\n";
		clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyExhangeMenueOption(_enCurrenciesMainMenueOptions Opt)
	{
		system("CLS");
		switch (Opt)
		{
		case ListCurrencies:
			_ShowListCurrencies();
			_GoBackToCurrencyExhangeMenue();
			break;
		case FindCurrency:
			_ShowFindCurrency();
			_GoBackToCurrencyExhangeMenue();
			break;
		case UpdateRate:
			_ShowUpdateRate();
			_GoBackToCurrencyExhangeMenue();
			break;
		case CurrencyCalculator:
			_ShowCurrencyCalculator();
			_GoBackToCurrencyExhangeMenue();
			break;
		case MainMenue:
			break;
		}
	}

	static void _GoBackToCurrencyExhangeMenue()
	{
		cout << "\n\t\t\tPress any key to go back to Currency Menue...";
		system("pause>0");
		ShowCurrencyExhangeScreen();
	}
	static void _PrintCurrencyExhangeMenue()
	{
		_DrawScreenHeader("\t \tCurrency Exhange Screen", "");
		cout << "\n\t\t\t\t\t=============================================\n";
		cout << "\t\t\t\t\t";
		cout << "Currency Exhange Menue";
		cout << "\n\t\t\t\t\t=============================================\n";
		cout << "\t\t\t\t\t [1] List Currencies.\n";
		cout << "\t\t\t\t\t [2] Find Currency.\n";
		cout << "\t\t\t\t\t [3] Update Rate.\n";
		cout << "\t\t\t\t\t [4] Currency Calculator.\n";
		cout << "\t\t\t\t\t [5] Main Menue.\n";
		cout << "\n\t\t\t\t\t=============================================\n";
	}

public:
	static void ShowCurrencyExhangeScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExhange))
		{
			cout << "\n\t\t\tPress any key to go back to Main Menue...";
			system("pause>0");
			return;
		}

		system("CLS");
		_PrintCurrencyExhangeMenue();
		_PerformCurrencyExhangeMenueOption(ReadMainMenueOption("\t\t\t\t\tChoose what do you want to do? [1 to 5]? "));
	}
};

