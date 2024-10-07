#pragma once
#include <iostream>

using namespace std;


class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	//set Propertyis
	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	void setEmail(string Email)
	{
		_Email = Email;
	}
	void setPhone(string Phone)
	{
		_Phone = Phone;
	}

	// Get Propertyis
	string getFirstName()
	{
		return _FirstName ;
	}
	string getLastName()
	{
		return _LastName ;
	}
	string getEmail()
	{
		return _Email;
	}
	string getPhone()
	{
		return _Phone ;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;
	__declspec(property(get = getLastName, put = setLastName)) string LastName;
	__declspec(property(get = getEmail, put = setEmail)) string Email;
	__declspec(property(get = getPhone, put = setPhone)) string Phone;



	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

};

