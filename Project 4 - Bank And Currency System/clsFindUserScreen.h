#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
{
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

public:

    static void ShowFindClientScreen()
    {
        _DrawScreenHeader("\t\tFind User Screen", "");
        string UserName;
        UserName = clsInputValidate::ReadString("Please enter User name : ");

        while (!clsUser::IsUserExist(UserName))
        {
            UserName = clsInputValidate::ReadString("User name [" + UserName + "] is not found, choose anouther one: ");
        }
        clsUser User = clsUser::Find(UserName);
        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was Not Found :-(\n";
        }
        _PrintUser(User);

    }
};

