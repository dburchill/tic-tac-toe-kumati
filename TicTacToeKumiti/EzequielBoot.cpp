/*
* author  Ezequiel Flores Schmelensky
* email   efloresschmelensky@mynbcc.ca
*
* @section DESCRIPTION
* Homework11
* TicTacToc3
*
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*/
//  1 | 2 | 3
// --- --- ---
//  4 | 5 | 6
// --- --- ---
//  7 | 8 | 9
#include "EzequielBoot.h"

EzequielBoot::EzequielBoot(Piece p): Player(p) {}

bool EzequielBoot::makeMove(Board& board) const {
    if (board.isBlank()) {
        board.placePiece(getMyPiece(), 1);
        return true;
    }
        
    if (board.pieceOfKind(getOpponentPiece()) == 1) {
        if (board.hasCenter(getOpponentPiece())) {
            if (board.pieceOfKind(getMyPiece()) == 1) {
                board.placePiece(getMyPiece(), 9); return true;
            } else {
                board.placePiece(getMyPiece(), 2); return true;
            }
        } else {
            if (!board.hasCenter(getMyPiece())) {
                board.placePiece(getMyPiece(), 5); return true;
            } else {
                if (board.isLegalMove(9)) {
                    board.placePiece(getMyPiece(), 9); return true;
                } else if (board.isLegalMove(3)) {
                    board.placePiece(getMyPiece(), 3); return true;
                } else if (board.isLegalMove(7)) {
                    board.placePiece(getMyPiece(), 7); return true;
                } else {
                    board.placePiece(getMyPiece(), 1); return true;
                }
            }
        }   
    }

    board.placePiece(getMyPiece(), board.bestNextPos(getMyPiece()));
        
    return true;
}
