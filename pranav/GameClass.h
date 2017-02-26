class Game {
	State state;
	int maxDepth;
public:
	Game(int d): state() {
		maxDepth = d; 
	}
	void simulateGame();							  __________________________
	pair<string, string> decideBlackMove(State&);	/*							*/
	ll maxValue(State&, ll, ll, int);				/*	      Alpha-Beta		*/
	ll minValue(State&, ll, ll, int);				/*		    Search			*/
	ll terminalTest(State&, bool);					/*__________________________*/
};

void Game::simulateGame() {
	int i, j;
	bool colour = true;
	while(1) {
		if(colour) {	//White's turn
			string piece, position;
			
			if(state.checkmate(colour)) {
				cout << "You Lose!!\n";
				break;
			}
			
			cin >> piece >> position;
			
			if(!state.validateWhiteMove(piece, position)) {
				cout << "Invalid Move!! Retry!!\n";
				continue;
			}
			
			state.makeMove(piece, position, colour);
		}
		else {	//Black's turn
			auto move = decideBlackMove(state);
		}
	}
	return;
}

pair<string, string> Game::decideBlackMove(State &state) {
	ll value = LLONG_MIN;
	ll temp;

	pair<string, string> actions = state.getValidActions(false), optimal;

	for(int i = 0; i < actions.size(); ++i) {
		State aux = state;
		aux.makeMove(actions[i].first, actions[i].second, false);

		temp = minValue(aux, LLONG_MIN, LLONG_MAX, 1);
		if(value <= temp) {
			value = temp;
			optimal = i;
		}
	}

	return optimal[i];
}

ll Game::maxValue(State& state, ll alpha, ll beta, int depth) {

}

ll Game::minValue(State& state, ll alpha, ll beta, int depth) {

}