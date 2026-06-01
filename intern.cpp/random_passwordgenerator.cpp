#include <iostream>
#include <string>
#include <random>

using namespace std;

// Function to generate a random password
string generatePassword(int length)
{
    const string characters =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*()-_=+[]{}|;:,.<>?";

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, characters.size() - 1);

    string password;

    for (int i = 0; i < length; ++i)
    {
        password += characters[distribution(generator)];
    }

    return password;
}

int main()
{
    int passwordLength;

    cout << "************************************\n";
    cout << "      Random Password Generator\n";
    cout << "*************************************\n";

    cout << "Enter desired password length: ";
    cin >> passwordLength;

    if (passwordLength <= 0)
    {
        cout << "Error: Password length must be greater than 0.\n";
        return 1;
    }

    string password = generatePassword(passwordLength);

    cout << "\nGenerated Password: " << password << endl;

    return 0;
}