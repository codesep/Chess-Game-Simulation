/*
	Defining class Player
*/

// using namespace std;

class Player{
	// Stores the position of pieces
	map<string, pair<int, char> > pieces;

	// Stores the piece stored at a given position
	map<pair<int, char>, string> reversePieces;

	// Stores the pieces that have been removed
	set<string> removedPieces;

	// Colour of the piece
	// 1 implies white
	// -1 implies black
	int color;

public:
	// Player();

	// Initial Configuration of the players
	Player(bool type); 

	// Checks if a given block is occupied by a piece or not
	bool checkFreeBlock(pair<int, char> pos);

	// Making a move, i.e., moving 'piece' from it's current position to 'finalPosition'
	void makeMove(string piece, string finalPosition);

	//Removing a piece from the configuration
	void removePiece(string piece);

	// Gets the position from the given piece
	pair<int, char> getPosFromPiece(string piece);

	// Gets the piece from the given position
	string getPieceFromPos(pair<int, char> pos);

	// Gets the color of the player
	int getColor();
};	