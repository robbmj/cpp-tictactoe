

namespace TicTacToe {

	class TttCell {

	public:
		TttCell();

		char getPeice() const;
		void setPeice(char peice);

	protected:
		char mPeice;
	};
}