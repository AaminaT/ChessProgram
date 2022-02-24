#include "game.hpp"

class EndGame : public Game {
	private:
		Piece* check_king_status;
	public:
		bool info(){
			if(check_king_status.checkmate())
				return true;
			else
				return false;
		}
}
