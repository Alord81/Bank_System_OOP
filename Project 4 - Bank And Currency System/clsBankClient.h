#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "C:\Users\Abdullrahman\Desktop\Programing\C++\Programming Advices\Course-11\clsString.h"
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsBankClient : public clsPerson
{

public:
	struct stTransferRecord
	{
		string DateTime;
		string SourceClientAccount;
		double Amount;
		string DestinationClientAccount;
		double BalanceSourceAfterTransfer;
		double BalanceDestinationAfterTransfer;
		string UserName;
	}; 

private:

	enum enMode {EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	bool _MarkForDelete = false;

	static clsBankClient _ConvertLinetoClientObject(string Line, string seperator = "#//#")
	{
		vector <string> vData;
		vData = clsString::Split(Line, seperator);

		return clsBankClient(enMode::UpdateMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], stod(vData[6]));
	}
	
	static string _ConvetClientDataToLine(clsBankClient Client, string seperator = "#//#")
	{
		string Record = "";


		Record += Client.FirstName + seperator;
		Record += Client.LastName + seperator;
		Record += Client.Email + seperator;
		Record += Client.Phone + seperator;
		Record += Client.getAccountNumber() + seperator;
		Record += Client.PinCode + seperator;
		Record += to_string(Client.AccountBalance) + seperator;




		return Record;
	}

	static clsBankClient _GetEmptyClinetObject()
	{
		return clsBankClient(enMode::EmptyMode,"","","","","","",0);
	}

	static vector<clsBankClient> _LoadClientsDataFromFile(string url)
	{
		vector<clsBankClient> vDataRecordClients;

		fstream TheFile;
		TheFile.open(url, ios::in); // read mode

		if (TheFile.is_open())
		{

			string line;

			while (getline(TheFile, line))
			{
				if (line != "")
				{
					clsBankClient Client = _ConvertLinetoClientObject(line);
					vDataRecordClients.push_back(Client);
				}
			}
			TheFile.close();
		}

		return vDataRecordClients;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClient)
	{
		fstream TheFile;
		TheFile.open("Clients.txt", ios::out); // write mode

		if (TheFile.is_open())
		{

			for (clsBankClient Client : vClient)
			{

				TheFile << _ConvetClientDataToLine(Client) << endl;

			}
			TheFile.close();
		}
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsBankClient> vClients;
		vClients = _LoadClientsDataFromFile("Clients.txt");

		for (clsBankClient&Client : vClients)
		{
			if (Client.getAccountNumber() == getAccountNumber())
			{
				Client = *this;
				break;
			}
		}

		_SaveClientsDataToFile(vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvetClientDataToLine(*this));
	}

	void _SaveCleintsDataToFile(string URL, vector<clsBankClient> vClientsData)
	{
		fstream TheFile;
		TheFile.open(URL, ios::out); // read mode

		if (TheFile.is_open())
		{

			for (clsBankClient Client : vClientsData)
			{

				if (Client._MarkForDelete == false)
				{
					TheFile << _ConvetClientDataToLine(Client) << endl;
				}
			}
			TheFile.close();
		}
	}

	static string _PrepareTransferRecord(stTransferRecord TransferRecord,string seperator = "#//#")
	{
		string Record = "";

		Record += clsDate::DateToString(clsDate()) + " - " + clsDate::TimeToString() + seperator;
		Record += TransferRecord.SourceClientAccount + seperator;
		Record += TransferRecord.DestinationClientAccount + seperator;
		Record += to_string(TransferRecord.Amount) + seperator;
		Record += to_string(TransferRecord.BalanceSourceAfterTransfer) + seperator;
		Record += to_string(TransferRecord.BalanceDestinationAfterTransfer) + seperator;
		Record += TransferRecord.UserName;

		return Record;
	}
	static stTransferRecord _ConvetTransferToLine(string Line,string seperator = "#//#")
	{
		stTransferRecord TransferRecord;
		vector <string> TransferRecordDataLine = clsString::Split(Line, seperator);

		TransferRecord.DateTime = TransferRecordDataLine.at(0);
		TransferRecord.SourceClientAccount = TransferRecordDataLine.at(1);
		TransferRecord.DestinationClientAccount = TransferRecordDataLine.at(2);
		TransferRecord.Amount = stof(TransferRecordDataLine.at(3));
		TransferRecord.BalanceSourceAfterTransfer = stof(TransferRecordDataLine.at(4));
		TransferRecord.BalanceDestinationAfterTransfer = stof(TransferRecordDataLine.at(5));
		TransferRecord.UserName = TransferRecordDataLine.at(6);

		return TransferRecord;
	}

	static void _TransferLog(stTransferRecord Record)
	{
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app); // write mode
		string stDataLine = _PrepareTransferRecord(Record);

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


public:
	clsBankClient
	(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
	: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	//set Propertyis

	void setAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	void setPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}


	//get Propertyis

	string getAccountNumber()
	{
		return _AccountNumber;
	}
	float  getAccountBalance()
	{
		return _AccountBalance;
	}
	string getPinCode()
	{
		return _PinCode;
	}


	__declspec(property(get = getAccountBalance, put = setAccountBalance)) float AccountBalance;
	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;


	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsBankClient Clinet = _ConvertLinetoClientObject(Line);
				if (Clinet.getAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Clinet;
				}
				vClients.push_back(Clinet);
			}

			MyFile.close();
		}

		return _GetEmptyClinetObject();
	}

	static clsBankClient Find(string AccountNumber, string PassWord)
	{
		//you can remove this line
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Clinet = _ConvertLinetoClientObject(Line);
				if (Clinet.getAccountNumber() == AccountNumber && Clinet.PinCode == PassWord)
				{
					MyFile.close();
					return Clinet;
				}
				//you can remove this line
				vClients.push_back(Clinet);
			}

			MyFile.close();
		}

		return _GetEmptyClinetObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		return (!clsBankClient::Find(AccountNumber).IsEmpty());
	}
	
	enum enSaveResult {svSucceeded = 0, svFaildEmpty};

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
	
			if (clsBankClient::IsClientExist(_AccountNumber))
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
	
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		clsBankClient Client(enMode::AddNewMode,"","","","",AccountNumber, "", 0);
		return Client;
	}


	bool Delete()
	{
		vector <clsBankClient> vClient = _LoadClientsDataFromFile("Clients.txt");

		for (clsBankClient&C : vClient)
		{
			if (C.getAccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
			}
		}
		_SaveCleintsDataToFile("Clients.txt",vClient);

		*this = _GetEmptyClinetObject();
		return true;
	}

	static vector <clsBankClient> GetClientList()
	{
		return _LoadClientsDataFromFile("Clients.txt");
	}

	static double GetTotalBalance()
	{
		vector <clsBankClient> vClient = clsBankClient::GetClientList();
		double TotalAccountBalances = 0;

		for (clsBankClient& C : vClient)
		{
			TotalAccountBalances += C.AccountBalance;
		}

		return TotalAccountBalances;
	}


	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{

			_AccountBalance -= Amount;
			Save();
		}
	}
	bool Transfer(double Amount, clsBankClient& DestinationClient)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);

		stTransferRecord Record = clsBankClient::TranferRecord(getAccountNumber(), DestinationClient.getAccountNumber(),
			AccountBalance, DestinationClient.AccountBalance, Amount,CurrentUser.UserName);

		_TransferLog(Record);
	}



	static vector <stTransferRecord> GetTransferLogList()
	{
		vector <stTransferRecord> vLoginRegisterRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			stTransferRecord TransferRecord;
			while (getline(MyFile, Line))
			{
				TransferRecord = _ConvetTransferToLine(Line);
				vLoginRegisterRecord.push_back(TransferRecord);

			}
		}

		return vLoginRegisterRecord;
	}

	static stTransferRecord TranferRecord(string SourceClient, string DestinationClient, double BalanceSourceAfterTransfer, double BalanceDestinationAfterTransfer, double Amount, string UserName)
	{
		stTransferRecord Record;

		Record.UserName = UserName;
		Record.SourceClientAccount = SourceClient;
		Record.DestinationClientAccount = DestinationClient;
		Record.BalanceSourceAfterTransfer = BalanceSourceAfterTransfer;
		Record.BalanceDestinationAfterTransfer = BalanceDestinationAfterTransfer;
		Record.Amount = Amount;

		return Record;
	}
};

