#include <iostream>
#include <iomanip>
#include <string>
#include "ChessBoard.h"
#include "ChessPieces.h"

using namespace std;

string getColorName( Color c, bool shortVersion = true){
    switch(c){
        case White:
            if (shortVersion)
                return "W";
            else
                return "White";
        case Black:
            if (shortVersion)
                return "B";
            else
                return "Black";
    }
    return "U"; //return unknown
}

string getChessPieceName(PieceType ct, bool shortVersion = true){
    switch(ct){
        case Pawn:
            if(shortVersion)
                return "P";
            else
                return "Pawn";
        case Rook:
            if (shortVersion)
                return "R";
            else
                return "Rook";
        case Queen:
            if (shortVersion)
                return "Q";
            else
                return "Queen";
        case Knight:
            if(shortVersion)
                return "Kn";
            else
                return "Knight";
        case Bishop:
            if(shortVersion)
                return "B";
            else
                return "Bishop";
        case King:
            if (shortVersion)
                return "K";
            else
                return "King";
    }
    return "U";
}
ChessPieces::~ChessPieces() {}
ChessPieces::ChessPieces(PieceType pt, Color colorParameter, int rowsParameter, int columns1Parameter){
    pieceType = pt;
    colour = colorParameter;
    rows = rowsParameter;
    columns = columns1Parameter;
}
bool ChessPieces::position(int rowsParameter, int columns1Parameter){
    if (rows == rowsParameter && columns == columns1Parameter)
        return true;
    else
        return false;
}
string ChessPieces::getId(){
    string retval = getColorName(colour) +
                        getChessPieceName(pieceType);
    return retval;
}
string ChessPieces::getName(){
    string retval = getColorName(colour, false) + 
                        getChessPieceName(pieceType, false);
    return retval;
}
void ChessPieces::setCapture(){
    rows = -1;
    columns = -1;
}
bool ChessPieces::isCapture(){
    if (rows < 0 || columns < 0)
        return true;
    else
        return false;
}
Color ChessPieces::getColor(){
    return colour;
}
bool ChessPieces::move(int rowsParameter, int columns1Parameter){
    int deltaRow = abs(rowsParameter - rows);
    int deltaCol = abs(columns1Parameter - columns);
    if (deltaRow != deltaCol)
        return Illegal;
    if (deltaRow == 0 || deltaRow >2)
        return Illegal;
    if (pieceType == Rook){
        if (color == Black && rowsParameter < rows)
            return Illegal;
        if (color == White && rowsParameter > rows)
            return Illegal;
    }
    if (deltaRow == 2)
        return true;
    else
        return false;
}

Color ChessPieces::getColor(){
    return colour;
}
bool ChessPieces::move(int rowsParameter, int columns1Parameter){
    int deltaRow = abs(rowsParameter - rows);
    int deltaCol = abs(columns1Parameter - columns);
    if (deltaRow == 0 || deltaRow > 2)
        return Illegal;
    if (deltaRow != deltaCol)
        return Illegal;
    if (pieceType == Rook){
        if (colour == Black && rowsParameter < rows)
            return Illegal;
        if (colour == White && rowsParameter > rows)
            return Illegal;
    }
    if (deltaRow == 2)
        return Capture;
    else
        return Normal;
}

ChessBoard::ChessBoard(){
    PieceType kingRow[] = {Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook};
    int index = 0;
    for (int columns = 0; columns < numcols; columns++){
        chessPieces[index++] = 
        ChessPieces (kingRow[columns], Black, 0, columns);
        chessPieces[index++] = 
        ChessPieces (kingsRow[columns], White, 7, columns);
        chessPieces[index++] = 
        ChessPieces (Pawn, Black, 1, columns);
        chessPieces[index++] =
        ChessPieces (Pawn, White, 6, columns);
    }
}

int ChessBoard::findPieceAt(int rows, int columns){
    for (int i = 0; i < numchesspieces; i++){
        if (chessPieces[i].position(rows, columns))
        return i;
    }
    return -1;
}
bool ChessBoard::move(Color turns, int oldRows, int oldCols, int newRows, int newCols){
    if (newRows < 0 || newCols < 0 || newRows >= numrows || newCols >= numcols){
        cout << "Illegal area to move. Does not follow...\n";
        return Illegal;
    }
    int index =findPieceAt(oldRows, oldCols);
    if (index < 0){
        cout << "Nothing is there at location of board...\n";
        return Illegal;
    }
    int indexOther = findPieceAt(newRows, newCols);
    if(indexOther >= 0){
        cout << "There is something in the way of that spot...\n";
        return Illegal;
    }
    bool mvType = chessPieces[index].move(newRows, newCols);
    switch (mvType){
        case Illegal:
            cout << "Move is illegal for specific piece...\n";
            return Illegal;
        case Normal:
            chessPieces[index].captureMove(newRows, newCols);
            return Normal;
    }
    int captureRow = (oldRows + newRows)/2;
    int captureCol = (oldRows + newRows)/2;
    indexOther = findPieceAt(captureRow, captureCol);
    if (indexOther < 0){
        cout << "Capture move. but no pieces to jump over...\n";
        return Illegal;
    }
    if (chessPieces[index].getColor() ==
                    chessPieces[indexOther].getColor()){
                        cout << "cannot get your own piece...\n";
                        return Illegal;
    }
    chessPieces[indexOther].setCapture();
    chessPieces[index].captureMove(newRows, newCols);
        return Capture;
}
void ChessPieces::gameLoop (istream & inputs){
    Color turns = Black;
    int curRow, curCol, newRows, newCols;
    bool continueRunning = true;
    displayBoard();
    while (continueRunning){
        cout << getColorName(turns, false) << "'s turn!\n";
        cout << "Enter curRow curCol newRows newCols :" << endl;
        inputs>> curRow >> curCol >> newRows >> newCols;
        if (!inputs || curRow < 0){
            cout << "Exiting Game Loop\n";
            continueRunning = false;
        }
        else {
            if (move (turns, curRow, curCol, newRows, newCols)){
                displayBoard();
                if(turns == Black)
                    turns = White;
                else
                    turns = Black;
            }
            else{
                cout << "Try again. Bad move...\n";
            }
        }
    }
}
void ChessBoard::displayBoard(){
    cout << "\n************************" << endl << " ";
    for (int c = 0; c < numcols; c++)
        cout << setw(4) << c;
        cout << endl;
    for (int r = 0; r < numrows; r++){
        cout << "--------------------------" << endl;
        cout << r << ": |";
        cout << setfill(' ') << right;
        for (int c = 0; c < numcols; c++){
            int index = findPieceAt(r,c);
            if (index < 0)
                cout << "   |";
            else
                cout << setw(3) << chessPieces[index].getId() << '|';
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
    cout << "Capture Peices: ";
    for (int i = 0; i < numchesspieces; i++){
        if (chessPieces[i].isCapture())
        cout << setw(3) << chessPieces[i].getId();
    }
    cout << endl << "*********************************" << endl;
}