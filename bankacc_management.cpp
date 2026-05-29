#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Bank Account Class
class BankAccount {

private:
    string accountHolder;
    int accountNumber;
    double balance;

public:

    // Constructor
    BankAccount(string name, int accNo, double initialBalance) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    // Deposit Function
    void deposit(double amount) {

        if (amount <= 0) {
            cout << "\nInvalid deposit amount!" << endl;
            return;
        }

        balance += amount;

        cout << fixed << setprecision(2);
        cout << "\nAmount Deposited Successfully!" << endl;
        cout << "Deposited Amount : Rs. " << amount << endl;
    }

    // Withdraw Function
    void withdraw(double amount) {

        if (amount <= 0) {
            cout << "\nInvalid withdrawal amount!" << endl;
            return;
        }

        if (amount > balance) {
            cout << "\nInsufficient Balance!" << endl;
            return;
        }

        balance -= amount;

        cout << fixed << setprecision(2);
        cout << "\nWithdrawal Successful!" << endl;
        cout << "Withdrawn Amount : Rs. " << amount << endl;
    }

    // Check Balance Function
    void checkBalance() {

        cout << fixed << setprecision(2);

        cout << "\n****************************************" << endl;
        cout << "            ACCOUNT DETAILS              " << endl;
        cout << "*******************************************" << endl;

        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Available Balance : Rs. " << balance << endl;

        cout << "********************************************" << endl;
    }
};

int main() {

    string name;
    int accNo;
    double initialBalance;

    cout << "******************************************" << endl;
    cout << "       BANK ACCOUNT MANAGEMENT SYSTEM     " << endl;
    cout << "******************************************" << endl;

    // User Details
    cout << "\nEnter Account Holder Name : ";
    getline(cin, name);

    cout << "Enter Account Number : ";
    cin >> accNo;

    cout << "Enter Initial Balance : Rs. ";
    cin >> initialBalance;

    // Object Creation
    BankAccount userAccount(name, accNo, initialBalance);

    int choice;
    double amount;

    do {

        cout << "\n\n********************************************" << endl;
        cout << "                MAIN MENU                " << endl;
        cout << "********************************************" << endl;

        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;

        cout << "********************************************" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch(choice) {

            case 1:

                cout << "\nEnter Amount to Deposit : Rs. ";
                cin >> amount;

                userAccount.deposit(amount);
                break;

            case 2:

                cout << "\nEnter Amount to Withdraw : Rs. ";
                cin >> amount;

                userAccount.withdraw(amount);
                break;

            case 3:

                userAccount.checkBalance();
                break;

            case 4:

                cout << "\n********************************************" << endl;
                cout << "   THANK YOU FOR USING OUR BANK SYSTEM   " << endl;
                cout << "********************************************" << endl;

                break;

            default:

                cout << "\nInvalid Choice! Please try again." << endl;
        }

    } while(choice != 4);

    return 0;
}