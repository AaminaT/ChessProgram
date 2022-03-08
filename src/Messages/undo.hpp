#include "message.hpp"

class Undo : public Mesasge {
	private:
		int back_turns;
		std :: string decision;
	public:
		Undo(int number_turns) : Message()
		{
			back_turns = number_turns;
		}
		std:: string info(){
			decision = "go back " + back_turns + "turns";
			return decision;}
}
