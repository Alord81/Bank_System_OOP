#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDate.h"
#include "clsUtility.h"

using namespace std;

class clsLoginScreen : protected clsScreen 
{
private:




	static bool _Login()
    {
		bool LodingFaild = false;
		short NumberTrials = 0;
		string UserName, Password;
		do
		{
			if (LodingFaild)
			{
				NumberTrials++;
				system("CLS");
				_DrawScreenHeader("\t Login Screen", "");
				printf("\t\t\t\t\tInvalid Username/Password!\n");
				printf("\t\t\t\t\tYou have %d Trials to Login.\n", (3 - NumberTrials));

			}				
 
			if (NumberTrials == 3)
			{
				printf("\t\t\t\t\tYou are Locked after 3 faild to Login.\n\n\n");
				return false;
			}
			UserName = clsInputValidate::ReadString("\t\t\t\t\tEnter Username? ");
			Password = clsInputValidate::ReadString("\t\t\t\t\tEnter Password? ");
 
			//CurrentUser = clsUser::Find(UserName, clsUtility::EncryptText(Password,3));
			CurrentUser = clsUser::Find(UserName,  Password );
			LodingFaild = CurrentUser.IsEmpty();
		} while (LodingFaild);

		CurrentUser.RegisterLogIn();
		
		clsMainScreen::ShowMainMenue();
		return true;

	}




public:

	static bool ShowLoginScreen()
	{
		system("CLS");
		_DrawScreenHeader("\t Login Screen","");
		return _Login();
	}

};

