#include <iostream>
#include <fstream>
#include <string>
#include "ChessBoard.h"

using namespace std;
int main(){
    ChessBoard chess;
    ifstream inputs("chess.txt");
    chess.gameLoop(inputs);
    chess.gameLoop(cin);
}