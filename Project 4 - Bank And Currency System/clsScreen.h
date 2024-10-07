#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title,string SubTitle)
	{
		cout << "\t\t\t\t\t=============================================\n";
		cout << "\t\t\t\t\t ";
		cout << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t " << SubTitle;
		}
		cout << "\n\t\t\t\t\t=============================================\n";
		cout << "\t\t\t\t\tUser : " << CurrentUser.UserName;

		//clsDate Date;
		//string TodayDate = to_string(Date.GetDay()) + "/" + to_string(Date.GetMonth()) + "/" + to_string(Date.GetYear());
		//cout << "\n\t\t\t\t\tUser : " << TodayDate;
		//printf( "\n\t\t\t\t\tDate : %d/%d/%d", Date.GetDay(), Date.GetMonth(), Date.GetYear()); 

		cout << "\n\t\t\t\t\tUser : " << clsDate::DateToString(clsDate());
		cout << "\n\t\t\t\t\t=============================================\n";
	}
	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t=============================================\n";
			cout << "\t\t\t\t\t Access Denied! Contact your Admin\n";
			cout << "\t\t\t\t\t=============================================\n";
			return false;
		}
		else
		{
			return true;
		}
	}
};

