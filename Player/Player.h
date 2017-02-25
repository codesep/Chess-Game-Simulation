/*
	Class: Player

	Member Function: Player Constructor

	Takes input the type, i.e., white or black player, using a boolean variable. 

	Set up the initial configuration of the player.
*/

Player::Player(bool type){
	if(type == 1){	// Player with white pieces
		
		//	Pawns ('P')
		int ix = 1;
		for(char ch = 'a'; ch <= 'h'; ch++, ix++){
			pieces["WP" + to_string(ix)] = make_pair(2, ch);
			reversePieces[make_pair(2, ch)] = "WP" + to_string(ix);
		}

		// Rook	('R')
		pieces["WR1"] = make_pair(1, 'a');
		pieces["WR2"] = make_pair(1, 'h');
		reversePieces[make_pair(1, 'a')] = "WR1";
		reversePieces[make_pair(1, 'h')] = "WR2";


		// Knight	('N')
		pieces["WN1"] = make_pair(1, 'b');
		pieces["WN2"] = make_pair(1, 'g');
		reversePieces[make_pair(1, 'b')] = "WN1";
		reversePieces[make_pair(1, 'g')] = "WN2";

		//Bishop ('B')
		pieces["WB1"] = make_pair(1, 'c');
		pieces["WB2"] = make_pair(1, 'f');
		reversePieces[make_pair(1, 'c')] = "WB1";
		reversePieces[make_pair(1, 'f')] = "WB2";

		//Queen ('Q')
		pieces["WQ"] = make_pair(1, 'd');
		reversePieces[make_pair(1, 'd')] = "WQ";

		//King ('K')
		pieces["WK"] = make_pair(1, 'e');
		reversePieces[make_pair(1, 'e')] = "WK";

	}	
	else{			// Player with black pieces

		//	Pawns ('P')
		int ix = 1;
		for(char ch = 'a'; ch <= 'h'; ch++, ix++){
			pieces["BP" + to_string(ix)] = make_pair(7, ch);
			reversePieces[make_pair(7, ch)] = "WP" + to_string(ix);
		}

		// Rook	('R')
		pieces["BR1"] = make_pair(8, 'a');
		pieces["BR2"] = make_pair(8, 'h');
		reversePieces[make_pair(8, 'a')] = "WR1";
		reversePieces[make_pair(8, 'h')] = "WR2";

		// Knight	('N')
		pieces["BN1"] = make_pair(8, 'b');
		pieces["BN2"] = make_pair(8, 'g');
		reversePieces[make_pair(8, 'b')] = "WN1";
		reversePieces[make_pair(8, 'g')] = "WN2";

		//Bishop ('B')
		pieces["BB1"] = make_pair(8, 'c');
		pieces["BB2"] = make_pair(8, 'f');
		reversePieces[make_pair(8, 'c')] = "WB1";
		reversePieces[make_pair(8, 'f')] = "WB2";

		//Queen ('Q')
		pieces["BQ"] = make_pair(8, 'd');
		reversePieces[make_pair(8, 'd')] = "WQ";

		//King ('K')
		pieces["BK"] = make_pair(8, 'e');
		reversePieces[make_pair(8, 'e')] = "WK";

	}
}