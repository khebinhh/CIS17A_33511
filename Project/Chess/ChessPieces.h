#ifndef ChessPiece_h
#define ChessPiece_h

/*#pragma once*/
#include <string>
using namespace std;


enum PieceType {Pawn, Rook, Knight, Bishop, Queen, King};

class ChessPieces{
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
};

#endif