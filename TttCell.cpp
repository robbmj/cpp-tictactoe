
#include "TttCell.h"

namespace TicTacToe {

	TttCell::TttCell() : mPeice(' ') { }

	char TttCell::getPeice() const {
		return mPeice;
	}

	void TttCell::setPeice(char peice) {
		mPeice = peice;
	}
}