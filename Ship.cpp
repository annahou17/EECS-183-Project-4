/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Anna Hou, Durrah  Azdi
 * annahou, durrah
 *
 * Project 4: Battleship
 *
 * Ship holds all the functions for Ship,h. Ship represents a ship in the Battleship game.
 */

#include <cmath>

#include "Ship.h"

Ship::Ship() {
    start.set_row(0);
    start.set_col(0);
    end.set_row(0);
    end.set_col(0);
    size = 0;
    num_hits = 0;
}

Ship::Ship(Position start_in, Position end_in) {
    start = start_in;
    end = end_in;
    num_hits = 0;
    if (is_horizontal()) {
        //gets the start and end of the ships and subtracts them. then takes the absolute value
        size = abs(start.get_col() - end.get_col()) + 1;
    }
    //if ship is vertical
    else {
        size = abs(start.get_row() - end.get_row()) + 1;
    }
}

Position Ship::get_start() {
    return start;
}

Position Ship::get_end() {
    return end;
}

int Ship::get_size() {
    return size;
}

bool Ship::is_horizontal() {
    //checks to make sure the start and end are in the same row
    if (start.get_row() == end.get_row()) {
        return true;
    }
    else {
        return false;
    }
}

bool Ship::has_position(Position pos) {
    if (is_horizontal()) {
        //checks if the pos is in the same row as the starting value
        if ((pos.get_row() == start.get_row() &&
             //checks if the pos is in between the start and end col values
            pos.get_col() >= start.get_col() &&
            pos.get_col() <= end.get_col())) {
            return true;
        }
    }
    //ship is vertical
    else {
        //checks if the pos is in the same col as the starting value
        if ((pos.get_col() == start.get_col() &&
             //checks if the pos is in between the start and end row values
            pos.get_row() >= start.get_row() &&
            pos.get_row() <= end.get_row())) {
            return true;
        }
    }
    return false;
    
}

void Ship::hit() {
    /*checks the number of hits and makes sure it is less than size. if so
    increase num_hits*/
    if (num_hits < size) {
        num_hits++;
    }
}

bool Ship::has_sunk() {
    if (num_hits == size) {
        return true;
    }
    else {
        return false;
    }
}
