#include <chrono>
#include <cstddef>
#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <ostream>
#include <stack>
#include <string>
#include <thread>
#include <vector>

bool running = true;

void read_smth(){
    std::cout << "hi, im listening" << std::endl;
    std::string msg;
    while (running){
        std::getline(std::cin, msg);
        std::cout << msg << std::endl;

        if (msg == "q"){
            running = false;
            return;
        }
    }
}

void print_smth(){
    while (running){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "smth" << std::endl;
    }
}

const int SIZE = 8;

enum Color { white, black };
enum PieceType { Rook, Bishop, Knight, Queen, King, Pawn, none };
enum MoveType { Illegal, Move, Capture, Enroque, Promocion };
enum PieceLetter {p, r, b, n, k, q, P, R, B, N, K, Q};

struct Piece {
    PieceType piece;
    Color color;

    Piece(): piece(Pawn), color(black) {}
    Piece(PieceType p, Color c): piece(p), color(c) {}
};

struct Position {
    int x;
    int y;

    Position(int x, int y): x(x), y(y) {}
};

struct Board {
    std::vector<std::vector<char>> board;
};

std::unordered_map<char, Piece> piece_to_board = {
    {'p', Piece(Pawn, black)},
    {'b', Piece(Bishop, black)},
    {'r', Piece(Rook, black)},
    {'n', Piece(Knight, black)},
    {'q', Piece(Queen, black)},
    {'k', Piece(King, black)},

    {'_', Piece(none, white)},

    {'P', Piece(Pawn, white)},
    {'B', Piece(Bishop, white)},
    {'R', Piece(Rook, white)},
    {'N', Piece(Knight, white)},
    {'Q', Piece(Queen, white)},
    {'K', Piece(King, white)}
};

Piece piece_at(Position pos, Board board){
    char piece = board.board.at(pos.y).at(pos.x);

    return piece_to_board[piece];
}

class Game {
private:
    Board board;
    Color turn;
    std::stack<std::string> moves;


public:
    Game(){
	board = {{
		{'r', 'b', 'n', 'q', 'k', 'n', 'b', 'r'},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{'_', '_', '_', '_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_', '_', '_', '_'},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		{'R', 'B', 'N', 'Q', 'K', 'N', 'B', 'R'}
	}};

	turn = white;
    }

    Board get_board(){
	return board;
    }
};





int main(){
    Game game;
    Piece p = piece_at(Position(0, 2), game.get_board());

    std::cout << p.piece << std::endl;

    std::thread m(read_smth);
    std::thread t(print_smth);

    t.join();
    m.join();

    std::cout << "Hello World" << std::endl;
    return 0;
}
