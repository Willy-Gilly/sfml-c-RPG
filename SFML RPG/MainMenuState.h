#pragma once
#include "GameState.h"
class MainMenuState : public State
{
private:
	//Variables

	sf::RectangleShape background;
	sf::Font font;
	//Functions
	void initFonts();
	void initKeybinds();
public:
	//Construct Destruct
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();

	//Functions
	void endState();

	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

