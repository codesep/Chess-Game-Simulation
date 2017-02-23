/*
	Player Class makeMove function definition. Takes input the piece name and the position ('finalPosition') to which the piece is to be moved.
	Function moves the piece to the 'finalPosition' and freeing the block occupied earlier.
*/

void Player::makeMove(string piece, string finalPostion){
	//Get final position of the piece to be moved
	pair<int, char> pos = make_pair(finalPostion[0] - '0', finalPostion[1]);

	//Remove the piece from it's current position
	this->reversePieces[this->pieces[piece]] = "";

	//Move the piece to the final position
	this->pieces[piece] = pos;

	//Update reversePieces for the piece
	this->reversePieces[pos] = piece;
}