#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsListUsersShowScreen.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsMangeUsers : protected clsScreen
{
private:
	enum enManageOpt
	{
		ShowUsers = 1,
		Add_New_User = 2,
		Delete_User = 3,
		Update_User = 4,
		Find_User = 5,
		Main_Menue = 6
	};

	static void _PrintManageUsers()
	{
		_DrawScreenHeader("\t \tMange Users Screen","");
		cout << "\n\t\t\t\t\t=============================================\n";
		cout << "\t\t\t\t\t";
		cout << "Mange User Menue Screen";
		cout << "\n\t\t\t\t\t=============================================\n";
		cout << "\t\t\t\t\t [1] List Users.\n";
		cout << "\t\t\t\t\t [2] Add New User.\n";
		cout << "\t\t\t\t\t [3] Delete User.\n";
		cout << "\t\t\t\t\t [4] Update User.\n";
		cout << "\t\t\t\t\t [5] Find User.\n";
		cout << "\t\t\t\t\t [6] Main Menue.\n";
		cout << "\n\t\t\t\t\t=============================================\n";
	}

	static void _PerformManageUserOption(enManageOpt Opt)
	{

		system("CLS");
		
		switch (Opt)
		{
		case ShowUsers:
			_ShowAllUsers();
			_GoBackToManageMenue();
			break;
		case Add_New_User:
			_ShowAddNewUserScreen();
			_GoBackToManageMenue();
			break;
		case Delete_User:
			_ShowDeleteUserScreen();
			_GoBackToManageMenue();
			break;
		case Update_User:
			_ShowUpdateUserScreen();
			_GoBackToManageMenue();
			break;
		case Find_User:
			_ShowFindUserScreen();
			_GoBackToManageMenue();
			break;
		case Main_Menue:

			break;
		}

	}
	static void _GoBackToManageMenue()
	{
		cout << "\n\nPress any key to go back to Manage User Menue...";
		system("pause>0");
		ShowMangeUsersScreen();
	}
	static enManageOpt _ReadManageUserMenueOption(string Message)
	{
		short OptNumber;
		do
		{
			cout << Message;
			cin >> OptNumber;

		} while (!(OptNumber > 0 && OptNumber <= 6));

		enManageOpt TheOpt = (enManageOpt)OptNumber;
		return TheOpt;
	}


	static void _ShowAllUsers()
	{
		clsListUsersShowScreen::ShowAllUsers();
	}
	static void _ShowAddNewUserScreen()
	{
		//cout << "\nNot Invaled untel now!!...\n";
		clsAddUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		//cout << "\nNot Invaled untel now!!...\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		//cout << "\nNot Invaled untel now!!...\n";

		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		//cout << "\nNot Invaled untel now!!...\n";
		clsFindUserScreen::ShowFindClientScreen();
	}

public :
	static void ShowMangeUsersScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUser)) 
		{
			cout << "\n\t\t\tPress any key to go back to Main Menue...";
			system("pause>0");
			return;
		}

		system("CLS");
		_PrintManageUsers();
		_PerformManageUserOption(_ReadManageUserMenueOption("\t\t\t\t\tChoose what do you want to do? [1 to 6]? "));
	}

};


