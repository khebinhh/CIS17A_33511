//I use pragma once because I use the vs ide for my coding
/*#pragma once*/
#ifndef ChessBoard_h
#define ChessBoard_h

using namespace std;
#include <string>


enum Color {White, Black};

/*class ChessPieces{
    public:
        ChessPieces(PieceType pt, Color colorParameter,
                                    int columns1Parameter);
        bool move(int rowsParameter, int columns1Parameter);
        bool captureMove(int rowsParameter, int columns1Parameter);
        bool position (int rowsParameter, int columns1Parameter);
        string getId();
        string getName();
        void setCapture();
        bool isCapture();
        Color getColor();
    private:
        int rows, columns;
        Color colour;
        PieceType pieceType;
};*/

class ChessBoard{
    public:
        ChessBoard();
        void displayBoard();
        int findPieceAt(int rows, int columns);
        bool move (Color turns, int oldRows, int coldCols, int newRows, int newCols);
        void gameLoop(istream & inputs);
    private:
        static const int numrows=8, numcols=8;
        static const int numchesspieces=32;
        ChessPieces chessPieces[numchesspieces];
};
#endif