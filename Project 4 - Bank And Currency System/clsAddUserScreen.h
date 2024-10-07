#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include <iostream>
#include "clsInputValidate.h"


using namespace std;

class clsAddUserScreen : protected clsScreen
{
private:
	//enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions
	static void _ReadUserInfo(clsUser& User)
	{
        User.FirstName = clsInputValidate::ReadString("\t\t\t\t\tPlease enter first name : ");
        User.LastName = clsInputValidate::ReadString( "\t\t\t\t\tPlease enter Last name  : ");
        User.Email = clsInputValidate::ReadString(    "\t\t\t\t\tPlease enter Eamil      : ");
        User.Phone = clsInputValidate::ReadString(    "\t\t\t\t\tPlease enter Phone      : ");
        User.Password = clsInputValidate::ReadString( "\t\t\t\t\tPlease enter Password   : ");

        //Permissions code:
        char Ans = 'Y';
        cout << "\t\t\t\t\tEnter Permission:\n";

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

        PermissionsNumber += _ReadThePermissions("\t\t\t\t\tDo you want to give full access? Y/N? ", clsUser::enPermissions::pAll);
        if (PermissionsNumber == -1)
            return PermissionsNumber;

        printf("\n\n\t\t\t\t\tDo you want to give access to : \n");
        PermissionsNumber += _ReadThePermissions("\n\t\t\t\t\tShow Client List     ? y/n? ", clsUser::enPermissions::pListClient);
        PermissionsNumber += _ReadThePermissions("\n\t\t\t\t\tAdd New Client       ? y/n? ", clsUser::enPermissions::pAddNewClient);
        PermissionsNumber += _ReadThePermissions("\n\t\t\t\t\tDelete Client        ? y/n? ", clsUser::enPermissions::pDeleteClient);
        PermissionsNumber += _ReadThePermissions("\n\t\t\t\t\tUpdate Client        ? y/n? ", clsUser::enPermissions::pUpdateClient);
        PermissionsNumber += _ReadThePermissions("\n\t\t\t\t\tFind Client          ? y/n? ", clsUser::enPermissions::pFindClient);
        PermissionsNumber += _ReadThePermissions("\n\t\t\t\t\tTransaction          ? y/n? ", clsUser::enPermissions::pTransactions);
        PermissionsNumber += _ReadThePermissions("\n\t\t\t\t\tManage Users         ? y/n? ", clsUser::enPermissions::pManageUser);
        PermissionsNumber += _ReadThePermissions("\n\t\t\t\t\tLogin Regiset        ? y/n? ", clsUser::enPermissions::pLoginRegister);
        PermissionsNumber += _ReadThePermissions("\n\t\t\t\t\tCurrency Exhange     ? y/n? ", clsUser::enPermissions::pCurrencyExhange);

        return PermissionsNumber;
    }

    static void _PrintUser(clsUser User)
    {
        
        cout << "\n\t\t\t\t\tUser Card:";
        cout << "\n\t\t\t\t\t----------------------------------------\n";
        cout << "\n\t\t\t\t\tFirst Name  : " << User.FirstName;
        cout << "\n\t\t\t\t\tLast Name   : " << User.LastName;
        cout << "\n\t\t\t\t\tFull Name   : " << User.FullName();
        cout << "\n\t\t\t\t\tEmail       : " << User.Email;
        cout << "\n\t\t\t\t\tPhone       : " << User.Phone;
        cout << "\n\t\t\t\t\tPassword    : " << User.Password;
        cout << "\n\t\t\t\t\tPermissions : " << User.Permissions;
        cout << "\n\t\t\t\t\t----------------------------------------\n";
    }

public :
    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\t Add New User Screen","");
        string UserName = "";
        cout << "\n\t\t\t\t\tPlease enter User Name :";
        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            cout << "\t\t\t\t\tUser Name [" << UserName << "] is already used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::GetAddNewUserObject(UserName);

        printf("\n\t\t\t\t\tEnter User Info :\n");
        printf("\t\t\t\t\t----------------------------------------\n");
        _ReadUserInfo(User);
        printf("\n\t\t\t\t\t----------------------------------------\n");
        if (User.Save() == clsUser::enSaveResult::svSucceeded)
        {
            cout << "\n\t\t\t\t\tAccount Addeded Successfully :-)\n";
            _PrintUser(User);
        }
        else
        {
            cout << "\n\t\t\t\t\tError User was't saved because it's Empty...\n";
        }
    }

};

