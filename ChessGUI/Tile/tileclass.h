#ifndef TILECLASS_H
#define TILECLASS_H

#include <QLabel>
#include <QDebug>
#include <QPainter>

class Tile: public QLabel{
public:
    int tileColor;
    pair<int, int> position;
    string piece;

    Tile(QWidget* pParent = 0, Qt::WindowFlags f = 0): QLabel(pParent, f){};

    Tile(const QString& text, QWidget* pParent = 0, Qt::WindowFlags f = 0): QLabel(text, pParent, f){};


    void mousePressEvent(QMouseEvent *ev);

    void display(){
        this->setAlignment(Qt::AlignCenter);
        if(this->piece != ""){
            if(this->piece[0] == 'W'){
                switch(this->piece[1]){
                    case 'P':   this->setPixmap(QPixmap(":/Images/pawn_white.svg"));
                                break;
                    case 'R':   this->setPixmap(QPixmap(":/Images/rook_white.svg"));
                                break;
                    case 'N':   this->setPixmap(QPixmap(":/Images/knight_white.svg"));
                                break;
                    case 'K':   this->setPixmap(QPixmap(":/Images/king_white.svg"));
                                break;
                    case 'Q':   this->setPixmap(QPixmap(":/Images/queen_white.svg"));
                                break;
                    case 'B':   this->setPixmap(QPixmap(":/Images/bishop_white.svg"));
                                break;
                }
            } else{
                switch(this->piece[1]){
                    case 'P':   this->setPixmap(QPixmap(":/Images/pawn_black.svg"));
                                break;
                    case 'R':   this->setPixmap(QPixmap(":/Images/rook_black.svg"));
                                break;
                    case 'N':   this->setPixmap(QPixmap(":/Images/knight_black.svg"));
                                break;
                    case 'K':   this->setPixmap(QPixmap(":/Images/king_black.svg"));
                                break;
                    case 'Q':   this->setPixmap(QPixmap(":/Images/queen_black.svg"));
                                break;
                    case 'B':   this->setPixmap(QPixmap(":/Images/bishop_black.svg"));
                                break;
                }
            }
        }
        else
            this->setPixmap(QPixmap());
    }

    void tileDisplay(){
        if(this->tileColor)
            this->setStyleSheet("QLabel {background-image: url(\":/Images/marble-piece-black.png\"); border: 1px;}");
        else
            this->setStyleSheet("QLabel {background-image: url(\":/Images/marble-piece-white.png\"); border: 1px;}");
    }
};

#endif // TILECLASS_H
