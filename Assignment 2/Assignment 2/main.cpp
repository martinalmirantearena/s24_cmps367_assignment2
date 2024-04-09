//
//  main.cpp
//  Assignment 2
//
//  Created by Martin Almirantearena on 4/9/24.
//



/*   Problem 1

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main(int argc, const char * argv[]) {
    
    
    // Struct to hold expression data
    struct Expression {
        string expression;
        float operand1 = 0, operand2 = 0;
        char op = ' ';
        bool firstOperandSet = false;
        bool operatorSet = false;
        bool secondOperandSet = false;
        bool decimalPoint = false;
    };
    
    // Function to check if a character is an operator
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
    
    // Function to perform arithmetic operation
    float performOperation(float num1, float num2, char op) {
        switch(op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                if (num2 != 0)
                    return num1 / num2;
                else {
                    cout << "Error: Division by zero!" << endl;
                    exit(1);
                }
            case '^':
                return pow(num1, num2);
            default:
                cout << "Error: Invalid operator!" << endl;
                exit(1);
        }
    }
    
    int main() {
        
    
        Expression expr;
        cout << "Enter the expression you want to solve: ";
        getline(cin, expr.expression);
        
        for (char c : expr.expression) {
            if (isdigit(c)) {
                if (!expr.firstOperandSet) {
                    expr.operand1 = expr.operand1 * 10 + (c - '0');
                } else if (expr.operatorSet && !expr.secondOperandSet) {
                    expr.operand2 = expr.operand2 * 10 + (c - '0');
                }
            } else if (c == '.') {
                if (!expr.decimalPoint) {
                    expr.decimalPoint = true;
                    if (!expr.firstOperandSet)
                        expr.operand1 /= 10.0;
                    else if (expr.operatorSet && !expr.secondOperandSet)
                        expr.operand2 /= 10.0;
                } else {
                    cout << "Error: Invalid expression!" << endl;
                    exit(1);
                }
            } else if (isOperator(c)) {
                if (!expr.operatorSet) {
                    expr.op = c;
                    expr.operatorSet = true;
                    expr.firstOperandSet = true;
                } else {
                    cout << "Error: Invalid expression!" << endl;
                    exit(1);
                }
            }
        }
        
        // Perform the operation
        float result = performOperation(expr.operand1, expr.operand2, expr.op);
        cout << "Result: " << result << endl;
        
        return 0;
    }
}
*/

/*  Problem 2
 
 #include <iostream>
 using namespace std;
 
 // Struct to hold date data
 struct Date {
 int month;
 int day;
 int year;
 };
 
 int main() {
 char choice;
 Date birthday;
 
 do {
 // Ask the user for birthday date
 cout << "Enter your birthday date (MM DD YYYY): ";
 cin >> birthday.month >> birthday.day >> birthday.year;
 
 // Validate year range
 if (birthday.year < 2000 || birthday.year > 2023) {
 cout << "Invalid year. Please enter a year between 2000 and 2023." << endl;
 continue;
 }
 
 // Validate month range
 if (birthday.month < 1 || birthday.month > 12) {
 cout << "Invalid month. Please enter a month between 1 and 12." << endl;
 continue;
 }
 
 // Validate day range based on month
 switch (birthday.month) {
 case 1: case 3: case 5: case 7: case 8: case 10: case 12:
 if (birthday.day < 1 || birthday.day > 31) {
 cout << "Invalid day for the given month." << endl;
 continue;
 }
 break;
 case 4: case 6: case 9: case 11:
 if (birthday.day < 1 || birthday.day > 30) {
 cout << "Invalid day for the given month." << endl;
 continue;
 }
 break;
 case 2:
 // Check for leap year
 if ((birthday.year % 4 == 0 && birthday.year % 100 != 0) || (birthday.year % 400 == 0)) {
 if (birthday.day < 1 || birthday.day > 29) {
 cout << "Invalid day for February (leap year)." << endl;
 continue;
 }
 } else {
 if (birthday.day < 1 || birthday.day > 28) {
 cout << "Invalid day for February." << endl;
 continue;
 }
 }
 break;
 }
 
 // Display appropriate response
 cout << "You entered: " << birthday.month << "/" << birthday.day << "/" << birthday.year << endl;
 cout << "Happy birthday!" << endl;
 
 // Ask if the user wants to enter another birthday
 cout << "Do you want to enter another birthday? (y/n): ";
 cin >> choice;
 } while (choice == 'y' || choice == 'Y');
 
 cout << "Goodbye!" << endl;
 
 return 0;
 }
 */

