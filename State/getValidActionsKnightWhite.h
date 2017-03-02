/*
	Class: State

	Member Function: getValidActionsKnightWhite
	
	Returns a vector containing valid actions, i.e. a piece and it's final position for a white Knight.
*/

vector< pair<string, string> > State::getValidActionsKnightWhite(pair<int, char> pos){

	// vector of valid actions for a white Knight
	vector< pair<string, string> > ret;

	// Coordinates of the given Knight
	int r = pos.first;
	char c = pos.second;

	int x[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int y[] = {1, -1, -2, 2, -2, 2, 1, -1};


	// Find valid actions for the given Knight
    for(int i = 0; i < 8; i++){

    	if(x[i] + r >= 1 && x[i] + r <= 8 && y[i] + c >= 'a' && y[i] + c <= 'h'){

    		if(colorOfPiece[ make_pair(x[i] + r, y[i] + c) ] == 1)
    			continue;

    		ret.push_back( make_pair(chessBoard[pos], to_string(x[i] + r) + char(ch + c) ) );
    	}
    }

	return ret;
}
