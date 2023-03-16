/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * Project 4: Battleship
 *
 * <#description#>
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
    row = row_in - '0' - 1;
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
    char junk;
    is >> row;
    if (is.fail()) {
        is.clear();
        char meow;
        char woof;
        is >> junk >> meow >> junk >> woof >> junk;
        if (woof > 'Z') {
            col = woof - 'a';
        }
        else {
            col = woof - 'A';
        }
        row = check_range(meow - '0' - 1);
        col = check_range(col);
    }
    else {
        char meow;
        is >> meow;
        if (meow > 'Z') {
            col = meow - 'a';
        }
        else {
            col = meow - 'A';
        }
        col = check_range(col);
        row = check_range(row - 1);
    }
    return;
}

void Position::write(ostream &os) {
    os << '(' << row + 1 << ',' << char('A' + col) << ')';
    return;
}

int Position::check_range(int val) {
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

