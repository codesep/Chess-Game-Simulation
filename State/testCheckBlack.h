/*
	Class: State

	Member Function: testCheckBlack
	
	Checks if the king of current player is in check or not.

	Return true or false.
*/

bool State::testCheckBlack(){

	// Get the current position of the King
	pair<int, char> pos = Black.getPosFromPiece("K");

	int r = pos.first;
	char c = pos.second;

	int i = r + 1;
	char ch = c;

	while(i <= 8 && colorOfPiece[ make_pair(i, ch) ] == 0)
		i += 1;

	if(i <= 8 && colorOfPiece[ make_pair(i, ch) ] == 1){

		if(i == r + 1 && chessBoard[ make_pair(i, ch) ] == "K")
			return 1;

		if(chessBoard[ make_pair(i, ch) ][0] == 'Q' || chessBoard[ make_pair(i, ch) ][0] == 'R')
			return 1;
	}

	i = r - 1;

	while(i >= 1 && colorOfPiece[ make_pair(i, ch) ] == 0)
		i -= 1;

	if(i >= 1 && colorOfPiece[ make_pair(i, ch) ] == 1){

		if(i == r - 1 && chessBoard[ make_pair(i, ch) ] == "K")
			return 1;

		if(chessBoard[ make_pair(i, ch) ][0] == 'Q' || chessBoard[ make_pair(i, ch) ][0] == 'R')
			return 1;
	}	 

	i = r, ch = c + 1;

	while(ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 0)
		ch += 1;

	if(ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 1){

		if(ch == c + 1 && chessBoard[ make_pair(i, ch) ] == "K")
			return 1;

		if(chessBoard[ make_pair(i, ch) ][0] == 'Q' || chessBoard[ make_pair(i, ch) ][0] == 'R')
			return 1;
	}

	ch = c - 1;

	while(ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 0)
		ch -= 1;

	if(ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 1){

		if(ch == c - 1 && chessBoard[ make_pair(i, ch) ] == "K")
			return 1;

		if(chessBoard[ make_pair(i, ch) ][0] == 'Q' || chessBoard[ make_pair(i, ch) ][0] == 'R')
			return 1;
	}

	i = r + 1, ch = c + 1;

	while(i <= 8 && ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 0)
		i += 1, ch += 1;

	if(i <= 8 && ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 1){

		if(i == r + 1 && ch == c + 1 && chessBoard[ make_pair(i, ch) ][0] == 'K' )
			return 1;

		if(chessBoard[ make_pair(i, ch) ][0] == 'Q' || chessBoard[ make_pair(i, ch) ][0] == 'B')
			return 1;	
	}

	i = r + 1, ch = c - 1;

	while(i <= 8 && ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 0)
		i += 1, ch -= 1;

	if(i <= 8 && ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 1){

		if(i == r + 1 && ch == c - 1 && chessBoard[ make_pair(i, ch) ][0] == 'K' )
			return 1;

		if(chessBoard[ make_pair(i, ch) ][0] == 'Q' || chessBoard[ make_pair(i, ch) ][0] == 'B')
			return 1;	
	}

	i = r - 1, ch = c + 1;

	while(i >= 1 && ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 0)
		i -= 1, ch += 1;

	if(i >= 1 && ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 1){

		if(i == r - 1 && ch == c + 1 && (chessBoard[ make_pair(i, ch) ][0] == 'K' || chessBoard[ make_pair(i, ch) ][0] == 'P'))
			return 1;

		if(chessBoard[ make_pair(i, ch) ][0] == 'Q' || chessBoard[ make_pair(i, ch) ][0] == 'B')
			return 1;	
	}

	i = r - 1, ch = c - 1;

	while(i >= 1 && ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 0)
		i += 1, ch -= 1;

	if(i >= 1 && ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 1){

		if(i == r - 1 && ch == c - 1 && (chessBoard[ make_pair(i, ch) ][0] == 'K' || chessBoard[ make_pair(i, ch) ][0] == 'P') )
			return 1;

		if(chessBoard[ make_pair(i, ch) ][0] == 'Q' || chessBoard[ make_pair(i, ch) ][0] == 'B')
			return 1;	
	}

	int x[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int y[] = {1, -1, -2, 2, -2, 2, 1, -1};

    for(int i = 0; i < 8; i++){

    	if(x[i] + r >= 1 && x[i] + r <= 8 && y[i] + c >= 'a' && y[i] + c <= 'h'){
    		if(colorOfPiece[ make_pair(x[i] + r, y[i] + c) ] == -1 && chessBoard[ make_pair(x[i] + r, y[i] + ch) ][0] == 'N')
    			return 1;
    	}
    }

    return 0;
}