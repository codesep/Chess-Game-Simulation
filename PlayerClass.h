class Player{
	map<string, pair<int, char> > pieces;
public:
	Player(bool type){
		if(type == 1){	// Player with white pieces
			
			//	Pawns ('P')
			char ix = '1';
			for(char ch = 'a'; ch <= 'h'; ch++, ix++)
				pieces["P" + ix] = make_pair(2, ch);

			// Rook	('R')
			pieces["R1"] = make_pair(1, 'a');
			pieces["R2"] = make_pair(1, 'h');

			// Knight	('N')
			pieces["N1"] = make_pair(1, 'b');
			pieces["N2"] = make_pair(1, 'g');

			//Bishop ('B')
			pieces["B1"] = make_pair(1, 'c');
			pieces["B2"] = make_pair(1, 'f');

			//Queen ('Q')
			pieces["Q"] = make_pair(1, 'd');

			//King ('K')
			pieces["K"] = make_pair(1, 'e');

		}	
		else{			// Player with black pieces

			//	Pawns ('P')
			char ix = '1';
			for(char ch = 'a'; ch <= 'h'; ch++, ix++)
				pieces["P" + ix] = make_pair(7, ch);

			// Rook	('R')
			pieces["R1"] = make_pair(8, 'a');
			pieces["R2"] = make_pair(8, 'h');

			// Knight	('N')
			pieces["N1"] = make_pair(8, 'b');
			pieces["N2"] = make_pair(8, 'g');

			//Bishop ('B')
			pieces["B1"] = make_pair(8, 'c');
			pieces["B2"] = make_pair(8, 'f');

			//Queen ('Q')
			pieces["Q"] = make_pair(8, 'd');

			//King ('K')
			pieces["K"] = make_pair(8, 'e');

		}
	}		
};