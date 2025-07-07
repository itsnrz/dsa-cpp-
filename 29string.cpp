#include<iostream>
#include<cstring>   // for strlen (optional)
#include<string>    // for std::string (recommended)
using namespace std;

int main() {
    // ❌ Method 1: Dangerous (Do NOT use if you plan to modify it)
    // This points to a string literal in read-only memory
    const char* s1 = "hello"; 
    cout << "String literal (read-only): " << s1 << endl;
    // s1[0] = 'H'; // ❌ Undefined behavior if uncommented

    // ✅ Method 2: Safe, writable array
    // This creates a modifiable character array on stack
    char s2[] = "world";  
    s2[0] = 'W'; // ✅ Safe
    cout << "Modifiable char array: " << s2 << endl;

    // ✅ Taking input into a char array using cin.getline()
    char input1[50];
    cout << "Enter a sentence (max 49 chars): ";
    cin.getline(input1, 50);  // reads including spaces until '\n'
    cout << "You entered: " << input1 << endl;

    // ✅ Method 3: Using std::string (recommended)
    string s3 = "C++ strings are better";
    s3[0] = 'c'; // ✅ Modifiable
    cout << "std::string: " << s3 << endl;

    // ✅ Taking input into a std::string using getline()
    string input2;
    cout << "Enter another sentence (using std::string): ";
    getline(cin, input2);  // much safer and handles any size dynamically
    cout << "You entered: " << input2 << endl;

    // 🔍 What is a delimiter?
    // A delimiter is a character where input stops while using getline().
    // By default, getline() stops at newline '\n', but we can specify another:
    string customInput;
    cout << "Enter text (will stop at '#'): ";
    getline(cin, customInput, '#'); // input ends at '#' character
    cout << "Custom delimited input: " << customInput << endl;

    // 🔄 Reversing a string using std::string and two pointers
    string n;
    cout << "\nEnter a string to reverse: ";
    getline(cin, n);

    cout << "Entered string is: ";
    for (char c : n) cout << c;
    cout << "\nString in reverse: ";

    for (int i = 0, j = n.length() - 1; i < j; i++, j--) {
        swap(n[i], n[j]); // two-pointer reversal
    }

    cout << n << endl;

    return 0;
}
