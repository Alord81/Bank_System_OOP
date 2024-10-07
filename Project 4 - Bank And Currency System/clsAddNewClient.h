#pragma once
#include <iostream>
#include "C:\Users\Abdullrahman\Desktop\Programing\C++\Programming Advices\Course-11\clsString.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUpdateClient.h"
#include "clsScreen.h"

using namespace std;
class clsAddNewClient : protected clsScreen 
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

    static void _ReadClient(clsBankClient& Client)
    {
        Client.FirstName = clsInputValidate::ReadString("Please enter first name : ");
        Client.LastName = clsInputValidate::ReadString("Please enter Last name  : ");
        Client.Email = clsInputValidate::ReadString("Please enter Eamil      : ");
        Client.Phone = clsInputValidate::ReadString("Please enter Phone      : ");
        Client.PinCode = clsInputValidate::ReadString("Please enter Pin Code   : ");
        cout << "Please enter account balanse :";
        Client.AccountBalance = clsInputValidate::ReadDblNumber();
    }
public :



    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) return;

        _DrawScreenHeader("\t  Add New Client Screen","");
            
        string AccountNumber;
        cout << "\nPlease enter Account Number :";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account number [" << AccountNumber << "] is already used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

        printf("\nEnter Client Info :\n");
        printf("----------------------------------------\n");
        _ReadClient(Client);
        printf("\n----------------------------------------\n");
        if (Client.Save() == clsBankClient::enSaveResult::svSucceeded)
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(Client);
        }
        else
        {
            cout << "\nError account was't saved because it's Empty...\n";
        }

    }


};

