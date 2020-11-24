#pragma once

#include"GameState.h"
class Game
{
	private:
		//Variables
		sf::RenderWindow *window;
		sf::Event sfEvent;

		sf::Clock dtClock;
		float dt; //Delta time calculating how long does it take to update and render

		std::stack<State*> states; // state is abstract class

		//Init
		void initWindow();
		void initStates();

	public:
		//Constructs / Destructs
		Game();
		virtual ~Game();

		//Functions
		void updateDt();
		void updateSFMLEvents();
		void update();
		void render();
		void run();
};

