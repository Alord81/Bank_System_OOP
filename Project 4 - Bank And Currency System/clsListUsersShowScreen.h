#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsUtility.h"

using namespace std;

class clsListUsersShowScreen : protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(25) << left << User.Email;
        //cout << "| " << setw(15) << left << clsUtility::DecryptText(User.Password, 3);
        cout << "| " << setw(15) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;
        cout << endl;
    }


public:
    static void ShowAllUsers()
    {
        vector <clsUser> vUsers = clsUser::GetUserList();

        string Title = "\t\tUsers List Screen";
        string SubTitle = "\t\t (" + to_string(vUsers.size()) + ") User(s)";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________________________\n\n";
        
        cout << setw(8) << left << "" << "| " << left << setw(12) << "User Name";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(25) << "Email";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(12) << "Permissions";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________________________\n\n";

        if (vUsers.size() == 0)
        {
            cout << "\n\t\t\t\t\tNo User Available In The System!";
        }
        else
        {
            for (clsUser& User : vUsers)
            {
                _PrintUserRecordLine(User);
            }
        }


        cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________________________\n\n";
    }
};

