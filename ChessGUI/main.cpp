#include "mainwindow.h"
#include <QApplication>
#include <QMouseEvent>
#include <vector>
#include <QLabel>
#include <cstring>
#include <utility>
#include <map>

using namespace std;

#include "Tile/tileclass.h"
#include "Tile/mouseevent.h"
#include "Validation/validationclass.h"
#include "Validation/validatememberfunction.h"

int countClicks = 0;

Tile *tile[9][9];

void setBorder(QWidget *gameWidget){
    vector<QLabel*> border(4);

    for(int i = 0; i < 4; i++)
        border[i] = new QLabel(gameWidget);

    border[0]->setGeometry(0, 0, 840, 20);

    border[0]->setStyleSheet("QLabel { background-color: rgb(170, 170, 127); color: black;}");

    border[1]->setGeometry(0, 820, 840, 20);

    border[1]->setStyleSheet("QLabel { background-color: rgb(170, 170, 127); color: black;}");

    border[2]->setGeometry(0, 20, 20, 800);

    border[2]->setStyleSheet("QLabel { background-color: rgb(170, 170, 127); color: black;}");

    border[3]->setGeometry(820, 20, 20, 800);

    border[3]->setStyleSheet("QLabel { background-color: rgb(170, 170, 127); color: black;}");
}

void chessBoard(QWidget *gameWidget){
    //Set Border's
    setBorder(gameWidget);
    int ver = 20;

    for(int i = 8; i >=1; i--){
        int hor = 20;
        for(int j = 1; j <= 8; j++){
            tile[i][j] = new Tile(gameWidget);
            tile[i][j]->tileColor = (i + j) % 2;
            tile[i][j]->piece = "";
            tile[i][j]->position = make_pair(i, j);
            tile[i][j]->tileDisplay();
            tile[i][j]->setGeometry(hor, ver, 100, 100);
            hor += 100;
        }
        ver += 100;
    }

    int ix = 1;
    //White Pawns
    for(int j = 1; j <= 8; j++)
        tile[2][j]->piece = "WP" + to_string(ix++);

    ix = 1;
    //Black Pawns
    for(int j = 1; j <= 8; j++)
        tile[7][j]->piece = "BP" + to_string(ix++);

    //White Rook
    tile[1][1]->piece = "WR1";
    tile[1][8]->piece = "WR2";

    //Black Rook
    tile[8][1]->piece = "BR1";
    tile[8][8]->piece = "BR2";

    //White Knight
    tile[1][2]->piece = "WN1";
    tile[1][7]->piece = "WN2";

    //Black Knight
    tile[8][2]->piece = "BN1";
    tile[8][7]->piece = "BN2";

    //White Bishop
    tile[1][3]->piece = "WB1";
    tile[1][6]->piece = "WB2";

    //Black Bishop
    tile[8][3]->piece = "BB1";
    tile[8][6]->piece = "BB2";

    //White Queen
    tile[1][4]->piece = "WQ";

    //Black Queen
    tile[8][4]->piece = "BQ";

    //White King
    tile[1][5]->piece = "WK";

    //Black King
    tile[8][5]->piece = "BK";

    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            tile[i][j]->display();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *gameWidget = new QWidget();
    gameWidget->setGeometry(0, 0, 840, 840);

    chessBoard(gameWidget);

    gameWidget->show();

    return a.exec();
}
