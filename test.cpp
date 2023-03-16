/**
 * Copyright 2019 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Project 4: Battleship
 *
 * Contains functions for testing classes in the project. 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


void test_position();
void test_ship();
void test_player();
void test_game();

void startTests() {
    test_position();
    test_ship();
    test_player();
    test_game();
    
    return;
}

void test_position() {
    // testing Position default constructor here
    Position start_pos;
    Position end_pos;
    cout << "Testing Position::Position() - default constructor\n";
    cout << "start_pos, expected output: (1,A) actual output: " << start_pos << endl;
    cout << "end_pos, expected output: (1,A) actual output: " << end_pos << endl;
    cout << endl;

    // testing Position non-default contructors
    Position p1(3, 9);
    Position p5(-6, 100);
    cout << "Testing Position::Posititon(int row_in, int col_in)" << endl;
    cout << "p1, expected output: (4,H), actual output: " << p1 << endl;
    cout << "p5, expected output: (1,H), actual output: " << p5 << endl;
    cout << endl;

    Position p2('3', 'a');
    Position p3('7', 'D');
    Position p4('9', 'J');
    cout << "Testing Position::Position(char row_in, char col_in) constructor" << endl;
    cout << "p2, expected output: (3,A), actual output: " << p2 << endl;
    cout << "p2, expected output: (7,D), actual output: " << p3 << endl;
    cout << "p3, expedted output: (8,H), actual output: " << p4 << endl;
    cout << endl;

    // testing Position setters here
    start_pos.set_row(7);
    start_pos.set_col(5);
    cout << "\nTesting Position::set_row() and Position::set_col()\n";
    cout << "start_pos, expected output: (8,F) actual output: " << start_pos << endl;

    start_pos.set_row(4);
    start_pos.set_col(10);
    cout << "start_pos, expected output: (5,H) actual output: " << start_pos << endl;

    // testing get positions here
    cout << "Testing get_row and get_col" << endl;
    cout << "p2, expected: 20, actual: " << p2.get_row() << p2.get_col();

    // testing Position read
    ifstream input_file;
    input_file.open("grid1.txt");
    if (input_file.good()) {

        // can use the Position::read() function directly
        start_pos.read(input_file);
        // or use the extraction operator
        input_file >> end_pos;

        cout << "\nTesting Position::read()\n";
        cout << "start_pos, expected output: (3,B) actual output: " << start_pos << endl;
        cout << "end_pos, expected output: (8,H) actual output: " << end_pos << endl;

        start_pos.read(input_file);
        input_file >> end_pos;

        cout << "start_pos, expected output: (3,A) actual output: " << start_pos << endl;
        cout << "end_pos, expected output: (8,A) actual output: " << end_pos << endl;

        start_pos.read(input_file);
        input_file >> end_pos;

        cout << "start_pos, expected output: (4,D) actual output: " << start_pos << endl;
        cout << "end_pos, expected output: (5,D) actual output: " << end_pos << endl;

        start_pos.read(input_file);
        input_file >> end_pos;

        cout << "start_pos, expected output: (8,G) actual output: " << start_pos << endl;
        cout << "end_pos, expected output: (8,E) actual output: " << end_pos << endl;

        start_pos.read(input_file);
        input_file >> end_pos;

        cout << "start_pos, expected output: (6,G) actual output: " << start_pos << endl;
        cout << "end_pos, expected output: (6,D) actual output: " << end_pos << endl;
        cout << endl;
    }
    else {
        cout << "\nError opening grid1.txt\n";
    }
    return;
}

void test_ship() {
    // testing default ship constructor here
    Ship s1;
    cout << "Testing Ship::Ship() - default constructor\n";
    cout << "s1 position testing, expected: (1,A) (1,A), actual: ";
    cout << s1.get_start() << " " << s1.get_end() << endl;
    cout << "s1 size testing, expected: 0, actual: " << s1.get_size() << endl;
    cout << endl;

    // testing non-default ship constructor here
    Position p2('3', 'a');
    Position p3('3', 'D');
    Ship s2(p2, p3);
    cout << "Testing Ship::Ship(Position start_in, Position end_in)\n";
    cout << "s2 position testing, expected: (3,A) (3,D), actual: ";
    cout << s2.get_start() << " " << s2.get_end() << endl;
    cout << "s2 size testing, expected: 4, actual: " << s2.get_size() << endl;
    cout << endl;

    Position p4('7', 'D');
    Position p5('3', 'D');
    Ship s3(p4, p5);
    cout << "Testing Ship::Ship(Position start_in, Position end_in)\n";
    cout << "s3 position testing, expected: (7,D) (3,D), actual: ";
    cout << s3.get_start() << " " << s3.get_end() << endl;
    cout << "s3 size testing, expected: 5, actual: " << s3.get_size() << endl;
    cout << endl;

    // testing has_position function
    Position p6('3', 'B');
    Position p7('5', 'D');
    cout << "Testing has_position()" << endl;
    cout << "s2 has_position testing (3,B), expected: 1, actual: "
        << s2.has_position(p6) << endl;

    cout << "s2 has_position testing (7,D), expected: 0, actual: "
        << s2.has_position(p4) << endl;

    cout << "s3 has_position testing (5,D), expected: 1, actual: "
        << s3.has_position(p7) << endl;

    cout << "s3 has_position testing (7,D), expected: 1, actual: "
        << s3.has_position(p4) << endl;

    cout << "s3 has_position testing (3,B), expected: 0, actual: "
        << s3.has_position(p6) << endl;
    cout << endl;

    // testing hit function here
    cout << "Testing hit() and has_sunk() function" << endl;
    s2.hit();
    cout << "s2 num_hits < size, expected: 0, actual: " << s2.has_sunk() << endl;
    s2.hit();
    s2.hit();
    s2.hit();
    cout << "s2 num_hits == size, expected: 1, actual: " << s2.has_sunk() << endl;
    s2.hit();
    cout << "s2 num_hits == size, expected: 1, actual: " << s2.has_sunk() << endl;
    cout << endl;

    return;
}

void test_player() {
    // testing Player functions here

    // testing Player::Player() default constructor here
    Player player1;
    cout << "Testing Player::Player() default constructor: \n";
    player1.print_grid();
    player1.print_guess_grid();
    cout << "player 1 name, expected: empty string, actual: " 
        << player1.get_name() << endl;
    cout << "player 1 num_ships, expected: 0, actual: " 
        << player1.get_num_ships() << endl;
    cout << "player 1 remaining_ships, expected: 0, actual: "
        << player1.get_remaining_ships();

    // testing non-default constructor here
    Player player2("Ahmad");
    cout << "\nTesting Player::Player(string name_val) non-default constructor:\n";
    player2.print_grid();
    player2.print_guess_grid();
    cout << "player 2 name, expected: Ahmad, actual: "
        << player2.get_name() << endl;
    cout << "player 2 num_ships, expected: 0, actual: "
        << player2.get_num_ships() << endl;
    cout << "player 2 remaining_ships, expected: 0, actual: "
        << player2.get_remaining_ships();
    cout << endl;

    // testing add_ship() function here
    cout << "\nTesting add_ship() function here:\n";
    // creating positions
    Position pos1('1', 'A');
    Position pos2('1', 'C');
    Position pos3('4', 'F');
    Position pos4('7', 'F');
    Position pos5('1', 'B');
    Position pos6('1', 'D');

    // creating ships
    Ship ship1(pos1, pos2);
    Ship ship2(pos2, pos1);
    Ship ship3(pos3, pos4);
    Ship ship4(pos4, pos3);
    Ship ship5(Position('6', 'A'), Position('6', 'C'));
    Ship ship6(Position('1', 'H'), Position('4', 'H'));
    Ship ship7(Position('3', 'B'), Position('3', 'D'));
    Ship ship8(Position('7', 'H'), Position('5', 'H'));

    // player 2 add_ship()
    player2.add_ship(ship1);
    player2.add_ship(ship3);

    // player 1 add_ship()
    player1.add_ship(ship2);
    player1.add_ship(ship4);
    player1.add_ship(ship5);
    player1.add_ship(ship6);
    player1.add_ship(ship7);
    player1.add_ship(ship8);

    cout << "player 2 num_ships, expected: 2, actual: " << player2.get_num_ships();
    cout << "\nPrinting player 2 grid: \n";
    player2.print_grid();
    cout << "\nplayer 1 num_ships, expected: 5, actual: " << player1.get_num_ships();
    cout << "\nPrinting player 1 grid: \n";
    player1.print_grid();
    
    // testing attack() function here

    cout << "\nTesting Player::attack() function\n";
    cout << "Player 2 attacks player 1 at (1,A) (1,B) and (1,C)" << endl;
    player2.attack(player1, pos1);
    player2.attack(player1, pos2);
    player2.attack(player1, pos5);
    cout << "Player 2 attacks player 1 at (1,D) adn (1,A), expected miss" << endl;
    player2.attack(player1, pos6);
    player2.attack(player1, pos1);
    cout << "Player 1's grid\n";
    player1.print_grid();
    cout << "Player 2's guess grid\n";
    player2.print_guess_grid();
    cout << "player 1 remaining_ships, expected: 4, actual: " << player1.get_remaining_ships();

    // testing load_grid_file here

    cout << "\nTesting Player::load_grid_file function\n";
    Player player3("Zalula");
    Player player4("Rooster");
    cout << "Boolean value, expected: 1, actual: " << player3.load_grid_file("grid1.txt") << endl;
    player3.print_grid();

    cout << "Boolean value, expedted: 1, actual: " << player4.load_grid_file("grid2.txt") << endl;
    player4.print_grid();

    Player player5("Empty man");
    cout << "Testing an empty file, expected: 0, actual: "
        << player5.load_grid_file("asijvn.txt") << endl;
    player5.print_grid();
    cout << endl;

}

void test_game() {
    // testing Gane class functions here
    cout << "\nTesting Game::Game() non-default constructor here\n";
    cout << "Expected: Jason generated random grid, Medea use grid1\n";
    Player player1("Jason");
    Player player2("Medea");
    Game game1(player1, "", player2, "grid2.txt");
    cout << "Jason's grid: \n";
    game1.get_p1().print_grid();
    cout << "Medea's grid \n";
    game1.get_p2().print_grid();

    // testing Game check_valid_move() here

    cout << "\nTesting Game::check_valid_move\n";
    cout << "1a, expected: 1, actual: " << game1.check_valid_move("1a") << endl;
    cout << "9E, expected: 0, actual: " << game1.check_valid_move("9E") << endl;
    cout << "4E, expected: 1, actual: " << game1.check_valid_move("4E") << endl;
    cout << "3P, expected: 0, actual: " << game1.check_valid_move("3P") << endl;
    cout << "alksdfhj, expected: 0, actual: " << game1.check_valid_move("adfhjkn;skdlf") << endl;

    // testing getter functions here

    cout << "\nTesting get player functions\n";
    cout << "Player 1 name, expected: Jason, actual: " << game1.get_p1().get_name() << endl;
    cout << "Player 2 name, expected: Medea, actual: " << game1.get_p2().get_name() << endl;

    cout << "\nTesting get move function\n";
    string move = game1.get_move(game1.get_p1().get_name());
    cout << move;

    return;
}

