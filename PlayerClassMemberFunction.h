// Initial Configuration of the players
Player::Player(bool type){
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


//Making a move
void Player::makeMove(Player &opponent, string piece, string finalPostion){
	//Get final position of the piece to be moved
	pair<int, char> pos = make_pair(finalPostion[0] - '0', finalPostion[1]);

	//Check if opponent's piece is present in the final position or not
	if(opponent.reversePieces[pos] == ""){
		//Remove the piece from it's current position
		this->reversePieces[this->pieces[piece]] = "";

		//Move the piece to the final position
		this->pieces[piece] = pos;

		//Update reversePieces for the piece
		this->reversePieces[pos] = piece;
	}
}