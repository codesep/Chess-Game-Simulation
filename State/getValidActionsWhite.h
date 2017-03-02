/*
	Class: State

	Member Function: getValidActionsWhite
	
	Returns a vector containing valid actions, i.e. a piece and it's final position.
*/

vector< pair<string, string> > State::getValidActionsWhite(){

	// vector of valid actions
	vector< pair<string, string> > ret;

	// Traverses the chess board to find white pieces and than find actions corresponding to those white pieces.
	for(int i = 1; i <= 8; i++){

		for(char ch = 'a'; ch <= 'h'; ch++){	

			if(colorOfPiece[ make_pair(i, ch) ] == 1){

				vector< pair<string, string> > tmp;

				switch(chessBoard[ make_pair(i, ch) ]){
					case 'P':	tmp = getValidActionsPawnWhite( make_pair(i, ch) );
								break;
					case 'R':	tmp = getValidActionsRookWhite( make_pair(i, ch) );
								break;
					case 'B':	tmp = getValidActionsBishopWhite( make_pair(i, ch) );
								break;
					case 'N':	tmp = getValidActionsKnightWhite( make_pair(i, ch) );
								break;
					case 'Q':	tmp = getValidActionsQueenWhite( make_pair(i, ch) );
								break;
					case 'K':	tmp = getValidActionsKingWhite( make_pair(i, ch) );
								break;						
				}

				for(int j = 0; j < tmp.size(); j++)
					ret.push_back( tmp[j] );
			}
		}
	}

	// Returns the vector of valid actions
	return ret;
}