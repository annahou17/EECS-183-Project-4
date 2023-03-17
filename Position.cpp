/**
* Copyright 2019 University of Michigan EECS183
*
* Position.cpp
* Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
*
*   Anna Hou, Durrah  Azdi
 * annahou, durrah
*
* Project 4: Battleship
*
* Position.cpp holds the functions of Position.h. Positions represent ships and moves.
*/

#include "Position.h"
#include "utility.h"

//sets position origin to 0,0
Position::Position() {
   row = 0;
   col = 0;
}

Position::Position(int row_in, int col_in) {
   row = check_range(row_in);
   col = check_range(col_in);
}

Position::Position(char row_in, char col_in) {
    //turn row into integer and subtract one to get proper interger position
    row = row_in - '0' - 1;
    /*checks if col_in is an upper or lower case letter and subtracts it by
    its case letter to get the interger value*/
    if (col_in > 'Z') {
        col = col_in - 'a';
    }
    else {
        col = col_in - 'A';
    }
    row = check_range(row);
    col = check_range(col);
}

int Position::get_row() {
   return row;
}

void Position::set_row(int row_in) {
   row = check_range(row_in);
   return;
}

int Position::get_col() {
   return col;
}

void Position::set_col(int col_in) {
   col = check_range(col_in);
   return;
}

void Position::read(istream &is) {
    //create a variable to hold unneeded characters
    char junk;
    is >> row;
    //checks if in a fail state
    if (is.fail()) {
        //resets the error
        is.clear();
        //new variables to hold the values we want to keep (number and letter)
        char new_row;
        char new_col;
        //reads in (1,A) instead of 1A
        is >> junk >> new_row >> junk >> new_col >> junk;
       
        if (new_col > 'Z') {
            col = new_col - 'a';
        }
       else {
            col = new_col - 'A';
        }
        //turns row and col into its interger value
        row = check_range(new_row - '0' - 1);
        col = check_range(col);
    }
    //not in a fail state
    else {
       //gets the data in 1A form
       char new_row;
       is >> new_row;
       if (new_row > 'Z') {
           col = new_row - 'a';
       }
       else {
           col = new_row - 'A';
       }
       col = check_range(col);
       row = check_range(row - 1);
   }
   return;
}

void Position::write(ostream &os) {
    //displays the coordinates in form (1,A)
    os << '(' << row + 1 << ',' << char('A' + col) << ')';
   return;
}

int Position::check_range(int val) {
    //makes sure val is in the range [0, MAX_GRID_SIZE]
   if (val >= 0 && val < MAX_GRID_SIZE) {
       return val;
   }
   else if (val < 0) {
       return 0;
   }
   else {
       return MAX_GRID_SIZE - 1;
   }
}


// Your code goes above this line.
// Don't change the implementations below!

istream &operator>>(istream &is,  Position &pos) {
   pos.read(is);
   return is;
}

ostream &operator<<(ostream &os, Position pos) {
   pos.write(os);
   return os;
}
