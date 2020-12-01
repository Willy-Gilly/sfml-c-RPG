#pragma once

#include "Entity.h"

class State
{
	private:
	protected:
		sf::RenderWindow* window;
		bool quit;
		std::map<std::string, int>* supportedKeys;
		std::map<std::string, int> keybinds;

		sf::Vector2i mousePosScreen; //2u means 2 dimensions unsigned
		sf::Vector2i mousePosWindow; //2i means 2 dimensions int
		sf::Vector2f mousePosView; //2f means 2 dimensions float

		//Resources
		std::vector<sf::Texture> textures;

		//Functions
		virtual void initKeybinds() = 0;
	public:
		State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
		virtual ~State();

		const bool& getQuit() const;
		virtual void checkForQuit();
		virtual void endState() = 0;
		virtual void updateMousePosition();

		virtual void updateInput(const float& dt) = 0;
		virtual void update(const float& dt) = 0; //Virtual est l'équivalent des abstract qui doivent être définies impérativement dans la classe qui hérite de State
		virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

