// functions are synthesized by the compiler
#include<iostream>
using namespace std;

class GameBoard {
public:
    GameBoard() { cout << "GameBoard()\n" << endl; }
    GameBoard(const GameBoard&) { cout << "GameBoard(GameBoard&)" << endl; }
    GameBoard& operator= (const GameBoard&) {
        cout << "GameBoard::operator=()" << endl;
        return *this;
    }
    ~GameBoard() { cout << "~GameBoard()" << endl; }
};

class Game {
    GameBoard gb; // compsition
public:
    // Default GameBoard constructor called
    Game() { cout << "Game()" << endl; }

    // GameBoard copy constructor must be explicitly called
    // or the default constructor will be called
    Game(const Game& g): gb(g.gb) {
        cout << "Game(const Game&)" << endl;
    }

    Game(int) { cout << "Game(int)" << endl; }

    Game& operator= (const Game& g) {
        // must explicitly call the GameBoard = operator
        // or no assignment happen for gb
        gb = g.gb;
        cout << "Game::operator=()" << endl;
        return *this;
    }

    class Other {}; // nested class
    // automatic type conversion
    operator Other() const {
        cout << "Game::Other()" << endl;
        return Other();
    }
    ~Game() { cout << "~Game()" << endl; };
};

class Chess : public Game {};

void f(Game::Other) {};

class Checkers : public Game {
public:
    // Default base-class constructor called
    Checkers() { cout << "Checkers()" << endl; }
    // must explicitly call the base-class copy-constructor
    Checkers(const Checkers& c) : Game(c) {
        cout << "Checkers(const Checkers& c)" << endl;
    }

    Checkers& operator=(const Checkers& c) {
        Game::operator=(c);
        cout << "Checkers::operator=()" << endl;
        return *this;
    }
};

int main() {
    Chess d1; // Default constructor
    Chess d2(d1); // Default Copy-constructor // use Game(const Game&)

    d1 = d2; // operator synthesized // Game::operator=
    f(d1); // type conversion

    Game::Other go;
    // d1 = go; // operator= not synthesized // only the same type works
    Checkers c1, c2(c1);
    c1 = c2;
}
