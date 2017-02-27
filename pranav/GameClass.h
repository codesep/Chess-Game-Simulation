class Game {
	State state;
	int maxDepth;
public:
	Game(int d): state() {
		maxDepth = d; 
	}
	void simulateGame();							// __________________________
	pair<string, string> decideBlackMove(State&);	/*							*/
	ll maxValue(State&, ll, ll, int);				/*	      Alpha-Beta		*/
	ll minValue(State&, ll, ll, int);				/*		    Search			*/
	ll terminalTest(State&, bool);					/*__________________________*/
};

ll Game::terminalTest(State& state, bool colour) {

}

void Game::simulateGame() {
	int i, j;
	bool colour = true;
	state.printState();
	while(1) {
		if(colour) {	//White's turn
			string piece, position;
			
			if(state.checkmate(colour)) {
				cout << "You Lose!!\n";
				break;
			}
			
			cin >> piece >> position;
			
			if(!state.validateMove(piece, position, colour)) {
				cout << "Invalid Move!! Retry!!\n";
				continue;
			}
			
			state.makeMove(piece, position, colour);
		}
		else {	//Black's turn

			if(state.checkmate(colour)) {
				cout << "You Win!!\n";
				break;
			}

			auto move = decideBlackMove(state);
			state.makeMove(move.first, move.second, colour);
		}
		colour = !colour;
	}
	return;
}

pair<string, string> Game::decideBlackMove(State &state) {
	ll value = LLONG_MIN;
	ll temp;

	set<pair<string, string> > actions = state.getValidActions(false);
	pair<string, string> optimal;

	for(auto it = actions.begin(); it != actions.end(); ++it) {
		State aux = state;
		auto curAction = *it;
		aux.makeMove(curAction.first, curAction.second, false);

		temp = minValue(aux, LLONG_MIN, LLONG_MAX, 1);
		if(value <= temp) {
			value = temp;
			optimal = curAction;
		}
	}

	return optimal;
}

ll Game::maxValue(State& state, ll alpha, ll beta, int depth) {
	if(terminalTest(state, false)) 
		return LLONG_MIN;

	if(depth == maxDepth)
		return state.evaluate();

	ll value = LLONG_MIN;
	set<pair<string, string> > actions = state.getValidActions(false);

	for(auto it = actions.begin(); it != actions.end(); ++it) {
		State aux = state;
		auto curAction = *it;
		aux.makeMove(curAction.first, curAction.second, false);

		value = max(value, minValue(aux, alpha, beta, depth+1));

		if(value >= beta)
			return value;

		alpha = max(alpha, value);
	}

	return value;
}

ll Game::minValue(State& state, ll alpha, ll beta, int depth) {
	if(terminalTest(state, true)) 
		return LLONG_MAX;

	if(depth == maxDepth)
		return state.evaluate();

	ll value = LLONG_MAX;
	set<pair<string, string> > actions = state.getValidActions(true);

	for(auto it = actions.begin(); it != actions.end(); ++it) {
		State aux = state;
		auto curAction = *it;
		aux.makeMove(curAction.first, curAction.second, true);

		value = max(value, maxValue(aux, alpha, beta, depth+1));

		if(value <= alpha)
			return value;

		beta = min(beta, value);
	}

	return value;
}