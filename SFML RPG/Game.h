#pragma once

#include "MainMenuState.h"
class Game
{
	private:
		//Variables
		sf::RenderWindow *window;
		sf::Event sfEvent;

		sf::Clock dtClock;
		float dt; //Delta time calculating how long does it take to update and render

		std::stack<State*> states; // state is abstract class

		std::map<std::string, int> supportedKeys;

		//Init
		void initWindow();
		void initStates();
		void initKeys();
	public:
		//Constructs / Destructs
		Game();
		virtual ~Game();

		//Functions



		//Updates
		void updateDt();
		void updateSFMLEvents();
		void update();

		//Renders
		void render();

		//Cores
		void run();
		void endApplication();
};

