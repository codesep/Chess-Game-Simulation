/*
	Class: State

	Member Function: makeMoveBlack

	Takes input the piece name and the position ('finalPosition') to which the piece is to be moved.
	
	Function moves the piece to the 'finalPosition' and freeing the block occupied earlier.

	Can also remove one of the piece of the opponent Player.
*/

void State::makeMoveBlack(string piece, string finalPosition){
	//Get final position of the piece to be moved
	pair<int, char> pos = make_pair(finalPostion[0] - '0', finalPostion[1]);

	// Get the current position of the piece.
	pair<int, char> currentPosition = Black.getPosFromPiece(piece);

	// Remove the piece from it's current position
	chessBoard[currentPosition] = "";

	// Black player makes a move
	Black.makeMove(piece, finalPosition);

	// Check if there was a black piece already at the finalPosition
	if(colorOfPiece[pos] == 1){

		// Remove the white piece occupying the final position.
		White.removePiece( chessBoard[pos] );
	}

	// Move the piece to final position on the chess board
	chessBoard[pos] = piece;

	// Make the color of piece at the final position to 1.
	colorOfPiece[pos] = -1;
}