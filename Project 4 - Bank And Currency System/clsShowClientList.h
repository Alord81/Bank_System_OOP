#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsUtility.h"
#include "clsScreen.h"

using namespace std;

class clsShowClientList : protected clsScreen 
{
private:

    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << left << setw(15) << Client.getAccountNumber();
        cout << "| " << left << setw(30) << Client.FullName();
        cout << "| " << left << setw(12) << Client.Phone;
        cout << "| " << left << setw(20) << Client.Email;
        cout << "| " << left << setw(12) << Client.PinCode;
        printf("| %.f OM", Client.AccountBalance);
        //cout << "| " << left << setw(12) << (to_string(Client.AccountBalance) + " OM");
        cout << endl;
    }

    static void _PrintClientBalancesRecordLine(clsBankClient Client)
    {
        cout << "\n\t\t\t\t| " << left << setw(15) << Client.getAccountNumber();
        cout << "| " << left << setw(30) << Client.FullName();
        printf("| %.f OM", Client.AccountBalance);
    }
     
public:
    static void ShowAllClients()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClient)) return;

        vector <clsBankClient> vClient = clsBankClient::GetClientList();
        string Title = "\t\tClient List Screen";
        string SubTitle = "\t\t (" + to_string(vClient.size()) + ") Client(s)";
        _DrawScreenHeader(Title, SubTitle);
        cout << "\n______________________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(30) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance" << endl;
        cout << "\n______________________________________________________________________________________________________________\n";

        if (vClient.size() == 0)
        {
            cout << "\n\t\t\t\t\tNo Client Available In The System!";
        }
        else
        {
            for (clsBankClient& C : vClient)
            {
                _PrintClientRecordLine(C);
            }
        }


        cout << "\n______________________________________________________________________________________________________________\n";
    }

    static void ShowClientBalances()
    {
        vector <clsBankClient> vClient = clsBankClient::GetClientList();
        double TotalAccountBalances = clsBankClient::GetTotalBalance();

        string Title = "\t\tBalances List Screen";
        string SubTitle = "\t\t (" + to_string(vClient.size()) + ") Client(s)";
        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t\t\t\t____________________________________________________________________\n\n";
        cout << "\t\t\t\t| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(30) << "Client Name";
        cout << "| " << left << setw(12) << "Balance" << endl;
        cout << "\n\t\t\t\t____________________________________________________________________\n";

        if (vClient.size() == 0)
        {
            cout << "\n\t\t\t\t\tNo Client Available In The System!";
        }
        else
        {
            for (clsBankClient& C : vClient)
            {
                _PrintClientBalancesRecordLine(C);
            }
        }

        cout << "\n\t\t\t\t____________________________________________________________________\n";

        //cout << "\t\t\t\tTotal Balance = " << TotalAccountBalances;
        printf("\t\t\t\tTotal Balance = %.2f OM", TotalAccountBalances);
        cout << "\n\t\t\t\t(" << clsUtility::NumberToText(TotalAccountBalances) << ")";
    }

};

