/*
	Class: State

	Member Function: testCheck
	
	Checks if the king of current player is in check or not.

	Return true or false.
*/

bool State::testCheck(){

	// Checks if the current player is white
	if(currentPlayer == "White"){

		// Checks if the king of white player is in check or not.
		return testCheckWhite();
	}
	else{	// Checks if the current player is black

		// Checks if the king of black player is in check or not.
		return testCheckBlack();	
	}
}