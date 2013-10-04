

#include "Player.h"

namespace TicTacToe {

	Player::Player(char peice) : mPeice(peice) { }

	char Player::getPeice() const {
		return mPeice;
	}
}