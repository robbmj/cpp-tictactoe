
#include "TttCell.h"

namespace TicTacToe {

	class TttBoard {

	public:
		TttBoard(int dimension = 3);
		TttBoard(const TttBoard& cpy);
		~TttBoard();

		TttBoard& operator=(const TttBoard& rhs);

		char getPeiceAt(int row, int column) const;
		void setPeiceAt(int row, int column, char peice);

		char declareWinner() const;

		bool isBoardFull() const;
		bool isMoveLegal(int row, int column) const;

		char** boardRepresentation() const;

	protected:
		TttCell** mCells;
		int mDimension;

		void boundsCheck(int row, int column) const;

		char isHorizonalWin() const;
		char isVerticalWin() const;
		char isDiaganlWin() const;
	};

}