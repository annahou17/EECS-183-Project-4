/**
 * start.cpp
 *
 * EECS 183
 * Lab 7: Classes
 *
 */

#include <iostream>
#include <string>

using namespace std;

//********************************************************
// Function declarations. 
// Function definitions are in test.cpp
//********************************************************
void startTests();

int main() {
    
    cout << "----------------------------------------" << endl
         << "EECS 183 Lab Menu Options" << endl
         << "----------------------------------------" << endl;
    cout << "1) Execute testing functions in test.cpp" << endl;    
    cout << "Choice --> ";

    int choice;
    cin >> choice;

    // remove the return character from the cin stream buffer
    string junk;
    getline(cin, junk);

    if (choice == 1) {
        startTests();
    }
    
    return 0;
}
