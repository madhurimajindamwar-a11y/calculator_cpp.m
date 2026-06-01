#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to check whether a string is a palindrome
bool isPalindrome(const string& text)
{
    string reversedText = text;
    reverse(reversedText.begin(), reversedText.end());

    return text == reversedText;
}

int main()
{
    string input;

    cout << "====================================\n";
    cout << "      Palindrome Checker Program\n";
    cout << "====================================\n";

    cout << "Enter a word or number: ";
    cin >> input;

    if (isPalindrome(input))
    {
        cout << "\nResult: \"" << input << "\" is a Palindrome.\n";
    }
    else
    {
        cout << "\nResult: \"" << input << "\" is NOT a Palindrome.\n";
    }

    return 0;
}