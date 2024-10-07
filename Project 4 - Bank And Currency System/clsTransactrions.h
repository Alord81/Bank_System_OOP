#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsShowClientList.h"
#include "clsDepositScreen.h"
#include "clsWithdraw.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactrions : protected clsScreen
{
private:
	enum _enTransactionOpt
	{
		eDeposit = 1,
		eWithdraw = 2,
		eTotalBalances = 3,
		eTransfer = 4,
		eTransferLog = 5,
		eMain_Menue = 6
	};

	static _enTransactionOpt _ReadTransactionsMenueOption(string Message)
	{
		short OptNumber;
		do
		{
			cout << Message;
			cin >> OptNumber;

		} while (!(OptNumber > 0 && OptNumber <= 6));

		_enTransactionOpt TheOpt = (_enTransactionOpt)OptNumber;
		return TheOpt;
	}
	static void _PerformTransactionsMenueOption(_enTransactionOpt TransOpt)
	{
		system("CLS");
		switch (TransOpt)
		{
		case eDeposit:
			_ShowDepositScreen();
			_GoBackToTransactionsMenueScreen();
			break;
		case eWithdraw:
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenueScreen();
			break;
		case eTotalBalances:
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenueScreen();
			break;
		case eTransfer:
			_ShowTransferScreen();
			_GoBackToTransactionsMenueScreen();
			break;
		case eTransferLog:
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenueScreen();
		case eMain_Menue:
			break;
		}
	}
	static void _GoBackToTransactionsMenueScreen()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenueScreen();
	}
	static void _ShowTransactionsMenue()
	{
		_DrawScreenHeader("\t\tTransactions Screen","");
		cout << "\t\t\t\t\t=============================================\n";
		cout << "\t\t\t\t\t ";
		cout << "Transactions Menue Screen";
		cout << "\n\t\t\t\t\t=============================================\n";
		cout << "\t\t\t\t\t [1] Deposit.\n";
		cout << "\t\t\t\t\t [2] Withdraw.\n";
		cout << "\t\t\t\t\t [3] Total Balances.\n";
		cout << "\t\t\t\t\t [4] Transfer.\n";
		cout << "\t\t\t\t\t [5] Transfer Log.\n";
		cout << "\t\t\t\t\t [6] Main Menue.";
		cout << "\n\t\t\t\t\t=============================================\n";
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositByAccountNumber();
	}
	static void _ShowWithdrawScreen()
	{
		clsWithdraw::ShowWithdrawByAccountNumber();

	}	
	static void _ShowTotalBalancesScreen()
	{
		clsShowClientList::ShowClientBalances();
		//cout << "\nNone Untell Now\n";
	}	
	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
		//cout << "\nNone Untell Now\n";

	}
	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
		cout << "\nNone Untell Now\n";

	}
	 
public:
	static void ShowTransactionsMenueScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTransactions)) return;

		system("CLS");
		_ShowTransactionsMenue();
		_PerformTransactionsMenueOption(_ReadTransactionsMenueOption("\t\t\t\t\tChoose what do you want to do? [1 to 6]? "));
	}
};

