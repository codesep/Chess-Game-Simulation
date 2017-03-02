#ifndef VALIDATEMEMBERFUNCTION_H
#define VALIDATEMEMBERFUNCTION_H

extern Tile *tile[9][9];
vector<pair<int, int> > possibleMoves;

void displayGreen(Tile *tmp){
    tmp->setStyleSheet("QLabel {background-color: green;}");
}

void displayOrange(Tile *tmp){
    tmp->setStyleSheet("QLabel {background-color: orange; border: 0.5px solid;}");
}

void displayRed(Tile *tmp){
    tmp->setStyleSheet("QLabel {background-color: red; border: 0.5px solid;}");
}

void Validation::choosePiece(Tile *tmp){
    switch(tmp->piece[1]){
        case 'P':   validatePawn(tmp);
                    break;
        case 'R':   validateRook(tmp);
                    break;
        case 'B':   validateBishop(tmp);
                    break;
        case 'N':   validateKnight(tmp);
                    break;
        case 'Q':   validateQueen(tmp);
                    break;
        case 'K':   validateKing(tmp);
                    break;
    }
}

void Validation::validatePawn(Tile *tmp){
    int i = tmp->position.first;
    int j = tmp->position.second;

    displayGreen(tile[i][j]);
    possibleMoves.push_back(make_pair(i, j));

    if(i + 1<=8 && tile[i + 1][j]->piece == ""){
        displayOrange(tile[i + 1][j]);
        possibleMoves.push_back(make_pair(i + 1, j));
        if(i == 2 && tile[i + 2][j]->piece == ""){
            displayOrange(tile[i + 2][j]);
            possibleMoves.push_back(make_pair(i + 2, j));
        }
    }


    if(i + 1<=8 && j + 1<=8 && tile[i + 1][j + 1]->piece[0] == 'B'){
        displayRed(tile[i + 1][j + 1]);
        possibleMoves.push_back(make_pair(i + 1, j + 1));
    }

    if(i + 1 <= 8 && j - 1 >= 1 && tile[i + 1][j - 1]->piece[0] == 'B'){
        displayRed(tile[i + 1][j - 1]);
        possibleMoves.push_back(make_pair(i + 1, j - 1));
    }
}

void Validation::validateRook(Tile *tmp){
    int r = tmp->position.first;
    int c = tmp->position.second;

    displayGreen(tile[r][c]);
    possibleMoves.push_back(make_pair(r, c));

    int i = r + 1, j = c;

    while(i <= 8 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        i += 1;
    }

    if(i <= 8 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r - 1;

    while(i >= 1 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        i -= 1;
    }

    if(i >= 1 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r, j = c + 1;

    while(j <= 8 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        j += 1;
    }

    if(j <= 8 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    j = c - 1;

    while(j >= 1 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        j -= 1;
    }

    if(j >= 1 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }
}

void Validation::validateBishop(Tile *tmp){
    int r = tmp->position.first;
    int c = tmp->position.second;

    displayGreen(tile[r][c]);
    possibleMoves.push_back(make_pair(r, c));

    int i = r + 1, j = c + 1;

    while(i <= 8 && j <= 8 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        i += 1;
        j += 1;
    }

    if(i <= 8 && j <= 8 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r - 1, j = c + 1;

    while(i >= 1 && j <= 8 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        i -= 1;
        j += 1;
    }

    if(i >= 1 && j <= 8 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r + 1, j = c - 1;

    while(i <= 8  && j >= 1 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        i += 1;
        j -= 1;
    }

    if(i <= 8 && j >= 1 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r - 1, j = c - 1;

    while(j >= 1 && i >= 1 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        j -= 1;
        i -= 1;
    }

    if(j >= 1 && i >= 1 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

}

void Validation::validateKnight(Tile *tmp){
    int r = tmp->position.first;
    int c = tmp->position.second;

    displayGreen(tile[r][c]);
    possibleMoves.push_back(make_pair(r, c));

    int x[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int y[] = {1, -1, -2, 2, -2, 2, 1, -1};

    for(int i = 0; i < 8; i++){
        if(x[i] + r >= 1 && x[i] + r <= 8 && y[i] + c >= 1 && y[i] + c <= 8){
            if(tile[x[i] + r][y[i] + c]->piece[0] == 'W')
                continue;
            if(tile[x[i] + r][y[i] + c]->piece == "")
                displayOrange(tile[x[i] + r][y[i] + c]);
            else
                displayRed(tile[x[i] + r][y[i] + c]);
            possibleMoves.push_back(make_pair(x[i] + r, y[i] + c));
        }
    }
}

void Validation::validateQueen(Tile *tmp){
    int r = tmp->position.first;
    int c = tmp->position.second;

    displayGreen(tile[r][c]);
    possibleMoves.push_back(make_pair(r, c));

    int i = r + 1, j = c;

    while(i <= 8 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        i += 1;
    }

    if(i <= 8 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r - 1;

    while(i >= 1 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        i -= 1;
    }

    if(i >= 1 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r, j = c + 1;

    while(j <= 8 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        j += 1;
    }

    if(j <= 8 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    j = c - 1;

    while(j >= 1 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        j -= 1;
    }

    if(j >= 1 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r + 1, j = c + 1;

    while(i <= 8 && j <= 8 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        i += 1;
        j += 1;
    }

    if(i <= 8 && j <= 8 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r - 1, j = c + 1;

    while(i >= 1 && j <= 8 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        i -= 1;
        j += 1;
    }

    if(i >= 1 && j <= 8 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r + 1, j = c - 1;

    while(i <= 8  && j >= 1 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        i += 1;
        j -= 1;
    }

    if(i <= 8 && j >= 1 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }

    i = r - 1, j = c - 1;

    while(j >= 1 && i >= 1 && tile[i][j]->piece == ""){
        displayOrange(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
        j -= 1;
        i -= 1;
    }

    if(j >= 1 && i >= 1 && tile[i][j]->piece[0] == 'B'){
        displayRed(tile[i][j]);
        possibleMoves.push_back(make_pair(i, j));
    }
}

void Validation::validateKing(Tile *tmp){
    int r = tmp->position.first;
    int c = tmp->position.second;

    displayGreen(tile[r][c]);
    possibleMoves.push_back(make_pair(r, c));

    int x[] = {0, 0, 1, -1, 1, 1, -1, 1};
    int y[] = {1, -1, 0, 0, 1, -1, 1, -1};

    for(int i = 0; i < 8; i++){
        if(x[i] + r >= 1 && x[i] + r <= 8 && y[i] + c >= 1 && y[i] + c <= 8){
            if(tile[x[i] + r][y[i] + c]->piece[0] == 'W')
                continue;
            if(tile[x[i] + r][y[i] + c]->piece == "")
                displayOrange(tile[x[i] + r][y[i] + c]);
            else
                displayRed(tile[x[i] + r][y[i] + c]);
            possibleMoves.push_back(make_pair(x[i] + r, y[i] + c));
        }
    }
}


#endif // VALIDATEMEMBERFUNCTION_H
