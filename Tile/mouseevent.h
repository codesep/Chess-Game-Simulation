#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H
#include "Validation/validationclass.h"

extern Tile *tile[9][9];
extern int countClicks;
bool turn = 1;
Validation *valid = new Validation();
extern vector<pair<int, int> > possibleMoves;
void validateMouseEvent(Tile *tmp);

void Tile::mousePressEvent(QMouseEvent *event){
    countClicks += 1;
    validateMouseEvent(this);
}

void backToNormal(){
    for(int i = 0; i < possibleMoves.size(); i++){
        int r = possibleMoves[i].first;
        int c = possibleMoves[i].second;
        tile[r][c]->tileDisplay();
        tile[r][c]->display();
    }
    possibleMoves.clear();
}

void validateMouseEvent(Tile *tmp){
    if(turn == 0){
        countClicks = 0;
        return;
    }

    if(countClicks == 1){
        if(tmp->piece[0] != 'W'){
            countClicks = 0;
            return;
        }

        valid->choosePiece(tmp);

    }
    else{
        if(tmp->piece[0] == 'W'){
            backToNormal();
            countClicks = 1;
            if(possibleMoves[0] == tmp->position){
                countClicks = 0;
                return;
            }
            valid->choosePiece(tmp);
            return;
        }

        bool flag = 0;

        for(int i = 1; i < possibleMoves.size(); i++){
            if(possibleMoves[i] == tmp->position){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            countClicks = 1;
            return;
        }


        for(int i = 0; i < possibleMoves.size(); i++){

            int r = possibleMoves[i].first;
            int c = possibleMoves[i].second;

            tile[r][c]->tileDisplay();

            if(i != 0 && possibleMoves[i] != tmp->position)
                tile[r][c]->display();
        }


        int r = tmp->position.first;
        int c = tmp->position.second;

        tile[r][c]->piece = tile[possibleMoves[0].first][possibleMoves[0].second]->piece;
        tile[possibleMoves[0].first][possibleMoves[0].second]->piece = "";

        tile[r][c]->display();
        tile[possibleMoves[0].first][possibleMoves[0].second]->display();

        countClicks = 0;
        possibleMoves.clear();
    }

}

#endif // MOUSEEVENT_H
