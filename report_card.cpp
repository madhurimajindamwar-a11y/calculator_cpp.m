#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to calculate total marks
float calculateTotal(float marks[], int n) {
    float total = 0;

    for (int i = 0; i < n; i++) {
        total += marks[i];
    }

    return total;
}

// Function to calculate percentage
float calculatePercentage(float total, int n) {
    return total / n;
}

// Function to calculate grade
string calculateGrade(float percentage) {

    if (percentage >= 90)
        return "A+";
    else if (percentage >= 80)
        return "A";
    else if (percentage >= 70)
        return "B";
    else if (percentage >= 60)
        return "C";
    else if (percentage >= 50)
        return "D";
    else
        return "Fail";
}

int main() {

    string studentName;
    int subjects;

    cout << "==========================================" << endl;
    cout << "        STUDENT REPORT CARD SYSTEM        " << endl;
    cout << "==========================================" << endl;

    // Input student details
    cout << "\nEnter Student Name : ";
    getline(cin, studentName);

    cout << "Enter Number of Subjects (3-5) : ";
    cin >> subjects;

    while (subjects < 3 || subjects > 5) {
        cout << "Invalid! Please enter subjects between 3 and 5 : ";
        cin >> subjects;
    }

    string subjectName[5];
    float marks[5];

    // Input subject names and marks
    for (int i = 0; i < subjects; i++) {

        cout << "\nEnter Subject " << i + 1 << " Name : ";
        cin >> subjectName[i];

        cout << "Enter Marks for " << subjectName[i] << " : ";
        cin >> marks[i];
    }

    // Function calls
    float total = calculateTotal(marks, subjects);
    float percentage = calculatePercentage(total, subjects);
    string grade = calculateGrade(percentage);

    // Display Report Card
    cout << "\n\n==========================================" << endl;
    cout << "              REPORT CARD                 " << endl;
    cout << "==========================================" << endl;

    cout << "\nStudent Name : " << studentName << endl;
    cout << "------------------------------------------" << endl;

    cout << left << setw(20) << "Subject"
         << setw(10) << "Marks" << endl;

    cout << "------------------------------------------" << endl;

    for (int i = 0; i < subjects; i++) {

        cout << left << setw(20) << subjectName[i]
             << setw(10) << marks[i] << endl;
    }

    cout << "------------------------------------------" << endl;

    cout << fixed << setprecision(2);

    cout << "\nTotal Marks   : " << total << endl;
    cout << "Percentage    : " << percentage << "%" << endl;
    cout << "Final Grade   : " << grade << endl;

    // Result Status
    if (grade == "Fail")
        cout << "Result Status : FAILED" << endl;
    else
        cout << "Result Status : PASSED" << endl;

    cout << "\n==========================================" << endl;
    cout << "      THANK YOU FOR USING THE SYSTEM      " << endl;
    cout << "==========================================" << endl;

    return 0;
}