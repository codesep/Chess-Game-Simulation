/*
	Defining class State
*/

using namespace std;

class State{
	// white and black players
	Player white, black;

	// current configuration of the chess board
	map<int, map<char, string> > chessBoard;

	//Current Player
	string currentPlayer;

public:
	//Get current player type
	string getCurrentPlayerType();

	//White players makes a move. Can also remove one of the piece of player black.
	void makeMoveWhite(string piece, string finalPosition);

	//Black players makes a move. Can also remove one of the piece of player white.
	void makeMoveBlack(string piece, string finalPosition);

	//Tests check mate condition for the current player
	bool testCheckMate();

	// Tests if the move of player white is legal or not
	bool checkLegalMoveWhite(string piece, string finalPosition);

	// Tests if the move of player black is legal or not
	bool checkLegalMoveBlack(string piece, string finalPosition);
};	