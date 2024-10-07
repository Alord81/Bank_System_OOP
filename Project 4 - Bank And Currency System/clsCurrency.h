#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "C:\Users\Abdullrahman\Desktop\Programing\C++\Programming Advices\Course-11\clsString.h"

using namespace std;

class clsCurrency
{
private:

	enum enMode {EmptyMode = 0, UpdateMode = 1};
	enMode _Mode;

	string _Country, _CurrencyCode,_CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string seperator = "#//#")
	{
		vector <string> vData;
		vData = clsString::Split(Line, seperator);
		return clsCurrency(enMode::UpdateMode, vData[0], vData[1], vData[2], stof(vData[3]));
	}
		static string _ConvetCurrencyDataToLine(clsCurrency Currency, string seperator = "#//#")
	{
		string Record = "";

		Record += Currency.Country() + seperator;
		Record += Currency.CurrencyCode() + seperator;
		Record += Currency.CurrencyName() + seperator;
		Record += to_string(Currency.Rate()) + seperator;

		return Record;
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
	static vector<clsCurrency> _LoadCurrencyDataFromFile(string url)
	{
		vector<clsCurrency> vDataRecordclsCurrencies;

		fstream TheFile;
		TheFile.open(url, ios::in); // read mode

		if (TheFile.is_open())
		{

			string line;

			while (getline(TheFile, line))
			{
				if (line != "")
				{
					clsCurrency Currency = _ConvertLinetoCurrencyObject(line);
					vDataRecordclsCurrencies.push_back(Currency);
				}
			}
			TheFile.close();
		}

		return vDataRecordclsCurrencies;
	}
	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrency)
	{
		fstream TheFile;
		TheFile.open("Currencies.txt", ios::out); // write mode

		if (TheFile.is_open())
		{

			for (clsCurrency C : vCurrency)
			{

				TheFile << _ConvetCurrencyDataToLine(C) << endl;

			}
			TheFile.close();
		}
	}
	void _Update()
	{
		vector <clsCurrency> vCurrency;
		vCurrency = _LoadCurrencyDataFromFile("Currencies.txt");

		for (clsCurrency& C : vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrency);
	}


public:

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		return (!clsCurrency::FindByCode(CurrencyCode).IsEmpty());
	}
	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile("Currencies.txt");
	}

	enum enSaveResult { svSucceeded = 0, svFaildEmpty };

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}
	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountToUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountToUSD;
		}

		return (float)(AmountToUSD * Currency2.Rate());
	}


};

