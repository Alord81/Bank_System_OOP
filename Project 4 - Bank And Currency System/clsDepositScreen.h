#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsShowClientList.h"

using namespace std;

class clsDepositScreen : protected clsScreen
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

    void _DepositAction(clsBankClient& Client, vector<clsBankClient>& vClients, string TargetAccount, double Deposit)
    {

        for (clsBankClient& c : vClients)
        {
            if (c.getAccountNumber() == TargetAccount)
            {
                c.AccountBalance += Deposit;
                Client = c;
                break;
            }
        }
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "Please enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        return AccountNumber;
    }

public:
    static void ShowDepositByAccountNumber()
    {
        _DrawScreenHeader("\t  Deposit Screen","");
        
        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not Exist. ";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        double DepositAmount;
        char Answer = 'n';

        cout << "\n\nThe following are the client details:\n";

        _PrintClient(Client);

        printf("Please enter deposit amount? ");
        DepositAmount = clsInputValidate::ReadDblNumber();

        cout << "Are you sure you want perfrom this transaction? y/n? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Client.Deposit(DepositAmount);

            cout << "\nAmount Deposited Successfully. \n";
            cout << "\nNew Balance Is: ";
            cout << Client.AccountBalance;
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }


};

