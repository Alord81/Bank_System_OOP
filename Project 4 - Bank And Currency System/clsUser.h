#pragma once
#include <iostream>
#include "clsPerson.h"
#include <string>
#include "C:\Users\Abdullrahman\Desktop\Programing\C++\Programming Advices\Course-11\clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsUtility.h"

using namespace std;

class clsUser : public clsPerson
{
public:
	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};
	
private:
	enum enMode {EmptyMode =0 , UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkedForDelete = false;
	string _DateAndTime = "";

	static clsUser _ConvertLinetoUserObject(string Line, string seperator = "#//#")
	{
		vector <string> vData;
		vData = clsString::Split(Line, seperator);

		return clsUser(enMode::UpdateMode, vData[0], vData[1], vData[2], vData[3], vData[4], clsUtility::DecryptText(vData[5],3), stod(vData[6]));
	}

	static string _ConvetUserDataToLine(clsUser User, string seperator = "#//#")
	{
		string Record = "";

		Record += User.FirstName + seperator;
		Record += User.LastName + seperator;
		Record += User.Email + seperator;
		Record += User.Phone + seperator;
		Record += User.UserName + seperator;
		Record += clsUtility::EncryptText(User.Password, 3) + seperator;
		Record += to_string(User.Permissions) + seperator;

		return Record;
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsUser> _LoadUsersDataFromFile(string url)
	{
		vector<clsUser> vDataRecordUsers;

		fstream TheFile;
		TheFile.open(url, ios::in); // read mode

		if (TheFile.is_open())
		{

			string line;

			while (getline(TheFile, line))
			{
				if (line != "")
				{
					clsUser User = _ConvertLinetoUserObject(line);
					vDataRecordUsers.push_back(User);
				}
			}
			TheFile.close();
		}

		return vDataRecordUsers;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUser)
	{
		fstream TheFile;
		TheFile.open("Users.txt", ios::out); // write mode

		if (TheFile.is_open())
		{

			for (clsUser User : vUser)
			{

				TheFile << _ConvetUserDataToLine(User) << endl;

			}
			TheFile.close();
		}
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsUser> vUsers;
		vUsers = _LoadUsersDataFromFile("Users.txt");

		for (clsUser& User : vUsers)
		{
			if (User.UserName == UserName)
			{
				User = *this;
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvetUserDataToLine(*this));
	}

	void _SaveUsersDataToFile(string URL, vector<clsUser> vUsersData)
	{
		fstream TheFile;
		TheFile.open(URL, ios::out); // read mode

		if (TheFile.is_open())
		{

			for (clsUser User : vUsersData)
			{

				if (User._MarkedForDelete == false)
				{
					TheFile << _ConvetUserDataToLine(User) << endl;
				}
			}
			TheFile.close();
		}
	}

	string _PrepareLogInRecord(string seperator = "#//#")
	{
		string Record = "";

		Record += clsDate::DateToString(clsDate()) + " - " + clsDate::TimeToString() + seperator;
		Record += this->UserName + seperator;
		Record += clsUtility::EncryptText(this->Password,3) + seperator;
		Record += to_string(this->Permissions);

		return Record;
	}

	static stLoginRegisterRecord _ConvetLoginRegisterToLine(string Line, string seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector <string> LoginRegisterDataLine = clsString::Split(Line,seperator);

		LoginRegisterRecord.DateTime = LoginRegisterDataLine.at(0);
		LoginRegisterRecord.UserName = LoginRegisterDataLine.at(1);
		LoginRegisterRecord.Password = LoginRegisterDataLine.at(2);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine.at(3));

		return LoginRegisterRecord;
	}

public:
	static enum enPermissions
	{
		pAll = -1,
		pListClient = 1,
		pAddNewClient = 2,
		pDeleteClient = 4,
		pUpdateClient = 8,
		pFindClient = 16,
		pTransactions = 32,
		pManageUser = 64,
		pLoginRegister = 128,
		pCurrencyExhange = 256
	};





	clsUser(enMode Mode,string FirstName,string LastName, string Email, string Phone, string UserName,string Password,int Permissions) : clsPerson(FirstName,LastName,Email,Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	string GetPassword()
	{
		return _Password;
	}
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	int GetPermissions()
	{
		return _Permissions;
	}
	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	_declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


	static clsUser Find(string UserName)
	{
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		//you can remove this line
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
				//you can remove this line
				vUsers.push_back(User);
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		return (!clsUser::Find(UserName).IsEmpty());
	}

	enum enSaveResult { svSucceeded = 0, svFaildEmpty };
	enSaveResult Save()
	{
		switch (this->_Mode)
		{
		case enMode::EmptyMode:
			if (IsEmpty())
			{
				return enSaveResult::svFaildEmpty;
			}
			break;
		case enMode::UpdateMode:

			_Update();
			return enSaveResult::svFaildEmpty;
			break;
		case enMode::AddNewMode:

			if (clsUser::IsUserExist(UserName))
			{
				return enSaveResult::svFaildEmpty;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;

			}

			break;
		default:
			break;
		}
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		clsUser User(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
		return User;
	}


	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile("Users.txt");

		for (clsUser& User : vUsers)
		{
			if (User.UserName == UserName)
			{
				User._MarkedForDelete = true;
			}
		}
		_SaveUsersDataToFile("Users.txt", vUsers);

		*this = _GetEmptyUserObject();
		return true;
	}

	static vector <clsUser> GetUserList()
	{
		return _LoadUsersDataFromFile("Users.txt");
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::pAll)
			return true;
		
		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;

	}

	void RegisterLogIn()
	{
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app); // write mode
		string stDataLine = _PrepareLogInRecord();

		if (MyFile.is_open())
		{

			if (MyFile.is_open())
			{

				MyFile << stDataLine << endl;

				MyFile.close();
			}
			MyFile.close();
		}
	}

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoginRegisterRecord;

		fstream MyFile;
		MyFile.open("LoginRegister.txt",ios::in);

		if (MyFile.is_open())
		{
			string Line;
			stLoginRegisterRecord LoginRegisterRecord;
			while (getline(MyFile,Line))
			{
				LoginRegisterRecord = _ConvetLoginRegisterToLine(Line);
				vLoginRegisterRecord.push_back(LoginRegisterRecord);

			}
		}
		
		return vLoginRegisterRecord;
	}
};

