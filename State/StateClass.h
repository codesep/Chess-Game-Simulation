/*
	Defining class State
*/

// using namespace std;

class State{
	// white and black players
	Player white, black;

	// Current configuration of the chess board
	map< pair<int, char>, string > chessBoard;

	// Stores the color of a piece occupying the given position.
	// 1 implies white
	// -1 implies black
	map< pair<int, char>, int > colorOfPiece;

public:
	// Initial State
	State();

	// Current Player
	string currentPlayer;

	//Get current player type
	string getCurrentPlayerType();

	//White players makes a move. Can also remove one of the piece of player black.
	void makeMoveWhite(string piece, string finalPosition);

	//Black players makes a move. Can also remove one of the piece of player white.
	void makeMoveBlack(string piece, string finalPosition);

	//Tests check mate condition for the current player
	bool testCheckMate();

	// Check mate solver
	bool checkMateSolver(State, pair<int, char> pos);

	//Tests check condition for the current player
	bool testCheck();

	//Tests check condition for the white player
	bool testCheckWhite();

	//Tests check condition for the black player
	bool testCheckBlack();	

	// Current Player makes a move. Can also remove one of the piece of opponent player.
	void makeMove(string piece, string finalPosition);

	// Get valid actions from the current state
	vector< pair<string, string> > getValidActions();

	// Get valid actions from the current state for white player
	vector< pair<string, string> > getValidActionsWhite();

	// Get valid actions from the current state for black player
	vector< pair<string, string> > getValidActionsBlack();

	// Get valid actions for a white pawn
	vector< pair<string, string> > getValidActionsPawnWhite(pair<int, char> position);

	// Get valid actions for a black pawn
	vector< pair<string, string> > getValidActionsPawnBlack(pair<int, char> position);

	// Get valid actions for a white rook
	vector< pair<string, string> > getValidActionsRookWhite(pair<int, char> position);

	// Get valid actions for a black rook
	vector< pair<string, string> > getValidActionsRookBlack(pair<int, char> position);

	// Get valid actions for a white Bishop
	vector< pair<string, string> > getValidActionsBishopWhite(pair<int, char> position);

	// Get valid actions for a black Bishop
	vector< pair<string, string> > getValidActionsBishopBlack(pair<int, char> position);

	// Get valid actions for a white Knight
	vector< pair<string, string> > getValidActionsKnightWhite(pair<int, char> position);

	// Get valid actions for a black Knight
	vector< pair<string, string> > getValidActionsKnightBlack(pair<int, char> position);

	// Get valid actions for a white Queen
	vector< pair<string, string> > getValidActionsQueenWhite(pair<int, char> position);

	// Get valid actions for a black Queen
	vector< pair<string, string> > getValidActionsQueenBlack(pair<int, char> position);

	// Get valid actions for a white King
	vector< pair<string, string> > getValidActionsKingWhite(pair<int, char> position);

	// Get valid actions for a black King
	vector< pair<string, string> > getValidActionsKingBlack(pair<int, char> position);
};	















