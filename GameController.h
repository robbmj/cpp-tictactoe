
#include "Player.h"
#include "TttBoard.h"

namespace TicTacToe {

	class GameController {

	public:
		GameController(int numPlayers = 2, int dimension = 3);
		~GameController();
		
		void run();

		void printBoard() const;
		
	protected:

		void getMove(); 

		void incrementTurn();

		int mTurn;
		int mNumPlayers;

		int mDimension;

		Player** mPlayers;
		TttBoard* mBoard;

		// controller should
			// wait on moves from the view
			// ask model if the input is good
				// update the model
			// apprise the view of model state
				// including whos turn it is and the board state

		// view should
			// promt plater for move
			// hand input to controller
				// promt user bad input
			// else
				// display new board state
				// ask player for input
	};
}