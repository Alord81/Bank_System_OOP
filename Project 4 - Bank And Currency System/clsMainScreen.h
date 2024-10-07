#pragma once
#include <iostream>
#include "clsUpdateClient.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsBankClient.h"
#include "clsShowClientList.h"
#include "clsFindClient.h"
#include "clsTransactrions.h"
#include "clsMangeUsers.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsLoginScreen.h"
#include "clsLogoinRegisterScreen.h"
#include "clsCurrencyExhange.h"

using namespace std;

class clsMainScreen :protected clsScreen
{
private:

	enum _enMainOptions
	{
		Show_Client = 1,
		Add_New_Client = 2,
		Delete_Client = 3,
		Updat_Client = 4,
		Find_Client = 5,
		Transactions = 6,
		Manage_Usre = 7,
		LogoinRegister = 8,
		CurrencyExhange = 9,
		Logout = 10
	};

	 
	static _enMainOptions ReadMainMenueOption(string Message)
	{
		short Choice;
		cout << Message;
		Choice = clsInputValidate::ReadIntNumberBetween(1,10);

		_enMainOptions TheOpt = (_enMainOptions)Choice;
		return TheOpt;
	}

	static void _PerformMainMenueOption(_enMainOptions Opt)
	{
		system("CLS");
		switch (Opt)
		{
		case Show_Client:

			clsShowClientList::ShowAllClients();

			_GoBackToMainMenue();
			break;
		case Add_New_Client:

			clsAddNewClient::ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		case Delete_Client:

			clsDeleteClient::ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case Updat_Client:

			clsUpdateClient::ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case Find_Client:

			clsFindClient::ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case Transactions:

			clsTransactrions::ShowTransactionsMenueScreen();
			_GoBackToMainMenue();
			break;
		case Manage_Usre:

			clsMangeUsers::ShowMangeUsersScreen();
			system("CLS");
			ShowMainMenue();
			break;
		case LogoinRegister:
			clsLogoinRegisterScreen::ShowLoginRegisterScreen();	
			_GoBackToMainMenue();
			break;
		case CurrencyExhange:
			clsCurrencyExhange::ShowCurrencyExhangeScreen();
			ShowMainMenue();
			break;
		case Logout:
			_LoginScreen();
			break;
		}
	}
 
	static void _LoginScreen()
	{
		//cout << "\n---------------------------------------------\n";
		//cout << "\t\tProgram Ends :-)";
		//cout << "\n---------------------------------------------\n";
		//system("pause>0");

		CurrentUser = clsUser::Find("", "");
		//clsLoginScreen::ShowLoginScreen();
	}

	static void _GoBackToMainMenue()
	{
		cout << "\n\t\t\tPress any key to go back to Main Menue...";
		system("pause>0");
		ShowMainMenue();
	}

public:
	

	static void ShowMainMenue()
	{
		system("CLS");
		string FullName = CurrentUser.FullName();
		_DrawScreenHeader("\t \t   Main Screen", "");

		cout << "\t\t\t\t\t [1]  Show Client List.\n";
		cout << "\t\t\t\t\t [2]  Add New Client.\n";
		cout << "\t\t\t\t\t [3]  Delete Client.\n";
		cout << "\t\t\t\t\t [4]  Update Client Info.\n";
		cout << "\t\t\t\t\t [5]  Find Client.\n";
		cout << "\t\t\t\t\t [6]  Transactions.\n";
		cout << "\t\t\t\t\t [7]  Manage Users.\n";
		cout << "\t\t\t\t\t [8]  Logoin Register.\n";
		cout << "\t\t\t\t\t [9]  Currency Exhange\n.";
		cout << "\t\t\t\t\t [10] Logout.";
		cout << "\n\t\t\t\t\t=============================================\n";
		_PerformMainMenueOption(ReadMainMenueOption("\t\t\t\t\tChoose what do you want to do? [1 to 10]? "));

	}

};
