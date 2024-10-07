#pragma once

#include <iostream>
#include "C:\Users\Abdullrahman\Desktop\Programing\C++\Programming Advices\Course-11\clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n----------------------------------------\n";
        cout << "\nFirst Name  : " << User.FirstName;
        cout << "\nLast Name   : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions  : " << User.Permissions;
        cout << "\n----------------------------------------\n";
    }

    static void _ReadUserInfo(clsUser& User)
    {
        User.FirstName = clsInputValidate::ReadString("Please enter first name : ");
        User.LastName = clsInputValidate::ReadString("Please enter Last name  : ");
        User.Email = clsInputValidate::ReadString("Please enter Eamil      : ");
        User.Phone = clsInputValidate::ReadString("Please enter Phone      : ");
        User.Password = clsInputValidate::ReadString("Please enter Password   : ");

        //Permissions code:
        cout << "Enter Permission:\n";

        User.Permissions = _ReadPermissionsToSet();

    }

    static int unsigned _ReadThePermissions(string Message, clsUser::enPermissions PermFor)
    {
        char Ans;
        cout << Message;
        cin >> Ans;

        if (Ans == 'y' || Ans == 'Y')
        {
            return PermFor;
        }
        else
        {
            return 0;
        }
    }

    static int _ReadPermissionsToSet()
    {
        short PermissionsNumber = 0;

        PermissionsNumber += _ReadThePermissions("Do you want to give full access? Y/N? ", clsUser::enPermissions::pAll);
        if (PermissionsNumber == -1)
            return PermissionsNumber;

        printf("\n\nDo you want to give access to : \n");
        PermissionsNumber += _ReadThePermissions("\nShow Client List     ? y/n? ", clsUser::enPermissions::pListClient);
        PermissionsNumber += _ReadThePermissions("\nAdd New Client       ? y/n? ", clsUser::enPermissions::pAddNewClient);
        PermissionsNumber += _ReadThePermissions("\nDelete Client        ? y/n? ", clsUser::enPermissions::pDeleteClient);
        PermissionsNumber += _ReadThePermissions("\nUpdate Client        ? y/n? ", clsUser::enPermissions::pUpdateClient);
        PermissionsNumber += _ReadThePermissions("\nFind Client          ? y/n? ", clsUser::enPermissions::pFindClient);
        PermissionsNumber += _ReadThePermissions("\nTransaction          ? y/n? ", clsUser::enPermissions::pTransactions);
        PermissionsNumber += _ReadThePermissions("\nManage Users         ? y/n? ", clsUser::enPermissions::pManageUser);
        PermissionsNumber += _ReadThePermissions("\nLogin Regiset        ? y/n? ", clsUser::enPermissions::pLoginRegister);
        PermissionsNumber += _ReadThePermissions("\nCurrency Exhange     ? y/n? ", clsUser::enPermissions::pCurrencyExhange);

        return PermissionsNumber;
    }

public:

    static void ShowUpdateUserScreen()
    {

        _DrawScreenHeader("\t\t Update User Screen", "");


        string UserName = "";

        cout << "Please enter User Name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "User name is not found, choose another one : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\n\nUpdate User Info : ";
        cout << "\n---------------------------------------------\n";
        _ReadUserInfo(User);

        clsUser::enSaveResult SaveResult;
        SaveResult = User.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResult::svSucceeded:
            cout << "\nUser Updated Successfully :-)\n";
            _PrintUser(User);

            break;
        case clsUser::enSaveResult::svFaildEmpty:
            cout << "\nError User was not saved because it's Empty\n";
            break;
        }

        _PrintUser(User);

    }


};

