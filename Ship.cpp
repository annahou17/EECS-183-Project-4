/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * Project 4: Battleship
 *
 * <#description#>
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
        size = abs(start.get_col() - end.get_col()) + 1;
    }
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
    if (start.get_row() == end.get_row()) {
        return true;
    }
    else {
        return false;
    }
}

bool Ship::has_position(Position pos) {
    if (is_horizontal()) {
        if ((pos.get_row() == start.get_row() &&
            pos.get_col() >= start.get_col() &&
            pos.get_col() <= end.get_col())) {
            return true;
        }
        if ((pos.get_row() == end.get_row() &&
            pos.get_col() >= end.get_col() &&
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

void Ship::hit() {
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
