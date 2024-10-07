#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsShowClientList.h"

using namespace std;

class clsWithdraw : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n----------------------------------------\n";
        cout << "\nFirst Name  : " << Client.FirstName;
        cout << "\nLast Name   : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nPassWord    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n----------------------------------------\n";
    }

    //void _WithdrawAction(clsBankClient& Client, vector<clsBankClient>& vClients, string TargetAccount, double Deposit)
    //{

    //    for (clsBankClient& c : vClients)
    //    {
    //        if (c.getAccountNumber() == TargetAccount)
    //        {
    //            c.AccountBalance += Deposit;
    //            Client = c;
    //            break;
    //        }
    //    }
    //}

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "Please enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        return AccountNumber;
    }

public:
    static void ShowWithdrawByAccountNumber()
    {
        _DrawScreenHeader("\t  Withdraw Screen", "");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not Exist. ";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        double Amount;
        char Answer = 'n';

        cout << "\n\nThe following are the client details:\n";

        _PrintClient(Client);

        printf("Please enter withdraw amount? ");
      
        Amount = clsInputValidate::ReadDblNumber();


        cout << "Are you sure you want perfrom this transaction? y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (Client.Withdraw(Amount))
            {
                cout << "\nAmount Withdraw Successfully.\n";
                cout << "\nNew Balance IS : " << Client.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmount to withdraw is: " << Amount << " OM";
                cout << "\nYour Balance is      : " << Client.AccountBalance << " OM\n";
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }


};

