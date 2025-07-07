// Preprocessor directive to include the Input/Output Stream Library
#include <iostream>  
// ^ This is required to use standard I/O objects like cout and cin.
// 'iostream' stands for "input-output stream", and it provides definitions
// for 'std::cout', 'std::cin', 'std::endl', etc.

using namespace std; 
// ^ Without this line, you’d need to use std::cout, std::cin, etc.

// ----------------------
//      MAIN PROGRAM
// ----------------------
int main() {
    // ----------------------
    // Output (cout) Examples
    // ----------------------
    cout << "hi \n";                 // prints: hi
    cout << "hello\n";               // prints: hello
    cout << "bye" << "\n" << "thankyou"; // prints: bye (newline) thankyou

    // ----------------------
    // Data Types and Type Conversion
    // ----------------------
    int a = 100;                     // Integer assignment
    cout << "\na = " << a;           // prints: a = 100
    cout << "\nsize of a = " << sizeof(a); // prints size of int (usually 4 bytes)

    bool x = true;                   // Boolean value (true = 1)
    cout << "\nBoolean x = " << x;   // prints: 1

    char c = 'X';                    // Character variable
    int A = c;                       // Implicit type conversion: char to int
    cout << "\nASCII of 'X' = " << A; // prints: 88

    c = (char)a;                     // Explicit type cast: int to char
    cout << "\nCharacter of 100 = " << c; // prints: d

    // ----------------------
    // Input Examples (cin)
    // ----------------------
    int n;
    cout << "\n\nEnter a number: "; 
    cin >> n;                        // Input for integer n
    cout << "Inputted number: " << n << "\n";

    double price;
    cout << "Enter the price: ";
    cin >> price;                    // Input for floating-point price
    cout << "Inputted price: " << price;

    // ----------------------
    // Arithmetic Operators
    // ----------------------
    int X, Y;
    cout << "\n\nEnter two numbers: ";
    cin >> X >> Y;                   // Input for two integers X and Y

    cout << "X is: " << X << "\nY is: " << Y;

    cout << "\nSum (X + Y): " << X + Y;          // Addition
    cout << "\nSubtraction (X - Y): " << X - Y;  // Subtraction
    cout << "\nDivision (X / Y): " << X / Y;     // Integer Division
    cout << "\nDivision with Type Cast: " << (float)X / Y; // Float division
    cout << "\nMultiplication (X * Y): " << X * Y; // Multiplication
    cout << "\nModulus (X % Y): " << X % Y;      // Remainder

    // ----------------------
    // Relational Operators
    // ----------------------
    cout << "\n\nIs X > Y: " << (X > Y);          // Greater than
    cout << "\nIs X < Y: " << (X < Y);            // Less than
    cout << "\nIs X >= Y: " << (X >= Y);          // Greater than or equal
    cout << "\nIs X <= Y: " << (X <= Y);          // Less than or equal
    cout << "\nIs X == Y: " << (X == Y);          // Equal to
    cout << "\nIs X != Y: " << (X != Y);          // Not equal to

    // ----------------------
    // Logical Operators
    // ----------------------
    cout << "\n\n!(X < Y): " << !(X < Y);                         // NOT operator
    cout << "\n(X < Y) || (X > Y): " << ((X < Y) || (X > Y));     // Logical OR
    cout << "\n(X < Y) && (X > Y): " << ((X < Y) && (X > Y));     // Logical AND

    // ----------------------
    // Unary Operators
    // ----------------------
    cout << "\n\n++X (Pre-increment): " << ++X;  // Increments X first, then prints
    cout << "\n--X (Pre-decrement): " << --X;    // Decrements X first, then prints

    // Return statement indicating successful execution
    return 0;
}
