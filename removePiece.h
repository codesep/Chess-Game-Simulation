/*
	Player Class removePiece definition. Takes input the piece which is to be removed from the configuration. 
	Puts NULL value in pieces data structure and empty string in reversePieces data structure.
*/

void Player::removePiece(string piece){
	// Getting the current position of piece
	pos<int, char> pos = this->pieces[piece];

	// Setting the position of piece to be NULL value, i.e. (-1, z)
	this->pieces[piece] = mp(-1, 'z');

	// Emptying the position in reversePieces
	this->reversePieces[pos] = "";
}

