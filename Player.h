

namespace TicTacToe {

	class Player {

	public:
		Player(char peice);
		char getPeice() const;

	protected:
		char mPeice;
	};
}