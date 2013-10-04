
#include <iostream>
#include <cstddef>		

#include "GameController.h"

using namespace std;

namespace TicTacToe {

	GameController::GameController(int numPlayers, int dimension) 
		: mNumPlayers(numPlayers)
		, mDimension(dimension)
		, mTurn(0) 
	{

		mPlayers = new Player* [numPlayers];

		mPlayers[0] = new Player('X');
		mPlayers[1] = new Player('O');

		char peice = 'A';

		for (int i = 2; i < numPlayers; ++i) {
			mPlayers[i] = new Player(peice);
			peice++;
		}
		
		mBoard = new TttBoard(dimension);
	}

	GameController::~GameController() {

		for (int i = 0; i < mDimension; ++i) {
			delete mPlayers[i];	
		}

		delete [] mPlayers;
		mPlayers = NULL;

		delete mBoard;
		mBoard = NULL;
	}

	void GameController::run() {

		cout << "Starting TicTacToe " << endl;

		char winningPlayer = ' ';

		do {

			printBoard();
			getMove();
			winningPlayer = mBoard->declareWinner();
			incrementTurn();

		}
		while (winningPlayer == ' ' && !mBoard->isBoardFull());

		printBoard();

		if (winningPlayer != ' ') {
			cout << "Congrats player " << winningPlayer << " you WON!!!!!" << endl;
		}
		else {
			cout << "You guys tied" << endl;
		}
	}

	void GameController::getMove() {

		char activePlayer = mPlayers[mTurn]->getPeice();

		int row, column;

		do {

			cout << "Player " << activePlayer << "'s turn, please make your move: ";

			cin >> row >> column;
		}
		while (!mBoard->isMoveLegal(row, column));
		
		mBoard->setPeiceAt(row, column, activePlayer);
	}

	void GameController::printBoard() const {
		
		char** board = mBoard->boardRepresentation();

		cout << endl;

		for (int i = 0; i < mDimension; ++i) {

			cout << "|";

			for (int j = 0; j < mDimension; ++j) {

				cout << board[i][j] << "|";
			}

			cout << endl;
		}

		for (int i = 0; i < mDimension; i++) {

			delete [] board[i];
		}

		delete [] board;

		board = NULL;
	}

	void GameController::incrementTurn() {
		if (mTurn == mNumPlayers - 1) {
			mTurn = 0;
		}
		else {
			++mTurn;
		}
	}
}