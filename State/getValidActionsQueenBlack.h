/*
	Class: State

	Member Function: getValidActionsQueenBlack
	
	Returns a vector containing valid actions, i.e. a piece and it's final position for a Black Queen.
*/

vector< pair<string, string> > State::getValidActionsQueenBlack(pair<int, char> pos){

	// vector of valid actions for a Black Queen
	vector< pair<string, string> > ret;

	// Coordinates of the given Queen
	int r = pos.first;
	char c = pos.second;

	int i = r + 1;
	char ch = c;

	// Find valid actions for the given Queen
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

	i = r + 1, ch = c + 1;

	while(i <= 8 && ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 0){

		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );
		i += 1;
		ch += 1;
	}

	if(i <= 8 && ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 1)
		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );

	i = r - 1, ch = c + 1;

	while(i >= 1 && ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 0){

		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );
		i -= 1;
		ch += 1;
	}

	if(i >= 1 && ch <= 'h' && colorOfPiece[ make_pair(i, ch) ] == 1)
		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );	

	i = r + 1, ch = c - 1;

	while(i <= 8 && ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 0){

		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );
		ch -= 1;
		i += 1;
	}

	if(i <= 8 && ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 1)
		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );
		
	i = r - 1, ch = c - 1;

	while(i >= 1 && ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 0){

		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );
		ch -= 1;
		i -= 1;
	}

	if(i >= 1 && ch >= 'a' && colorOfPiece[ make_pair(i, ch) ] == 1)
		ret.push_back( make_pair(chessBoard[pos], to_string(i) + ch) );	


	return ret;
}
