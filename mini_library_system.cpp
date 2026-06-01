#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Book
{
public:
    int bookID;
    string title;
    string author;
};

int main()
{
    const int MAX_BOOKS = 100;

    Book library[MAX_BOOKS];
    int totalBooks = 0;
    int choice;

    do
    {
        cout << "\n========================================";
        cout << "\n      MINI LIBRARY MANAGEMENT SYSTEM";
        cout << "\n========================================";
        cout << "\n1. Add New Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Search Book By Title";
        cout << "\n4. Exit";
        cout << "\n========================================";
        cout << "\nEnter Your Choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                if (totalBooks >= MAX_BOOKS)
                {
                    cout << "\nLibrary is Full!";
                    break;
                }

                cin.ignore();

                cout << "\nEnter Book ID: ";
                cin >> library[totalBooks].bookID;
                cin.ignore();

                cout << "Enter Book Title: ";
                getline(cin, library[totalBooks].title);

                cout << "Enter Author Name: ";
                getline(cin, library[totalBooks].author);

                totalBooks++;

                cout << "\nBook Added Successfully!\n";
                break;
            }

            case 2:
            {
                if (totalBooks == 0)
                {
                    cout << "\nNo Books Available!\n";
                    break;
                }

                cout << "\n==============================================================\n";
                cout << left
                     << setw(10) << "ID"
                     << setw(30) << "Title"
                     << setw(25) << "Author" << endl;

                cout << "==============================================================\n";

                for (int i = 0; i < totalBooks; i++)
                {
                    cout << left
                         << setw(10) << library[i].bookID
                         << setw(30) << library[i].title
                         << setw(25) << library[i].author
                         << endl;
                }

                cout << "==============================================================\n";
                break;
            }

            case 3:
            {
                if (totalBooks == 0)
                {
                    cout << "\nNo Books Available!\n";
                    break;
                }

                cin.ignore();

                string searchTitle;
                bool found = false;

                cout << "\nEnter Book Title to Search: ";
                getline(cin, searchTitle);

                for (int i = 0; i < totalBooks; i++)
                {
                    if (library[i].title == searchTitle)
                    {
                        cout << "\nBook Found!\n";
                        cout << "----------------------------------\n";
                        cout << "Book ID : " << library[i].bookID << endl;
                        cout << "Title   : " << library[i].title << endl;
                        cout << "Author  : " << library[i].author << endl;
                        cout << "----------------------------------\n";

                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "\nBook Not Found!\n";
                }

                break;
            }

            case 4:
            {
                cout << "\n========================================";
                cout << "\n Thank You for Using Library System";
                cout << "\n========================================\n";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice! Please Enter 1-4.\n";
            }
        }

    } while (choice != 4);

    return 0;
}