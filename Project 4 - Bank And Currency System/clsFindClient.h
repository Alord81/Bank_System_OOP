#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"


using namespace std;


class clsFindClient : protected clsScreen 
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

public:

    static void ShowFindClientScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) return;

		_DrawScreenHeader("\t\tFind Client Screen", "");
        string AccountNumber;
        AccountNumber = clsInputValidate::ReadString("Please enter account number: ");
        
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValidate::ReadString("Account number [" + AccountNumber + "] is not found, choose anouther one: ");
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        if (!Client.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was Not Found :-(\n";
        }
        _PrintClient(Client);

	}

};