/* Problem 3
 
 #include <iostream>
 #include <string>
 #include <cmath>

 using namespace std;

 // Struct to hold person's information
 struct Person {
     string name;
     string gender;
     int age;
     int heightFeet;
     int heightInches;
     double weightPounds;
 };

 int main() {
     Person person;

     // Ask the user for their information
     cout << "Enter your name: ";
     getline(cin, person.name);

     cout << "Enter your age: ";
     cin >> person.age;

     cout << "Enter your gender (male/female): ";
     cin >> person.gender;

     cout << "Enter your height (feet): ";
     cin >> person.heightFeet;

     cout << "Enter your height (inches): ";
     cin >> person.heightInches;

     cout << "Enter your weight (pounds): ";
     cin >> person.weightPounds;

     // Convert height to inches
     int heightInchesTotal = person.heightFeet * 12 + person.heightInches;

     // Calculate BMI
     double bmi = (703 * person.weightPounds) / (pow(heightInchesTotal, 2));

     // Determine BMI status
     string bmiStatus;
     if (bmi < 18.5) {
         bmiStatus = "Underweight";
     } else if (bmi >= 18.5 && bmi < 25) {
         bmiStatus = "Normal";
     } else if (bmi >= 25 && bmi < 30) {
         bmiStatus = "Overweight";
     } else {
         bmiStatus = "Obese";
     }

     // Output the information
     cout << "\nName: " << person.name << endl;
     cout << "Age: " << person.age << endl;
     cout << "Gender: " << person.gender << endl;
     cout << "Height: " << person.heightFeet << " feet " << person.heightInches << " inches" << endl;
     cout << "Weight: " << person.weightPounds << " pounds" << endl;
     cout << "BMI: " << bmi << " (" << bmiStatus << ")" << endl;

     return 0;
 }
*/

/* Problem 4

#include <iostream>

using namespace std;

// Struct to hold multiplication table data
struct MultiplicationTable {
    int startRange;
    int endRange;
    int startMultiply;
    int endMultiply;
};

int main() {
    char choice;
    
    do {
        MultiplicationTable table;
        
        // Input starting and ending range for the multiplication table
        cout << "Enter the starting range for Multiplication Table: ";
        cin >> table.startRange;
        
        cout << "Enter the ending range for Multiplication Table: ";
        cin >> table.endRange;
        
        // Input starting and ending range for the numbers to multiply
        cout << "Enter the starting range for multiplying the numbers in Multiplication Table: ";
        cin >> table.startMultiply;
        
        cout << "Enter the ending range for multiplying the numbers in Multiplication Table: ";
        cin >> table.endMultiply;
        
        // Generate and display the multiplication table
        cout << "Here is the multiplication table for " << table.startRange << " to " << table.endRange << " in the range of "
             << table.startMultiply << " to " << table.endMultiply << endl;
        
        // Display the header row
        cout << "X ";
        for (int i = table.startMultiply; i <= table.endMultiply; ++i) {
            cout << i << " ";
        }
        cout << endl;
        
        // Display the multiplication table
        for (int i = table.startRange; i <= table.endRange; ++i) {
            cout << i << " ";
            for (int j = table.startMultiply; j <= table.endMultiply; ++j) {
                cout << i * j << " ";
            }
            cout << endl;
        }
        
        // Ask if the user wants to create another multiplication table
        cout << "Do you want to create another multiplication table? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the multiplication table generator. Goodbye!" << endl;

    return 0;
}
*/

/* Problem 5

#include <iostream>
#include <cmath>

using namespace std;

// Struct to hold operation data
struct Operation {
    char operand;
    double operand1;
    double operand2;
};

// Struct to hold mathematical function prototypes
struct MathFunctions {
    static double addition(double a, double b) {
        return a + b;
    }

    static double subtraction(double a, double b) {
        return a - b;
    }

    static double multiplication(double a, double b) {
        return a * b;
    }

    static double division(double a, double b) {
        if (b != 0)
            return a / b;
        else {
            cout << "Error: Division by zero!" << endl;
            return NAN; // Not a Number
        }
    }

    static double modulus(double a, double b) {
        return fmod(a, b);
    }

    static double exponent(double a, double b) {
        return pow(a, b);
    }

    static double sin_function(double a) {
        return sin(a);
    }

    static double asin_function(double a) {
        return asin(a);
    }

    // Implement other mathematical functions similarly...
};

int main() {
    Operation operation;

    // Ask the user for the problem to solve
    cout << "Enter the problem to solve (operand operand1 operand2): ";
    cin >> operation.operand >> operation.operand1 >> operation.operand2;

    double result;

    // Determine which operation to perform
    switch (operation.operand) {
        case '+':
            result = MathFunctions::addition(operation.operand1, operation.operand2);
            break;
        case '-':
            result = MathFunctions::subtraction(operation.operand1, operation.operand2);
            break;
        case '*':
            result = MathFunctions::multiplication(operation.operand1, operation.operand2);
            break;
        case '/':
            result = MathFunctions::division(operation.operand1, operation.operand2);
            break;
        case '%':
            result = MathFunctions::modulus(operation.operand1, operation.operand2);
            break;
        case '^':
            result = MathFunctions::exponent(operation.operand1, operation.operand2);
            break;
        case 's':
            result = MathFunctions::sin_function(operation.operand1);
            break;
        case 'a':
            result = MathFunctions::asin_function(operation.operand1);
            break;
        // Add other cases for additional functions...
        default:
            cout << "Error: Invalid operand!" << endl;
            return 1;
    }

    // Output the result
    cout << "Result: " << result << endl;

    return 0;
}
*/
