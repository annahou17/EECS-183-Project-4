/**
 * test.cpp
 *
 * EECS 183
 * Lab 7: Classes
 *
 * <#Name#>
 * <#uniqname#>
 *
 * <#Description#>
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Position.h"
#include "utility.h"

void test_position();
void test_position_read();

void startTests() {
    test_position();
    test_position_read();

    return;
}

void test_position() {
    // testing Position default constructor here
    Position start_pos;
    Position end_pos;
    cout << "Testing Position::Position() - default constructor\n";
    cout << "start_pos, expected output: (1,A) actual output: " << start_pos << endl;
    cout << "end_pos, expected output: (1,A) actual output: " << end_pos << endl;
    
    // testing Position setters here
    start_pos.set_row(4);
    start_pos.set_col(5);
    cout << "\nTesting Position::set_row() and Position::set_col()\n";
    cout << "start_pos, expected output: (5,F) actual output: " << start_pos << endl;
    
    // testing Position read
    ifstream input_file;
    input_file.open("grid1.txt");
    if (input_file.good()) {

        // can use the Position::read() function directly
        start_pos.read(input_file);

        // or use the extraction operator
        input_file >> end_pos;

        cout << "\nTesting Position::read()\n";
        cout << "start_pos, expected output: (1,A) actual output: " << start_pos << endl;
        cout << "end_pos, expected output: (4,A) actual output: " << end_pos << endl;
    }
    else {
        cout << "\nError opening grid1.txt\n";
    }
  
    return;
}

void test_position_read() {
    cout << "Testing check_range: ";
    Position test(0,8);
    test.write(cout);
    cout << endl;
    Position test2(7,9);
    test2.write(cout);
    cout << endl;
    
    Position something;
    something.set_row(3);
    ifstream in_file;
    in_file.open("grid1.txt");
    if (in_file.good()) {
        something.read(in_file);
    }
}
