#ifndef __GAME_HPP__
#define __GAME_HPP__

class Game: public Observer, public Listener {
	private:
	int id;

	public:
	Game(): Observer(), Listener() {}
}

#endif //__GAME_HPP__
