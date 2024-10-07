#pragma once
#include <string>
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsUpdateClient :protected clsScreen
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

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "Enter First Name : ";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "Enter Last Name : ";
        Client.LastName = clsInputValidate::ReadString();
        cout << "Enter Email : ";
        Client.Email = clsInputValidate::ReadString();
        cout << "Enter Pin Code : ";
        Client.PinCode = clsInputValidate::ReadString();
        cout << "Enter Account Balance : ";
        Client.AccountBalance = clsInputValidate::ReadDblNumber();

    }

public:

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient)) return;

        _DrawScreenHeader("\t\t Update Client Screen","");


        string AccountNumber = "";

        cout << "Please enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account number is not found, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\n\nUpdate Client Info : ";
        cout << "\n---------------------------------------------\n";
        _ReadClientInfo(Client);

        clsBankClient::enSaveResult SaveResult;
        SaveResult = Client.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svSucceeded:
            cout << "\nAccount Update Successfully :-)\n";
            _PrintClient(Client);

            break;
        case clsBankClient::enSaveResult::svFaildEmpty:
            cout << "\nError account was not saved because it's Empty\n";
            break;
        }

        _PrintClient(Client);

    }


};

