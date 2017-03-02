/*
	Class: Player

	Member Function: getPieceFromPos

	Takes input the position ('pos') and return the piece occupying the given position.
	
	Returns the piece.
*/

string Player::getPieceFromPos(pair<int, char> pos){

	// Returns the piece occupying the given position.
	// If the position is empty than returns an empty string.
	return reversePieces[pos];
}