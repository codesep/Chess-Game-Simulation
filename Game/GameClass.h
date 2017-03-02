/*
	Defining class Game
*/

class Game{

	//	State object representing current state of the game 
	State currentState;

	// Max depth until which the search tree will be built
	int maxDepth;

public:

	// Simulate game function
	void simulateGame();

	// Gives the moves best for the AI
	pair<string, string> decideBlackMove(State&);

	// Returns max utility value
	ll maxValue(State&, ll alpha , ll beta, int depth);

	// Returns min utility value
	ll minValue(State&, ll alpha , ll beta, int depth);

	// Tests if the given state is the terminal state or not
	ll terminalTest(State&, bool);
};