#include<iostream>
#include<vector>
using namespace std;

// Function using pointer (with * in parameter) to increment value
void change(int *a) {
    (*a)++;  // 🔹 '*' here is used to dereference pointer 'a' (i.e., access the value at the address)
}

// Function using reference (with & in parameter) to increment value
void aliaschange(int &a) {
    a++;  // 🔹 '&' here is used in declaration to create an alias; inside the function it behaves like a normal variable
}

int main() {
    int a = 10;

    int* ptr = &a;  // 🔹 '*' used to declare pointer; '&' used to get the address of 'a'

    // Displaying pointer and variable information
    cout << "Address of a            : " << &a << endl;      // 🔹 '&' = address-of operator
    cout << "Value of a              : " << a << endl;
    cout << "Dereferencing ptr       : " << *ptr << endl;    // 🔹 '*' = dereference (access value at address)
    cout << "Address of ptr itself   : " << &ptr << endl;    // 🔹 '&' = address of the pointer variable

    // Using pointer function (requires &a to pass address)
    change(&a);  // 🔹 '&' = address-of operator to pass pointer to function
    cout << "\nValue of a after pointer change : " << a << endl;

    // Using reference function (pass variable directly)
    aliaschange(a);  // 🔹 No & needed; reference automatically refers to original
    cout << "Value of a after alias change   : " << a << endl;

    cout << "\n\n\t\t\t\tPOINTER ARITHMETIC" << endl;

    int* ptr2;                // 🔹 '*' used to declare pointer
    int* ptr1 = ptr2 + 2;     // 🔹 Pointer arithmetic; moves 2 integers ahead

    cout << "Initial ptr1 (ptr2 + 2)         : " << ptr1++ << endl;  // Post-increment: prints, then moves
    cout << "Address after increment (ptr1)  : " << ptr1 << endl;
    cout << "Address of ptr2                 : " << ptr2 << endl;
    cout << "ptr1 - ptr2 (element diff)      : " << ptr1 - ptr2 << endl;  // 🔹 Pointer subtraction = number of elements
    cout << "Is ptr1 < ptr2?                 : " << (ptr1 < ptr2) << endl;
    cout << "Size of ptr1 and ptr2           : " << sizeof(ptr1) << " " << sizeof(ptr2) << endl;

    cout << "\n\n\t\t\t\tPOINTER ARITHMETIC IN ARRAY" << endl;

    int x[5] = {1, 2, 3, 4, 5};
    int* p = x;  // 🔹 Array decays to pointer to first element

    // Array pointer usage
    cout << "Value at x[3] (x+3)             : " << x[3] << endl;
    cout << "Value at x (x[0])               : " << *x << endl;       // 🔹 *x is same as x[0]
    cout << "Value at p++ (x[0], then move)  : " << *(p++) << endl;   // 🔹 *p = x[0], then p = p + 1
    cout << "Value at new p (x[1])           : " << *p << endl;       // 🔹 Now p points to x[1], *p = 2

    return 0;
}

/* 
📌 SUMMARY: MULTI-PURPOSE USAGE OF * and &

🔸 * (Asterisk)
   → Used in 3 ways:
     1. Pointer declaration:       int* ptr;     // ptr is a pointer to int
     2. Dereferencing:             *ptr = 5;     // assign to value pointed by ptr
     3. Multiplication:            int x = 2 * 3;

🔸 & (Ampersand)
   → Used in 3 ways:
     1. Address-of:                int* p = &a;
     2. Reference declaration:     void fun(int &ref)
     3. Bitwise AND:               int b = a & 1;

📌 POINTER VS REFERENCE (ALIAS)

Feature / Aspect                    | Pointer (int* ptr)                               | Reference (Alias) (int& ref)
-----------------------------------|--------------------------------------------------|----------------------------------------------
Definition                         | A variable that holds the address of another var | An alias (alternate name) for another variable
Declaration                        | int* ptr = &a;                                   | int& ref = a;
Dereferencing                      | Requires *ptr to access or modify value          | Use ref directly, behaves like original var
Can be reassigned?                 | ✅ Yes, can point to another variable             | ❌ No, fixed to the original variable
Can be null?                       | ✅ Yes, can be nullptr                           | ❌ No, must refer to a valid variable
Memory Address                     | Has its own memory address                       | Shares same address as original variable
Use in Functions                   | Needs &var to pass (change(&a))                  | Cleaner syntax (change(a))
Safety                             | ⚠️ Less safe – can be uninitialized or null       | ✅ Safer – always refers to valid variable
Use cases                          | Dynamic memory, DSA (linked lists, trees, etc.)  | Function arguments where variable needs update
*/
