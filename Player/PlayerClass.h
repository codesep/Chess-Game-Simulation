/*
	Defining class Player
*/

using namespace std;

class Player{
	// Stores the position of pieces
	map<string, pair<int, char> > pieces;

	// Stores the piece stored at a given position
	map<pair<int, char>, string> reversePieces;

public:
	// Initial Configuration of the players
	Player(bool type); 

	// Checks if a given block is occupied by a piece or not
	bool checkFreeBlock(pair<int, char> pos);

	// Making a move, i.e., moving 'piece' from it's current position to 'finalPosition'
	void makeMove(string piece, string finalPostion);

	//Removing a piece from the configuration
	void removePiece(string piece);
};	