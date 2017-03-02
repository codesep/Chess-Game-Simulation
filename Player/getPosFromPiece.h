/*
	Class: Player

	Member Function: getPosFromPiece

	Takes input the piece ('piece') and return the position of the given piece.
	
	Returns the position.
*/

pair<int, char> Player::getPosFromPiece(string piece){

	// Returns the position of the given piece
	// If the piece is already removed that returns the NULL value, i.e. (-1, 'z').
	return pieces[piece];
}