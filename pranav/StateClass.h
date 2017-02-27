class State {
	Player White;
	Player Black;
	map<int, map<char, string> > chessBoard;
	map<int, map<char, int> > colourOfPiece; //1->white, -1->black, 0->empty
public:
	State(): White(true), Black(false) {

		//Setting up the initial state of the chess board

		for(int i = 1; i <= 8; ++i) {
			for(char j = 'a'; j <= 'h'; ++j) {
				colourOfPiece[i][j] = 0;
			}
		}

		//Black Pawns
		for(char ch = 'a'; ch <= 'h'; ch++) {
			chessBoard[7][ch] = "P" + to_string(ch - 'a' + 1);
			colourOfPiece[7][ch] = -1;
		}

		//White Pawns
		for(char ch = 'a'; ch <= 'h'; ch++) {
			chessBoard[2][ch] = "P" + to_string(ch - 'a' + 1);
			colourOfPiece[2][ch] = 1;
		}

		//Black Rooks
		chessBoard[8]['a'] = "R1";
		colourOfPiece[8]['a'] = -1;
		chessBoard[8]['h'] = "R2";
		colourOfPiece[8]['h'] = -1;

		//White Rooks
		chessBoard[1]['a'] = "R1";
		colourOfPiece[1]['a'] = 1;
		chessBoard[1]['h'] = "R2";
		colourOfPiece[1]['h'] = 1;

		//Black Knight
		chessBoard[8]['b'] = "N1";
		colourOfPiece[8]['b'] = -1;
		chessBoard[8]['g'] = "N2";
		colourOfPiece[8]['g'] = -1;

		//White Knight
		chessBoard[1]['b'] = "N1";
		colourOfPiece[1]['b'] = 1;
		chessBoard[1]['g'] = "N2";
		colourOfPiece[1]['g'] = 1;

		//Black Bishop
		chessBoard[8]['c'] = "B1";
		colourOfPiece[8]['c'] = -1;		
		chessBoard[8]['f'] = "B2";
		colourOfPiece[8]['f'] = -1;

		//White Bishop
		chessBoard[1]['c'] = "B1";
		colourOfPiece[1]['c'] = 1;
		chessBoard[1]['f'] = "B2";
		colourOfPiece[1]['f'] = 1;

		//Black Queen
		chessBoard[8]['d'] = "Q";
		colourOfPiece[8]['d'] = -1;

		//White Queen
		chessBoard[1]['d'] = "Q";
		colourOfPiece[1]['d'] = 1;

		//Black King
		chessBoard[8]['e'] = "K";
		colourOfPiece[8]['e'] = -1;

		//White King
		chessBoard[1]['e'] = "K";
		colourOfPiece[1]['e'] = 1;
	}
	bool validateMove(string, string, bool);
	bool isCheck(bool);
	void makeMove(string, string, bool);
	bool checkmate(bool);
	void printState();
	set<pair<string, string> > getValidActions(bool);
	ll evaluate();
};

ll State::evaluate() {

}

bool State::checkmate(bool colour) {
	return false;
}

set<pair<string, string> > State::getValidActions(bool colour) {
	set<pair<string, string> > actions;
	map<string, pair<int, char> > pieces;

	if(colour)
		pieces = White.getAvailablePieces();
	else
		pieces = Black.getAvailablePieces();

	for(auto it = pieces.begin(); it != pieces.end(); ++it) {
		for(int i = 1; i <= 8; ++i) {
			for(char j = 'a'; j <= 'h'; ++j) {
				string finalPosition = j + to_string(i);
				if(validateMove(it->first, finalPosition, colour))
					actions.insert(make_pair(it->first, finalPosition));
			}
		}
	}
	return actions;
}

void State::printState() {
	for(int i = 8; i >= 1; --i) {
		cout<< i << " ";
		for(char j = 'a'; j <= 'h'; ++j) {
			if(colourOfPiece[i][j] == 1)
				cout << setw(4) << chessBoard[i][j];
			else if(colourOfPiece[i][j] == -1) 
				cout << "\033[38;2;0;0;0m" << setw(4) << chessBoard[i][j] << "\033[0m";
			else
				cout << setw(4) << ".";
		}
		cout << endl;
	}
	cout << "  "; 
	for(char j = 'a'; j <= 'h'; ++j) {
		cout << setw(4) << j; 
	}
	cout << endl;
	return;
}

