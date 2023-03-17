/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Anna Hou, Durrah  Azdi
 * annahou, durrah
 *
 * Project 4: Battleship
 *
 * Player holds the Player.h functions. Player represents a player in the Battleship game.
 */

#include <fstream>

#include "Player.h"


Player::Player() {
    name = "";
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

Player::Player(string name_val) {
    name = name_val;
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

void Player::init_grid() {
    //loops through row
    for (int row = 0; row < MAX_GRID_SIZE; row++) {
        //loops through col
        for (int col = 0; col < MAX_GRID_SIZE; col++) {
            //sets each element in both grids to EMPTY_LETTER
            grid[row][col] = EMPTY_LETTER;
            guess_grid[row][col] = EMPTY_LETTER;
        }
    }
    return;
}

string Player::get_name() {
    return name;
}

int Player::get_num_ships() {
    return num_ships;
}

int Player::get_remaining_ships() {
    return remaining_ships;
}

char Player::get_grid_at(int row, int col) {
    return grid[row][col];
}

char Player::get_guess_grid_at(int row, int col) {
    return guess_grid[row][col];
}

void Player::add_ship(Ship ship) {
    // checks to see if num_ship
    // has not reached max of 5
    if (num_ships < MAX_NUM_SHIPS) {
        // assigns a ship to a new spot in the array
        // increments num_ships and remaining_ships
        ships[num_ships] = ship;
        num_ships++;
        remaining_ships++;
        if (ship.is_horizontal()) {
            //if ship is horizontal, checks if the starting point
            // comes first or the end
            // adds ship letters from the "start" position
            // and loops until the size of ship is reached
            if (ship.get_start().get_col() < ship.get_end().get_col()) {
                int i = 0;
                while (i < ship.get_size()) {
                    grid[ship.get_start().get_row()]
                        [ship.get_start().get_col() + i] = SHIP_LETTER;
                    i++;
                }
            }
            else {
                int i = 0;
                while (i < ship.get_size()) {
                    grid[ship.get_end().get_row()]
                        [ship.get_end().get_col() + i] = SHIP_LETTER;
                    i++;
                }
            }
        }
        else {
            // same for not horizontal orientation, but
            // instead the row increments now
            if (ship.get_start().get_row() < ship.get_end().get_row()) {
                int i = 0;
                while (i < ship.get_size()) {
                    grid[ship.get_start().get_row() + i]
                        [ship.get_start().get_col()] = SHIP_LETTER;
                    i++;
                }
            }
            else {
                int i = 0;
                while (i < ship.get_size()) {
                    grid[ship.get_end().get_row() + i]
                        [ship.get_end().get_col()] = SHIP_LETTER;
                    i++;
                }
            }
        }
    }
    return;
}

void Player::attack(Player &opponent, Position pos) {
    bool has_hit = false;
    // loops through to check all the ships in
    // the player's array
    for (int i = 0; i < opponent.num_ships; i++) {
        // checks to see if the attack position has a ship there
        // also checks if the position hasn't been hit yet
        if (opponent.ships[i].has_position(pos)
            && guess_grid[pos.get_row()][pos.get_col()] == '-') {
            // changes the grid and guess grid to O (hit letter)
            opponent.grid[pos.get_row()][pos.get_col()] = HIT_LETTER;
            guess_grid[pos.get_row()][pos.get_col()] = HIT_LETTER;
            // calls hit function on the opponent's ship
            opponent.ships[i].hit();
            // updates boolean to true so that the 'miss' message
            // doesn't run when done looping through the ships
            has_hit = true;

            cout << name << " " << pos << " hit" << endl;
            
            // checks if the ship has sunk and decrements the
            // number of ships and announcews it
            if (opponent.ships[i].has_sunk()) {
                opponent.remaining_ships--;
                announce_ship_sunk(opponent.ships[i].get_size());
            }
        }
    }
    // only runs if there were no ships hit
    if (!has_hit) {
        opponent.grid[pos.get_row()][pos.get_col()] = MISS_LETTER;
        guess_grid[pos.get_row()][pos.get_col()] = MISS_LETTER;
        cout << name << " " << pos << " miss" << endl;
    }
    return;
}

void Player::announce_ship_sunk(int size) {
    //prints the corresponding message based on what size ship was sunk
    cout << "Congratulations " << name << "! You sunk a ";
    if (size == 2) {
        cout << "Destroyer\n";
    }
    else if (size == 3) {
        cout << "Submarine\n";
    }
    else if (size == 4) {
        cout << "Battleship\n";
    }
    else {
        cout << "Carrier\n";
    }
    return;
}

bool Player::load_grid_file(string filename) {
    // declaring variables to receive input later on
    Position start_pos;
    Position end_pos;
    // declaring a boolean to see if file was successfully opened
    bool file_opened = false;
    ifstream input_file;
    
    // opening the file
    input_file.open(filename);
    // updating boolean to indicate file has opened
    if (input_file.good()) {
        file_opened = true;
    }
    // getting first inputs from the file
    input_file >> start_pos >> end_pos;
    // while file is sitll in a good state,
    // continues reading data
    while (input_file.good()) {
        // creates and adds a ship based on 
        // the data read
        Ship ship(start_pos, end_pos);
        add_ship(ship);
        // read more data.
        // while loop terminates when it enters a fail state
        input_file >> start_pos >> end_pos;
    }
    if (file_opened) {
        return true;
    }
    input_file.close();

    return false;
}

bool Player::destroyed() {
    //if there is not more ships, then return false
    if (remaining_ships == 0) {
        return true;
    }
    return false;
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
    ::print_grid(grid);
}

void Player::print_guess_grid() {
    ::print_grid(guess_grid);
}
