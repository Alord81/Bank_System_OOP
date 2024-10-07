#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include <iostream>
#include "clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
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

public :

	static void ShowDeleteUserScreen()
	{
        _DrawScreenHeader("\t\t Delete Client Screen", "");
        string UserName;
        UserName = clsInputValidate::ReadString("Please enter User name: ");

        while (!clsUser::IsUserExist(UserName))
        {
            UserName = clsInputValidate::ReadString("User name [" + UserName + "] is not found, choose anouther one: ");
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        char Answer = 'n';

        printf("\nAre you sure you want to delete this user y/n? ");
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                printf("\nUser Deleted Successfully:-)\n");

                _PrintUser(User);
            }
            else
            {

                printf("\nError \'UserName\' was't deleted..\n");
            }

        }
	}


};

