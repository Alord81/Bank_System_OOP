#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
    static void _PrintTransferLogRecordLine(clsBankClient::stTransferRecord Record)
    {
        cout << "| " << left << setw(23) << Record.DateTime;
        cout << "| " << left << setw(8) << Record.SourceClientAccount;
        cout << "| " << left << setw(8) << Record.DestinationClientAccount;
        cout << "| " << left << setw(8) << Record.Amount;
        cout << "| " << left << setw(10) << Record.BalanceSourceAfterTransfer;
        cout << "| " << left << setw(10) << Record.BalanceDestinationAfterTransfer;
        cout << "| " << left << setw(8) << Record.UserName;
        cout << endl;
    }
public:
    static void ShowTransferLogScreen()
    {

        vector <clsBankClient::stTransferRecord> vTransferRecor = clsBankClient::GetTransferLogList();
        string Title = "\t\tTransfer Log List Screen";
        string SubTitle = "\t\t (" + to_string(vTransferRecor.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);
        cout << "\n____________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << "\n____________________________________________________________________________________________________\n";

        if (vTransferRecor.size() == 0)
        {
            cout << "\n\t\t\t\t\tNo Data Available In The System!";
        }
        else
        {
            for (clsBankClient::stTransferRecord& L : vTransferRecor)
            {
                _PrintTransferLogRecordLine(L);
            }
        }


        cout << "\n____________________________________________________________________________________________________\n";
    }

};

