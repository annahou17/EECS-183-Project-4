/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Anna Hou
 * annahou
 *
 * Project 4: Battleship
 *
 * Function definitions for poisition function
 */

#include "Position.h"
#include "utility.h"


Position::Position() {
    row = 0;
    col = 0;
}

Position::Position(int row_in, int col_in) {
    row = check_range(row_in);
    col = check_range(col_in);
    
}

Position::Position(char row_in, char col_in) {
//    if (check_range(row_in) && check_range(col_in)) {
//        col = toupper(col_in);
//        row = row_in - '1';
//        col = col_in - 'A';
//    }
    
    row_in = check_range(row_in);
    col_in = check_range(col_in);
    
    row = (row_in - '0') - 1;
    col = toupper(col_in);
    col = col_in - 'A';

}

int Position::get_row() {
    return row;
}

void Position::set_row(int row_in) {
    row_in = check_range(row_in);
    row = row_in;
    return;
}

int Position::get_col() {
    return col;
}

void Position::set_col(int col_in) {
    col_in = check_range(col_in);
    col = col_in;
    return;
}

void Position::read(istream &is) {
    char junk;
    is >> row;
    if (is.fail()) {
        is.clear();
        char letter;
        char number;
        is >> junk >> letter >> junk >> number >> junk;
        //turn col into an int
        if (number > 'Z') {
            col = number - 'a';
        }
        else {
            col = number - 'A';
        }
        //turns row from char to int and minus one to get the corrindate value
        row = check_range(letter - '0' - 1);
        col = check_range(col);
    }
    else {
        char number;
        is >> number;
        if (number > 'Z') {
            col = number - 'a';
        }
        else {
            col = number - 'A';
        }
        row = check_range(row - 1);
        col = check_range(col);
        return;
    }
}

void Position::write(ostream &os) {
    os << "(" << row + 1 << "," << static_cast<char>(col + 'A') << ")";
    return;
}

int Position::check_range(int val) {
    if (val >= 0 && val < MAX_GRID_SIZE) {
        return val;
    }
    else if (val < 0) {
        return 0;
    }
    else if (val >= MAX_GRID_SIZE) {
        return MAX_GRID_SIZE - 1;
    }
    return 0;
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












bool Ship::has_position(Position pos) {
    if (is_horizontal()) {
        if ((pos.get_row() == start.get_row() &&
             pos.get_col() >= start.get_col() &&
             pos.get_col() <= end.get_col())) {
            return true;
        }
        if ((pos.get_row() == end.get_row() &&
             pos.get_col() >= end.get_col()&&
             pos.get_col() <= start.get_col())) {
            return true;
        }
    }
    else { //ship is vertical
        if ((pos.get_col() == start.get_col() &&
             pos.get_row() >= start.get_row() &&
             pos.get_row() <= end.get_row())) {
            return true;
            
        }
        if ((pos.get_col() == end.get_col() &&
             pos.get_row() >= end.get_row() &&
             pos.get_row() <= start.get_row())) {
            return true;
        }
    }
    return false;
}

