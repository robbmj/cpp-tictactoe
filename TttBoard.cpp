

#include <cstddef>

#include <stdexcept>
#include <iostream>
#include "TttBoard.h"

using namespace std;

namespace TicTacToe {

	TttBoard::TttBoard(int dimension) : mDimension(dimension) { 

		mCells = new TttCell* [dimension];

		for (int i = 0; i < dimension; ++i) {
			mCells[i] = new TttCell[dimension];
		}
	}

	TttBoard::~TttBoard() {
		
		for (int i = 0; i < mDimension; ++i) {

			delete [] mCells[i];
		}

		delete [] mCells;

		mCells = NULL;
	}

	TttBoard::TttBoard(const TttBoard& cpy) {

	}

	TttBoard& TttBoard::operator=(const TttBoard& rhs) {

	}

	char TttBoard::getPeiceAt(int row, int column) const {
		boundsCheck(row, column);
		return mCells[row][column].getPeice();
	}		

	void TttBoard::setPeiceAt(int row, int column, char peice) {
		boundsCheck(row, column);
		if (!isMoveLegal(row, column)) {
			throw invalid_argument("There is already a peice in the specified cell");
		}
		mCells[row][column].setPeice(peice);
	}

	char TttBoard::declareWinner() const {
		
		char winnerIs = isHorizonalWin();

		winnerIs = winnerIs == ' ' ? isVerticalWin() : winnerIs;

		winnerIs = winnerIs == ' ' ? isDiaganlWin() : winnerIs;

		return winnerIs;
	}

	char TttBoard::isHorizonalWin() const {


		for (int i = 0; i < mDimension; ++i) {
			
			char atLeftOfBoard = mCells[i][0].getPeice();

			if (atLeftOfBoard != ' ') {
				
				int inARow = 1;

				for (int j = 1; j < mDimension; ++j) {

					//cout << i << " " << j << endl;
					if (mCells[i][j].getPeice() == atLeftOfBoard) {
						inARow++;
					}
				}

				if (inARow == mDimension) {
					return atLeftOfBoard;
				}
			}
			
		}

		return ' ';
	}

	char TttBoard::isVerticalWin() const {
		for (int i = 0; i < mDimension; ++i) {
			
			char atTopOfBoard = mCells[0][i].getPeice();

			if (atTopOfBoard != ' ') {

				int inARow = 1;

				for (int j = 1; j < mDimension; ++j) {

					if (mCells[j][i].getPeice() == atTopOfBoard) {
						inARow++;
					}
				}

				if (inARow == mDimension) {
					return atTopOfBoard;
				}
			}
			
		}

		return ' ';
	}

	char TttBoard::isDiaganlWin() const {

		char atTopLeft = mCells[0][0].getPeice();

		if (atTopLeft != ' ') {

			int inARow = 1;

			for (int i = 1, j = 1; i < mDimension; i++, j++) {

				if (mCells[i][j].getPeice() == atTopLeft) {
					inARow++;
				}
			}

			if (inARow == mDimension) {
				return atTopLeft;
			}
		}

		int d = mDimension - 1;

		char atTopRight = mCells[0][d].getPeice();

		if (atTopRight != ' ') {

			int inARow = 1;

			for (int i = 1, j = d - 1; i < mDimension; i++, j--) {

				cout << i << " " << j << endl;

				if (mCells[i][j].getPeice() == atTopRight) {
					inARow++;
				}
			}

			cout << inARow << endl;

			if (inARow == mDimension) {
				return atTopRight;
			}
		}

		return ' ';
	}

	bool TttBoard::isBoardFull() const {

		int numCellsFilled = 0;

		for (int i = 0; i < mDimension; ++i) {
			for (int j = 0; j < mDimension; ++j) {

				if (mCells[i][j].getPeice() != ' ') {
					++numCellsFilled;
				}
			}
		}

		return numCellsFilled == mDimension * mDimension;
	}

	bool TttBoard::isMoveLegal(int row, int column) const {
		try {
			boundsCheck(row, column);
		}
		catch (const out_of_range& e) {
			return false;
		}
		return mCells[row][column].getPeice() == ' ';
	}

	char** TttBoard::boardRepresentation() const {

		char** board = new char* [mDimension];

		for (int i = 0; i < mDimension; i++) {

			board[i] = new char [mDimension];

			for (int j = 0; j < mDimension; j++) {

				board[i][j] = mCells[i][j].getPeice();
			}
		}

		return board;
	}

	void TttBoard::boundsCheck(int row, int column) const {
		if (row >= mDimension || column >= mDimension) {
			throw out_of_range("Out of Play area");
		}
	}

	//oid isWin() {

		// for each row
			// for each column
				// if the row index is 0 and the col index is 0
					// todo figure out how to do this
				// else if the row is 0 and the col is 1 less than the bounds
					// todo figure out how to do this
				// else if the row is 0 and the col is not on the boundry
					// todo figure out how to do this
				// else if the col is 0 and the row in not on the boundry
					// todo figure out how to do this
	//}
}
