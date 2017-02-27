class Player{
	map<string, pair<int, char> > pieces;
	map<pair<int, char>, string> reversePieces;
	set<string> removedPieces;
	bool colour;
public:

	// Initial Configuration of the players
	Player(bool);
	void makeMove(string, string);
	void removePiece(string);
	pair<int, char> getPosFromPiece(string);
	string getPieceFromPos(pair<int, char>);
	map<string, pair<int, char> > getAvailablePieces();
};

map<string, pair<int, char> > Player::getAvailablePieces() {
	return pieces;
}

void Player::makeMove(string piece, string finalPosition) {
	pair<int, char> pos = make_pair(finalPosition[1] - '0', finalPosition[0]);

	//Remove the piece from it's current position
	reversePieces[pieces[piece]] = "";

	//Move the piece to the final position
	pieces[piece] = pos;

	//Update reversePieces for the piece
	reversePieces[pos] = piece;
}

void Player::removePiece(string piece) {
	pair<int, char> pos = pieces[piece];
	removedPieces.insert(piece);
	pieces.erase(piece);
	reversePieces.erase(pos);
}

pair<int, char> Player::getPosFromPiece(string piece) {
	if(pieces.find(piece) == pieces.end())	return make_pair(-1, 'z');
	return pieces[piece];
}

string Player::getPieceFromPos(pair<int, char> pos) {
	if(reversePieces.find(pos) == reversePieces.end())	return "";
	return reversePieces[pos];
}

// Initial Configuration of the players
Player::Player(bool type){
	colour = type;
	if(type == 1){	// Player with white pieces
		
		//	Pawns ('P')
		int ix = 1;
		for(char ch = 'a'; ch <= 'h'; ch++, ix++){
			pieces["P" + to_string(ix)] = make_pair(2, ch);
			reversePieces[make_pair(2, ch)] = "P" + to_string(ix);
		}

		// Rook	('R')
		pieces["R1"] = make_pair(1, 'a');
		pieces["R2"] = make_pair(1, 'h');
		reversePieces[make_pair(1, 'a')] = "R1";
		reversePieces[make_pair(1, 'h')] = "R2";


		// Knight	('N')
		pieces["N1"] = make_pair(1, 'b');
		pieces["N2"] = make_pair(1, 'g');
		reversePieces[make_pair(1, 'b')] = "N1";
		reversePieces[make_pair(1, 'g')] = "N2";

		//Bishop ('B')
		pieces["B1"] = make_pair(1, 'c');
		pieces["B2"] = make_pair(1, 'f');
		reversePieces[make_pair(1, 'c')] = "B1";
		reversePieces[make_pair(1, 'f')] = "B2";

		//Queen ('Q')
		pieces["Q"] = make_pair(1, 'd');
		reversePieces[make_pair(1, 'd')] = "Q";

		//King ('K')
		pieces["K"] = make_pair(1, 'e');
		reversePieces[make_pair(1, 'e')] = "K";

	}	
	else{			// Player with black pieces

		//	Pawns ('P')
		int ix = 1;
		for(char ch = 'a'; ch <= 'h'; ch++, ix++){
			pieces["P" + to_string(ix)] = make_pair(7, ch);
			reversePieces[make_pair(7, ch)] = "P" + to_string(ix);
		}

		// Rook	('R')
		pieces["R1"] = make_pair(8, 'a');
		pieces["R2"] = make_pair(8, 'h');
		reversePieces[make_pair(8, 'a')] = "R1";
		reversePieces[make_pair(8, 'h')] = "R2";

		// Knight	('N')
		pieces["N1"] = make_pair(8, 'b');
		pieces["N2"] = make_pair(8, 'g');
		reversePieces[make_pair(8, 'b')] = "N1";
		reversePieces[make_pair(8, 'g')] = "N2";

		//Bishop ('B')
		pieces["B1"] = make_pair(8, 'c');
		pieces["B2"] = make_pair(8, 'f');
		reversePieces[make_pair(8, 'c')] = "B1";
		reversePieces[make_pair(8, 'f')] = "B2";

		//Queen ('Q')
		pieces["Q"] = make_pair(8, 'd');
		reversePieces[make_pair(8, 'd')] = "Q";

		//King ('K')
		pieces["K"] = make_pair(8, 'e');
		reversePieces[make_pair(8, 'e')] = "K";

	}
}

