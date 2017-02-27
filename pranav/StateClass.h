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
	bool validateWhiteMove(string, string);
	bool isCheck(bool);
	void makeMove(string, string, bool);
	bool checkmate(bool);
	vector<pair<string, string> > getValidActions(bool);
};

bool State::checkmate(bool colour) {

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
	if(colour) {
		auto king_pos = White.getPosFromPiece("K");

	}
}

bool State::validateWhiteMove(string piece, string finalPosition) {
	if(White.getPosFromPiece(piece) != make_pair(-1, 'z')) {
		return false;
	}
	bool colour = true;

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

vector<pair<string, string> > State::getValidActionsPawn(string piece, pair<int, char> currentPosition, int colour){
	int i = currentPosition.first;
	char ch = currentPosition.second;

	vector<pair<string, string> > ret;

	if(colour == 1){

		if(i + 1<=8 && chessBoard[i + 1][ch] == ""){
	        ret.push_back(make_pair(piece, to_string(i + 1) + ch));
	        if(i == 2 && tile[i + 2][ch] == "")
		        ret.push_back(make_pair(piece, to_string(i + 2) + ch));
		}

	    if(i + 1<=8 && ch + 1<='h' && colourOfPiece[i + 1][ch + 1] == -1)
	        ret.push_back(make_pair(piece, to_string(i + 1) + char(ch + 1)));

	    if(i + 1 <= 8 && ch - 1 >= 'a' && colourOfPiece[i + 1][ch - 1] == -1)
	    	ret.push_back(make_pair(piece, to_string(i + 1) + char(ch - 1)));		
	}
	else{
		if(i - 1 >= 1 && chessBoard[i - 1][ch] == ""){
	        ret.push_back(make_pair(piece, to_string(i - 1) + ch));
	        if(i == 7 && tile[i - 2][ch] == "")
		        ret.push_back(make_pair(piece, to_string(i - 2) + ch));
		}

	    if(i - 1 >= 1 && ch + 1<='h' && colourOfPiece[i - 1][ch + 1] == 1)
	        ret.push_back(make_pair(piece, to_string(i - 1) + char(ch + 1)));

	    if(i - 1 >= 1 && ch - 1 >= 'a' && colourOfPiece[i - 1][ch - 1] == 1)
	    	ret.push_back(make_pair(piece, to_string(i - 1) + char(ch - 1)));			
	}
	return ret;
}

vector<pair<string, string> > State::getValidActions(int colour){
	vector<pair<string, string> > Actions;
	for(int r = 1; r <= 8; r++){
		for(char ch = 'a'; ch <= 'h'; ch++){
			if(colourOfPiece[r][ch] == colour*-1){
				vector<pair<string, string> > tmp;

				switch(chessBoard[r][ch][0]){
					case 'P': ret = getValidActionsPawn
				}

				for(int i = 0; i < tmp.size(); i++)
					Actions.push_back(tmp[i]);
			}
		}
	}
}






























