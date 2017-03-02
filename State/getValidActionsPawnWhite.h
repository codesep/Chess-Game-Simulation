/*
	Class: State

	Member Function: getValidActionsPawnWhite
	
	Returns a vector containing valid actions, i.e. a piece and it's final position for a white pawn.
*/

vector< pair<string, string> > State::getValidActionsPawnWhite(pair<int, char> pos){

	// vector of valid actions for a white pawn
	vector< pair<string, string> > ret;

	// Coordinates of the given pawn
	int i = pos.first;
	char ch = pos.second;

	// Find valid actions for the given pawn
	if(i + 1 <= 8 && colorOfPiece[make_pair(i + 1, ch)] == 0){

		ret.push_back( make_pair( chessBoard[pos], to_string(i + 1) + ch ) );

		if(i == 2 && colorOfPiece[make_pair(i + 2, ch)] == 0){

			// First move of the pawn can take two steps
			ret.push_back( make_pair( chessBoard[pos], to_string(i + 2) + ch ) );			
		}
	}

	//Pawn Diagonal moves
	if(i + 1 <= 8 && ch + 1 <= 'h' && colorOfPiece[make_pair(i + 1, ch + 1)] == -1)
		ret.push_back( make_pair( chessBoard[pos], to_string(i + 1) + char(ch + 1) ) );

	if(i + 1 <= 8 && ch - 1 => 'a' && colorOfPiece[make_pair(i + 1, ch - 1)] == -1)
		ret.push_back( make_pair( chessBoard[pos], to_string(i + 1) + char(ch - 1) ) );			

	return ret;
}
