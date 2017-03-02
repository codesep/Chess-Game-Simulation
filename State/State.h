/*
	Class: State

	Member Function: State Constructor
	
	Set up the initial configuration of the game, i.e. the initial state.
*/

State::State(): white(1), black(0){
	// Setting up the initial state of the chess board

	currentPlayer = "White";

	// Setting up the colorOfPiece
	for(int i = 1; i <= 2; i++){
		for(char ch = 'a'; ch <= 'h'; ch++){
			if(i == 1 || i == 2)
				colorOfPiece[make_pair(i, ch)] = 1;
			else if(i == 7 || i == 8)
				colorOfPiece[make_pair(i, ch)] = -1;
			else
				colorOfPiece[make_pair(i, ch)] = 0;
		}
	}

	// Black Pawns
	for(char ch = 'a'; ch <= 'h'; ch++)
		this->chessBoard[7][ch] = "P" + to_string(ch - 'a' + 1);

	// White Pawns
	for(char ch = 'a'; ch <= 'h'; ch++)
		this->chessBoard[2][ch] = "P" + to_string(ch - 'a' + 1);

	// Black Rooks
	this->chessBoard[8]['a'] = "R1";
	this->chessBoard[8]['h'] = "R2";

	// White Rooks
	this->chessBoard[1]['a'] = "R1";
	this->chessBoard[1]['h'] = "R2";

	// Black Knight
	this->chessBoard[8]['b'] = "N1";
	this->chessBoard[8]['g'] = "N2";

	// White Knight
	this->chessBoard[1]['b'] = "N1";
	this->chessBoard[1]['g'] = "N2";

	// Black Bishop
	this->chessBoard[8]['c'] = "B1";
	this->chessBoard[8]['f'] = "B2";

	// White Bishop
	this->chessBoard[1]['c'] = "B1";
	this->chessBoard[1]['f'] = "B2";

	// Black Queen
	this->chessBoard[8]['d'] = "Q";

	// White Queen
	this->chessBoard[1]['d'] = "Q";

	// Black King
	this->chessBoard[8]['e'] = "K";

	// White King
	this->chessBoard[1]['e'] = "K";
}
