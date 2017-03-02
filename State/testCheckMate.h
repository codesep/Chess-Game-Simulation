/*
	Class: State

	Member Function: testCheckMate
	
	Checks if the king of current player is in check mate or not.

	Return true or false.
*/

bool State::testCheckMate(){

	int color = 1;

	pair<int, char> pos;

	// Get the current position of the King
	if(currentPlayer == "White")
		pos = White.getPosFromPiece("K");
	else
		pos = Black.getPosFromPiece("K"), color = -1;

	// Coordinates of the King 
	int r = pos.first;
	char c = pos.second;

	if(testCheck() == 0)
		return 0;

	if(r + 1 <= 8 && colorOfPiece[ make_pair(r + 1, c) ] != color){

		if(checkMateSolver(*this, make_pair(r + 1, c) ) == 0)
			return 0;
	}

	if(r - 1 >= 1 && colorOfPiece[ make_pair(r - 1, c) ] != color){

		if(checkMateSolver(*this, make_pair(r - 1, c) ) == 0)
			return 0;
	}	

	if(c + 1 <= 'h' && colorOfPiece[ make_pair(r, c + 1) ] != color){

		if(checkMateSolver(*this, make_pair(r, c + 1) ) == 0)
			return 0;
	}

	if(c - 1 >= 'a' && colorOfPiece[ make_pair(r, c - 1) ] != color){

		if(checkMateSolver(*this, make_pair(r, c - 1) ) == 0)
			return 0;
	}

	if(r + 1 <= 8 && c + 1 <= 'h' && colorOfPiece[ make_pair(r + 1, c + 1) ] != color){

		if(checkMateSolver(*this, make_pair(r + 1, c + 1) ) == 0)
			return 0;
	}

	if(r + 1 <= 8 && c - 1 >= 'a' && colorOfPiece[ make_pair(r + 1, c - 1) ] != color){

		if(checkMateSolver(*this, make_pair(r + 1, c - 1) ) == 0)
			return 0;
	}

	if(r - 1 >= 1 && c + 1 <= 'h' && colorOfPiece[ make_pair(r - 1, c + 1) ] != color){

		if(checkMateSolver(*this, make_pair(r - 1, c + 1) ) == 0)
			return 0;
	}

	if(r - 1 >= 1 && c - 1 >= 'a' && colorOfPiece[ make_pair(r - 1, c - 1) ] != color){

		if(checkMateSolver(*this, make_pair(r - 1, c - 1) ) == 0)
			return 0;
	}	

	return 1;
}