void State::makeMove(string piece, string finalPosition, bool colour) {

	pair<int, char> pos = make_pair(finalPosition[1] - '0', finalPosition[0]);
	
	if(colour) {	//White is making a move
		auto curPos = White.getPosFromPiece(piece);
		
		chessBoard[curPos.first][curPos.second] = "";
		colourOfPiece[curPos.first][curPos.second] = 0;
		
		White.makeMove(piece, finalPosition);
		curPos = White.getPosFromPiece(piece);

		chessBoard[curPos.first][curPos.second] = piece;
		colourOfPiece[curPos.first][curPos.second] = 1;
		
		if(Black.getPieceFromPos(pos) != "") {
			Black.removePiece(Black.getPieceFromPos(pos));
		}
	}
	else {	//Black is making a move
		auto curPos = Black.getPosFromPiece(piece);
		
		chessBoard[curPos.first][curPos.second] = "";
		colourOfPiece[curPos.first][curPos.second] = 0;
		
		Black.makeMove(piece, finalPosition);
		curPos = Black.getPosFromPiece(piece);
		
		chessBoard[curPos.first][curPos.second] = piece;
		colourOfPiece[curPos.first][curPos.second] = -1;
		
		if(White.getPieceFromPos(pos) != "") {
			White.removePiece(White.getPieceFromPos(pos));
		}
	}
}

bool State::isCheck(bool colour) {
	return false;
	if(colour) {
		auto king_pos = White.getPosFromPiece("K");

	}
}

bool State::validateMove(string piece, string finalPosition, bool colour) {
	return true;
	if(White.getPosFromPiece(piece) != make_pair(-1, 'z')) {
		return false;
	}

	pair<int, char> pos = make_pair(finalPosition[1] - '0', finalPosition[0]);
	pair<int, char> curPos = White.getPosFromPiece(piece);

	if(pos == curPos)	return false;
	if(pos.first < 1 || pos.first > 8)	return false;
	if(pos.second < 'a' || pos.second > 'h')	return false;

	if(isCheck(true) && piece!="K") {
		return false;
	}

	if(piece[0] == 'P') {
		if(abs(pos.first-curPos.first) != 1 || pos.first <= curPos.first)	return false;
		if(abs(pos.second-curPos.second) > 1)	return false;

		if(pos == make_pair(curPos.first+1, curPos.second)) {
			if(Black.getPieceFromPos(pos) != "")	return false;
		}
		
		if(pos == make_pair(curPos.first+1, (char) (curPos.second+1))) {
			if(Black.getPieceFromPos(pos) == "")	return false;
		}
		
		if(pos == make_pair(curPos.first+1, (char) (curPos.second-1))) {
			if(Black.getPieceFromPos(pos) == "")	return false;
		}
	}

	else if(piece[0] == 'R') {
		if(pos.first != curPos.first && pos.second != curPos.second)	return false;
		
		if(pos.first == curPos.first) {
			if(pos.second > curPos.second) {
				for(char i = curPos.second; i < pos.second; ++i) {
					if(Black.getPieceFromPos(make_pair(pos.first, i)) != "")	return false;
				}
			}
			else {
				for(char i = curPos.second; i > pos.second; --i) {
					if(Black.getPieceFromPos(make_pair(pos.first, i)) != "")	return false;
				}	
			}
		}
		else if(pos.second == curPos.second) {
			if(pos.first > curPos.first) {
				for(int i = curPos.first; i < pos.first; ++i) {
					if(Black.getPieceFromPos(make_pair(i, pos.second)) != "")	return false;
				}
			}
			else {
				for(int i = curPos.first; i > pos.first; --i) {
					if(Black.getPieceFromPos(make_pair(i, pos.second)) != "")	return false;
				}
			}
		}
	}
	else if(piece[0] == 'N') {
		
	}
	return true;
}