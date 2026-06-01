#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact
{
public:
    string name;
    string phoneNumber;

    Contact(string contactName, string contactPhone)
    {
        name = contactName;
        phoneNumber = contactPhone;
    }
};

void addContact(vector<Contact>& contacts)
{
    string name, phoneNumber;

    cout << "\nEnter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);

    contacts.push_back(Contact(name, phoneNumber));

    cout << "\nContact added successfully!\n";
}

void viewContacts(const vector<Contact>& contacts)
{
    if (contacts.empty())
    {
        cout << "\nNo contacts available.\n";
        return;
    }

    cout << "\n===== Contact List =====\n";

    for (size_t i = 0; i < contacts.size(); i++)
    {
        cout << "\nContact " << i + 1 << endl;
        cout << "Name  : " << contacts[i].name << endl;
        cout << "Phone : " << contacts[i].phoneNumber << endl;
    }
}

void searchContact(const vector<Contact>& contacts)
{
    if (contacts.empty())
    {
        cout << "\nNo contacts available.\n";
        return;
    }

    string searchName;
    
    cout << "\nEnter contact name to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;

    for (const auto& contact : contacts)
    {
        if (contact.name == searchName)
        {
            cout << "\nContact Found!\n";
            cout << "Name  : " << contact.name << endl;
            cout << "Phone : " << contact.phoneNumber << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nContact not found.\n";
    }
}

int main()
{
    vector<Contact> contacts;
    int choice;

    do
    {
        cout << "\n********************************\n";
        cout << "        CONTACT BOOK SYSTEM\n";
        cout << "************************************\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addContact(contacts);
                break;

            case 2:
                viewContacts(contacts);
                break;

            case 3:
                searchContact(contacts);
                break;

            case 4:
                cout << "\nThank you for using Contact Book!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}