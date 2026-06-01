#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

class TodoManager
{
private:
    vector<string> tasks;
    const string FILE_NAME = "tasks.txt";

    void loadTasks()
    {
        ifstream inputFile(FILE_NAME);

        string task;
        while (getline(inputFile, task))
        {
            if (!task.empty())
            {
                tasks.push_back(task);
            }
        }

        inputFile.close();
    }

    void saveTasks() const
    {
        ofstream outputFile(FILE_NAME);

        for (const auto& task : tasks)
        {
            outputFile << task << endl;
        }

        outputFile.close();
    }

public:
    TodoManager()
    {
        loadTasks();
    }

    void addTask()
    {
        string task;

        cout << "\nEnter Task Description: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, task);

        if (task.empty())
        {
            cout << "Task cannot be empty.\n";
            return;
        }

        tasks.push_back(task);
        saveTasks();

        cout << "\nTask added successfully.\n";
    }

    void viewTasks() const
    {
        if (tasks.empty())
        {
            cout << "\nNo tasks found.\n";
            return;
        }

        cout << "\n========== CURRENT TASKS ==========\n";

        for (size_t i = 0; i < tasks.size(); i++)
        {
            cout << "[" << i + 1 << "] " << tasks[i] << endl;
        }

        cout << "===================================\n";
    }

    void deleteTask()
    {
        if (tasks.empty())
        {
            cout << "\nNo tasks available to delete.\n";
            return;
        }

        viewTasks();

        int taskNumber;

        cout << "\nEnter Task Number to Delete: ";
        cin >> taskNumber;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input.\n";
            return;
        }

        if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size()))
        {
            cout << "\nTask number out of range.\n";
            return;
        }

        tasks.erase(tasks.begin() + taskNumber - 1);
        saveTasks();

        cout << "\nTask deleted successfully.\n";
    }

    void displayMenu() const
    {
        cout << "\n=====================================\n";
        cout << "      COMMAND LINE TO-DO LIST\n";
        cout << "=====================================\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
    }
};

int main()
{
    TodoManager todoManager;
    int choice;

    do
    {
        todoManager.displayMenu();

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nPlease enter a valid numeric choice.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
                todoManager.addTask();
                break;

            case 2:
                todoManager.viewTasks();
                break;

            case 3:
                todoManager.deleteTask();
                break;

            case 4:
                cout << "\nThank you for using the To-Do List Application.\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}