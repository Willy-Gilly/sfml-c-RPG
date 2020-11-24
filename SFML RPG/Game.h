#pragma once

#include"State.h"
class Game
{
	private:
		//Variables
		sf::RenderWindow *window;
		sf::Event sfEvent;

		sf::Clock dtClock;
		float dt; //Delta time calculating how long does it take to update and render

		//Init
		void initWindow();

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

