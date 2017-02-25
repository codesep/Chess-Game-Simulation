/*
	Class: State

	Member Function: State Constructor
	
	Set up the initial configuration of the game, i.e. the initial state.
*/

State::State(): white(1), black(0){
	//Setting up the initial state of the chess board

	//Black Pawns
	for(char ch = 'a'; ch <= 'h'; ch++)
		this->chessBoard[7][ch] = "BP" + to_string(ch - 'a' + 1);

	//White Pawns
	for(char ch = 'a'; ch <= 'h'; ch++)
		this->chessBoard[2][ch] = "WP" + to_string(ch - 'a' + 1);

	//Black Rooks
	this->chessBoard[8]['a'] = "BR1";
	this->chessBoard[8]['h'] = "BR2";

	//White Rooks
	this->chessBoard[1]['a'] = "WR1";
	this->chessBoard[1]['h'] = "WR2";

	//Black Knight
	this->chessBoard[8]['b'] = "BN1";
	this->chessBoard[8]['g'] = "BN2";

	//White Knight
	this->chessBoard[1]['b'] = "WN1";
	this->chessBoard[1]['g'] = "WN2";

	//Black Bishop
	this->chessBoard[8]['c'] = "BB1";
	this->chessBoard[8]['f'] = "BB2";

	//White Bishop
	this->chessBoard[1]['c'] = "WB1";
	this->chessBoard[1]['f'] = "WB2";

	//Black Queen
	this->chessBoard[8]['d'] = "BQ";

	//White Queen
	this->chessBoard[1]['d'] = "WQ";

	//Black King
	this->chessBoard[8]['e'] = "BK";

	//White King
	this->chessBoard[1]['e'] = "WK";
}

