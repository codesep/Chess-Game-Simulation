#ifndef VALIDATIONCLASS_H
#define VALIDATIONCLASS_H

class Validation{
public:
    Validation(){}
    void choosePiece(Tile *tmp);
    void validatePawn(Tile *tmp);
    void validateRook(Tile *tmp);
    void validateBishop(Tile *tmp);
    void validateKnight(Tile *tmp);
    void validateQueen(Tile *tmp);
    void validateKing(Tile *tmp);
};

#endif // VALIDATIONCLASS_H
