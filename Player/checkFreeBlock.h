/*
	Class: Player

	Member Function: checkFreeBlock

	Takes input the position ('pos') and checks if the position is occupied by a piece of the Player or not.
	
	Returns true or false.
*/

bool Player::checkFreeBlock(pair<int, char> pos){
	//Checks if the given position is free or not
	if(this->reversePieces[pos] == "")
		return 1;

	return 0;
}
