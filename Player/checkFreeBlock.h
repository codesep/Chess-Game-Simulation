/*
	Player Class checkFreeBlock definition. Takes input the position ('pos') and checks if the position is occupied by a piece of the Player or not.
	Returns true or false.
*/

bool Player::checkFreeBlock(pair<int, char> pos){
	if(this->reversePieces[pos] == "")
		return 1;
	return 0;
}

