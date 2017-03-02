/*
	Class: State

	Member Function: getValidActions
	
	Returns a set containing valid actions, i.e. a piece and it's final position.
*/

set< pair<string, string> > State::getValidActions(){

	// Checks if the current player is white
	if(currentPlayer == "White"){

		// Get valid actions for player white
		return getValidActionsWhite();
	}
	else{	// Checks if the current player is black

		// Get valid actions for player black
		return getValidActionsBlack();
	}
}