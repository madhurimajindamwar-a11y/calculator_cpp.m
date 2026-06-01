# Simple Calculator Using C++

## Project Overview

The Simple Calculator is a console-based C++ application designed to perform basic arithmetic operations. The program allows users to enter two numbers and choose an arithmetic operator to perform calculations such as addition, subtraction, multiplication, and division.

This project was developed to strengthen my understanding of fundamental C++ programming concepts including user input/output, conditional statements, switch-case control structures, arithmetic operations, and error handling.

The calculator provides an easy-to-use interface where users can perform mathematical calculations quickly and efficiently.

# Objective

The primary objective of this project is to:

* Learn how to take user input in C++.
* Understand arithmetic operations and operators.
* Implement decision-making using the switch-case statement.
* Handle invalid user input and runtime errors.
* Develop problem-solving skills through practical programming.

# Features

The calculator supports the following operations:

### Addition (+)

Adds two numbers together.

Example:

10 + 5 = 15

### Subtraction (-)

Subtracts the second number from the first number.

Example:

10 - 5 = 5

### Multiplication (*)

Multiplies two numbers.

Example:

10 * 5 = 50

### Division (/)

Divides the first number by the second number.

Example:

10 / 5 = 2

### Error Handling

* Prevents division by zero.
* Detects invalid operators entered by the user.

# How the Program Works

The program follows a simple step-by-step process:

## Step 1: Input First Number

The user enters the first numerical value.

Example:

Enter first number: 25

## Step 2: Select an Operator

The user chooses one of the following operators:

+
-
*
/

Example:

Enter operator (+, -, *, /): *
## Step 3: Input Second Number

The user enters the second numerical value.

Example:

Enter second number: 4

## Step 4: Perform Calculation

The program uses a switch-case statement to determine which arithmetic operation should be performed.
Depending on the operator selected:

* Addition is performed for +
* Subtraction is performed for -
* Multiplication is performed for *
* Division is performed for /
## Step 5: Display Result

The calculated result is displayed on the screen.
Example:

Result = 100

# Code Structure

## Input Section

The program first collects the required input from the user.


double num1, num2;
char op;

cin >> num1;
cin >> op;
cin >> num2;

### Explanation

* `num1` stores the first number.
* `num2` stores the second number.
* `op` stores the arithmetic operator selected by the user.

## Switch-Case Statement

The switch statement is used to execute the corresponding arithmetic operation.

switch(op)
{
    case '+':
        cout << num1 + num2;
        break;

    case '-':
        cout << num1 - num2;
        break;

    case '*':
        cout << num1 * num2;
        break;

    case '/':
        cout << num1 / num2;
        break;
}
```

### Why Switch-Case?

The switch-case structure provides:

* Better readability
* Faster execution for multiple choices
* Cleaner code organization

compared to multiple if-else statements.

# Division by Zero Handling

One important feature of this project is preventing division by zero.

```cpp
if(num2 != 0)
    cout << num1 / num2;
else
    cout << "Division by zero is not allowed!";


### Why This Is Important

Division by zero is mathematically undefined and can cause runtime errors. This validation improves the reliability of the program.

# Sample Outputs

## Example 1: Addition

Enter first number: 20
Enter operator (+, -, *, /): +
Enter second number: 15

Result = 35

## Example 2: Multiplication

Enter first number: 8
Enter operator (+, -, *, /): *
Enter second number: 6

Result = 48

## Example 3: Division by Zero

Enter first number: 25
Enter operator (+, -, *, /): /
Enter second number: 0

Division by zero is not allowed!
## Example 4: Invalid Operator

Enter first number: 10
Enter operator (+, -, *, /): %

Enter second number: 5

Invalid operator!

# Concepts Learned

Through this project, I gained practical experience in:

* Variables and Data Types
* User Input and Output
* Arithmetic Operators
* Switch-Case Statements
* Conditional Statements
* Error Handling
* Program Flow Control
* Problem Solving Using C++

# Time Complexity Analysis

The calculator performs a single arithmetic operation based on the user's choice.

### Time Complexity

O(1)

Reason:

Only one operation is executed regardless of the input values.

### Space Complexity

O(1)

Reason:

The program uses a fixed amount of memory for storing variables.
# Applications

A simple calculator is one of the most fundamental applications in programming and forms the basis for:

* Scientific Calculators
* Financial Calculation Systems
* Billing Applications
* Educational Software
* Engineering Tools
# Future Enhancements

The project can be extended with additional features such as:

* Square Root Calculation
* Percentage Calculation
* Power and Exponential Operations
* Modulus Operator
* Scientific Calculator Functions
* Graphical User Interface (GUI)
* Calculation History Storage

# Conclusion

This project successfully demonstrates the implementation of a basic calculator using C++. It provides a practical understanding of arithmetic operations, switch-case statements, user interaction, and error handling. The application is simple, efficient, and serves as an excellent beginner-level project for learning core programming concepts in C++.
