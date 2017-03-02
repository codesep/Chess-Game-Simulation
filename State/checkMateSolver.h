/*
	Class: State

	Member Function: checkMateSolver
	
	Checks if the king of current player is in check mate or not.

	Return true or false.
*/

bool State::checkMateSolver(State st, pair<int, char> pos){

	// Final position to which the king is to moved
	string finalPosition = to_string(pos.first) + pos.second;

	string tmp = currentPlayer;

	// Make the king move to finalPosition
	st.makeMove("K", finalPosition);

	currentPlayer = tmp;

	// Checks if the modified state is in check condition or not
	return st.testCheck();
}