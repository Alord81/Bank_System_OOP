#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsLoginScreen.h"
#include "clsUtility.h"

using namespace std;

class clsLogoinRegisterScreen : protected clsScreen
{

private:
    static void _PrintClientRecordLine(clsUser::stLoginRegisterRecord User)
    {
        cout << "| " << left << setw(30) << User.DateTime;
        cout << "| " << left << setw(30) << User.UserName;
        cout << "| " << left << setw(25) << clsUtility::DecryptText(User.Password,3);
        cout << "| " << left << setw(20) << User.Permissions;
        cout << endl;
    }
public:
    static void ShowLoginRegisterScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister)) return;

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();
        string Title = "\t\tLogin Register List Screen";
        string SubTitle = "\t\t (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);
        cout << "\n______________________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(30) << "Date/Time";
        cout << "| " << left << setw(30) << "User Name";
        cout << "| " << left << setw(25) << "Password";
        cout << "| " << left << setw(20) << "Permissions";
        cout << "\n______________________________________________________________________________________________________________\n";

        if (vLoginRegisterRecord.size() == 0)
        {
            cout << "\n\t\t\t\t\tNo Client Available In The System!";
        }
        else
        {
            for (clsUser::stLoginRegisterRecord& L : vLoginRegisterRecord)
            {
                _PrintClientRecordLine(L);
            }
        }
         

        cout << "\n______________________________________________________________________________________________________________\n";
    }

};

