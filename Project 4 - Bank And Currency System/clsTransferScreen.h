#pragma once
#include <sstream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n----------------------------------------\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n----------------------------------------\n";
    }

    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber = "";
        cout << Message;
        AccountNumber = clsInputValidate::ReadString();

        return AccountNumber;
    }

    static clsBankClient _GetClientData(string Message,string NotMatchFirstAccount = "")
    {
        string AccountNumber;
        AccountNumber = _ReadAccountNumber(Message);
        while (!clsBankClient::IsClientExist(AccountNumber) || (AccountNumber == NotMatchFirstAccount))
        {
            cout << "\nClient with [" << AccountNumber << "] does not Exist. ";
            AccountNumber = _ReadAccountNumber(Message);
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        return Client;
    }


public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen","");
        clsBankClient SourceClient = _GetClientData("\nPlease enter client Account Number to Transfer From: ");
        clsBankClient DestinationClient = _GetClientData("\nPlease enter client Account Number to Transfer To: ",SourceClient.getAccountNumber());

        double Amount = 0;
        cout << "\nEnter Transfer Amount? ";
        Amount = clsInputValidate::ReadDblNumber();
        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount? ";
            Amount = clsInputValidate::ReadDblNumber();
        }

        char Ans = 'y';
        cout << "Are you sure you wabt to perform this operation? y/n? ";
        cin >> Ans;

        if (Ans == 'Y' || Ans == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\nTransfer done successfuly.\n";

            }
            else
                cout << "\nTransfer Faild.\n";


            _PrintClient(SourceClient);
            _PrintClient(DestinationClient);
        }

	}

};

