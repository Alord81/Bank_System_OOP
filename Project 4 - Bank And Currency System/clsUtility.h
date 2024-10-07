#pragma once

#include <iostream>
#include "clsDate.h"
#include "C:\Users\Abdullrahman\Desktop\Programing\C++\Programming Advices\Course-11\clsString.h"
#include <cstdlib>

using namespace std;

class clsUtility
{
	void PrintTableHeader()
	{
		cout << "\n\n\t\t\t Multipliaction Table From 1 to 10\n\n";
		cout << "\t";
		for (int i = 1; i <= 10; i++)
		{
			cout << i << "\t";
		}
		cout << "\n___________________________________________________________________________________\n";
	}

public:
	static string ColumSperator(int Counter)
	{
		if (Counter < 10)
			return " |";
		else
			return " |";
	}
	static int ReadPositiveNumber(string Message)
	{
		int Number = 0;
		do
		{
			cout << Message << endl;
			cin >> Number;
		} while (Number <= 0);
		return Number;
	}
	static enum enPrimeNotPrime {
		Prime = 1,
		NotPrime = 2
	};
	static enPrimeNotPrime CheckPrime(int Number)
	{
		int M = round(Number / 2);
		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return enPrimeNotPrime::NotPrime;
		}
		return enPrimeNotPrime::Prime;
	}
	static bool isPerfectNumber(int Number)
	{
		int Sum = 0;
		for (int i = 1; i < Number; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}
		return Number == Sum;
	}
	static void PrintPerfectNumbersFrom1ToN(int Number)
	{
		for (int i = 1; i <= Number; i++)
		{
			if (isPerfectNumber(i))
			{
				cout << i << endl;
			}
		}
	}
	static void PrintDigitsInReversedOrder(int Number)
	{
		int Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;
		}
	}
	static int SumOfDigits(int Number)
	{
		int Sum = 0, Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Sum = Sum + Remainder;
		}
		return Sum;
	}
	static int ReverseNumber(int Number)
	{
		int Remainder = 0, Number2 = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}
		return Number2;
	}
	static int CountDigitFrequency(short DigitToCheck, int Number)
	{
		int FreqCount = 0, Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			if (DigitToCheck == Remainder)
			{
				FreqCount++;
			}
		}
		return FreqCount;
	}
	static void PrintAllDigitsFrequencey(int Number)
	{
		cout << endl;
		for (int i = 0; i < 10; i++)
		{
			short DigitFrequency = 0;
			DigitFrequency = CountDigitFrequency(i, Number);
			if (DigitFrequency > 0)
			{
				cout << "Digit " << i << " Frequencey is "
					<< DigitFrequency << " Time(s).\n";
			}
		}
	}
	static void PrintDigits(int Number)
	{
		int Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;
		}
	}
	static bool IsPalindromeNumber(int Number)
	{
		return Number == ReverseNumber(Number);
	}
	static void PrintInvertedNumberPattern(int Number)
	{
		cout << "\n";
		for (int i = Number; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}
			cout << "\n";
		}
	}
	static void PrintNumberPattern(int Number)
	{
		cout << "\n";
		for (int i = 1; i <= Number; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}
			cout << "\n";
		}
	}
	static void PrintInvertedLetterPattern(int Number)
	{
		cout << "\n";
		for (int i = 65 + Number - 1; i >= 65; i--)
		{
			for (int j = 1; j <= Number - (65 + Number - 1); j++)
			{
				cout << char(i);
			}
			cout << "\n";
		}
	}
	static void PrintLetterPattern(int Number)
	{
		cout << "\n";
		for (int i = 65; i <= 65 + Number - 1; i++)
		{
			for (int j = 1; j <= i - 65 + 1; j++)
			{
				cout << char(i);
			}
			cout << "\n";
		}
	}
	static void PrintWordsFromAAAtoZZZ()
	{
		cout << "\n";
		string word = "";
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					word = word + char(i);
					word = word + char(j);
					word = word + char(k);
					cout << word << endl;
					word = "";
				}
			}
			cout << "\n____________________________\n";
		}
	}
	static string ReadPassword()
	{
		string Password;
		cout << "Please enter a 3-Letter Password (all capital)?\n";
		cin >> Password;
		return Password;
	}
	static bool GuessPassword(string OriginalPassword)
	{
		string word = "";
		int Counter = 0;
		cout << "\n";
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					Counter++;
					word = word + char(i);
					word = word + char(j);
					word = word + char(k);
					cout << "Trial [" << Counter << "] : " << word
						<< endl;
					if (word == OriginalPassword)
					{
						cout << "\nPassword is " << word << "\n";
						cout << "Found after " << Counter << "Trial(s)\n";
						return true;
					}
					word = "";
				}
			}
		}
		return false;
	}
	static string ReadText()
	{
		string Text;
		cout << "Please enter Text?\n";
		getline(cin, Text);
		return Text;
	}
	static string EncryptText(string Text, short EncryptionKey =2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}
	static string DecryptText(string Text, short EncryptionKey =2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To)
	{
		// Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static enum enCharType {
		SamallLetter = 1,
		CapitalLetter = 2,
		SpecialCharacter = 3,
		Digit = 4
	};
	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SamallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string GenerateKey()
	{
		string Key = "";
		Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
		return Key;
	}
	static void GenerateKeys(short NumberOfKeys)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}
	}
	static void FillArrayWithKeys(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey();
	}
	static void PrintArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}

	static void ReadArray(int arr[100], int& arrLength)
	{
		cout << "\nEnter number of elements:\n";
		cin >> arrLength;
		cout << "\nEnter array elements: \n";
		for (int i = 0; i < arrLength; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
		}
		cout << endl;
	}
	static int TimesRepeated(int Number, int arr[100], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
		{
			if (Number == arr[i])
			{
				count++;
			}
		}
		return count;
	}
	static void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
	{
		cout << "\nEnter number of elements:\n";
		cin >> arrLength;
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(1, 100);
	}
	static void FillArrayWithRandomNumbers(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(1, 100);
	}
	static int MaxNumberInArray(int arr[100], int arrLength)
	{
		int Max = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] > Max)
			{
				Max = arr[i];
			}
		}
		return Max;
	}
	static int MinNumberInArray(int arr[100], int arrLength)
	{
		int Min = 0;
		Min = arr[0];
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < Min)
			{
				Min = arr[i];
			}
		}
		return Min;
	}
	static int SumArray(int arr[100], int arrLength)
	{
		int Sum = 0;
		for (int i = 0; i < arrLength; i++)
		{
			Sum += arr[i];
		}
		return Sum;
	}
	static float ArrayAverage(int arr[100], int arrLength)
	{
		return (float)SumArray(arr, arrLength) / arrLength;
	}
	static void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}
	static void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100],
		int arrLength, int& arr2Lenght)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
			{
				arrDestination[Counter] = arrSource[i];
				Counter++;
			}
		}
		arr2Lenght = --Counter;
	}
	static void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arrSum[i] = arr1[i] + arr2[i];
		}
	}
	static void SwapNumbers(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void FillArrayWith1toN(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = i + 1;
	}
	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			SwapNumbers(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}
	static void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[arrLength - 1 - i];
	}
	static short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == Number)
				return i;
		}
		return -1;
	}
	static void PrintNumberPosition(int Number, int arr[100], int arrLength)
	{
		short NumberPosition = FindNumberPositionInArray(Number, arr,
			arrLength);
		if (NumberPosition == -1)
			cout << "The number is not found :-(\n";
		else
		{
			cout << "The number found at position: ";
			cout << NumberPosition << endl;
			cout << "The number found its order: ";
			cout << NumberPosition + 1 << endl;
		}
	}
	static bool IsNumberInArray(int Number, int arr[100], int arrLength)
	{
		return FindNumberPositionInArray(Number, arr, arrLength) != -1;
	}
	static void PrintFoundOrNotFound(int Number, int arr[100], int arrLength)
	{
		cout << "\nNumber you are looking for is: " << Number << endl;
		if (!IsNumberInArray(Number, arr, arrLength))
			cout << "No, The number is not found :-(\n";
		else
		{
			cout << "Yes, it is found :-)\n";
		}
	}
	static void AddArrayElement(int Number, int arr[100], int& arrLength)
	{
		arrLength++;
		arr[arrLength - 1] = Number;
	}

	static void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
			if (arrSource[i] % 2 != 0)
			{
				AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
			}
	}
	static void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
			if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
			{
				AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
			}
	}
	static void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
	{
		for (int i = 0; i < SourceLength; i++)
		{
			if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
			{
				AddArrayElement(arrSource[i], arrDestination, DestinationLength);
			}
		};
	}
	static bool IsPalindromeArray(int arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			if (arr[i] != arr[Length - i - 1])
			{
				return false;
			}
		};
		return true;
	}
	static int OddCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 != 0)
			{
				Counter++;
			}
		}
		return Counter;
	}
	static int EvenCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 == 0)
			{
				Counter++;
			}
		}
		return Counter;
	}
	static int PositiveCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] >= 0)
			{
				Counter++;
			}
		}
		return Counter;
	}
	static int NegativeCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < 0)
			{
				Counter++;
			}
		}
		return Counter;
	}
	static float MyABS(float Number)
	{
		if (Number > 0)
			return Number;
		else
			return Number * -1;
	}
	static float GetFractionPart(float Number)
	{
		return Number - int(Number);
	}
	static int MyRound(float Number)
	{
		int IntPart;
		IntPart = int(Number);
		float FractionsPart = GetFractionPart(Number);
		if (FractionsPart >= .5)
		{
			if (Number > 0)
			{
				return ++IntPart;
			}
			else
			{
				return --IntPart;
			}
		}
		else
		{
			return IntPart;
		}
	}
	static int MyFloor(float Number)
	{
		if (Number > 0)
			return int(Number);
		else
			return int(Number) - 1;
	}
	static int MyCeil(float Number)
	{
		if (abs(GetFractionPart(Number)) > 0)
		{
			if (Number > 0)
				return int(Number) + 1;
			else
				return int(Number);
		}
		else
		{
			return int(Number);
		}
	}
	static int MySqrt(float Number)
	{
		return pow(Number, 0.5);
	}

	static string NumberToText(int Number)
	{
		if (Number <= 0)
		{
			return "";
		}

		if (Number >= 1 && Number < 20)
		{
			vector<string> vNumber = {
				"One",
				"Two",
				"Three",
				"Four",
				"Five",
				"Six",
				"Seven",
				"Eight",
				"Nine",
				"Ten",
				"Eleven",
				"Twelve",
				"Thirteen",
				"Fourteen",
				"Fifteen",
				"Sixteen",
				"Seventeen",
				"Eighteen",
				"Nineteen" };

			return vNumber[Number - 1];
		}

		if (Number > 19 && Number < 100)
		{
			vector<string> vNumber = {
				"Ten",
				"Twenty",
				"Thirty",
				"Forty",
				"Fifty",
				"Sixty",
				"Seventy",
				"Eighty",
				"Ninety" };

			return vNumber[(Number / 10) - 1] + " " + NumberToText(Number % 10);
		}

		if (Number > 99 && Number < 200)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}

		if (Number > 199 && Number < 1000)
		{
			return NumberToText(Number / 100) + " Hundreds " + NumberToText(Number % 100);
		}

		if (Number > 999 && Number < 2000)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number > 1999 && Number < 1000000)
		{
			return NumberToText(Number / 1000) + " Thousands " + NumberToText(Number % 1000);
		}

		if (Number > 99999 && Number < 2000000)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}

		if (Number > 1999999 && Number < 1000000000)
		{
			return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000);
		}

		if (Number > 199999999 && Number < 2000000000)
		{
			return "One Billion  " + NumberToText(Number % 1000000000);
		}
		else
		{
			return NumberToText(Number / 1000000000) + " Billions " + NumberToText(Number % 1000000000);
		}
	}

};

