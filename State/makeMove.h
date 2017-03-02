/*
	Class: State

	Member Function: makeMove

	Takes input the piece name and the position ('finalPosition') to which the piece is to be moved.
	
	Function moves the piece to the 'finalPosition' and freeing the block occupied earlier.

	Can also remove one of the piece of the opponent Player.
*/

void State::makeMove(string piece, string finalPosition){
	// Checks if the current player is white
	if(this->currentPlayer == "White"){
		// Player white makes a move
		this->makeMoveWhite(piece, finalPosition);

		// Change the current player to black
		this->currentPlayer = "Black";
	}
	else{ 	// Checks if the current player is black
		// Player black makes a move
		this->makeMoveBlack(piece, finalPosition);

		// Change the current player to white
		this->currentPlayer = "White";
	}
}