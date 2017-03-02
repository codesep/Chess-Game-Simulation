/*
	Class: State

	Member Function: getValidActionsRookBlack
	
	Returns a vector containing valid actions, i.e. a piece and it's final position for a black rook.
*/

vector< pair<string, string> > State::getValidActionsRookBlack(pair<int, char> pos){

	// vector of valid actions for a black rook
	vector< pair<string, string> > ret;

	// Coordinates of the given rook
	int r = pos.first;
	char c = pos.second;

	int i = r + 1;
	char ch = c;

	// Find valid actions for the given rook
	while(i <= 8 && colorOfPiece[ make_pair(i, ch) ] == 0){

		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );
		i += 1;
	}

	if(i <= 8 && colorOfPiece[ make_pair(i, ch) ] == 1)
		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );

	i = r - 1;

	while(i >= 1 && colorOfPiece[ make_pair(i, ch) ] == 0){

		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );
		i -= 1;
	}

	if(i >= 1 && colorOfPiece[ make_pair(i, ch) ] == 1)
		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );	

	i = r, ch = c + 1;

	while(ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 0){

		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );
		ch += 1;
	}

	if(ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 1)
		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );
		
	ch = c - 1;

	while(ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 0){

		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );
		ch -= 1;
	}

	if(ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 1)
		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );	

	return ret;
}
