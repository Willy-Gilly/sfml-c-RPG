#include "GameState.h"

void GameState::initKeybinds()
{
	this->keybinds.emplace("moveUp", this->supportedKeys->at("Z"));
	this->keybinds.emplace("moveDown", this->supportedKeys->at("S"));
	this->keybinds.emplace("moveLeft", this->supportedKeys->at("Q"));
	this->keybinds.emplace("moveRight", this->supportedKeys->at("D"));

	this->keybinds.emplace("moveUp2", this->supportedKeys->at("Up"));
	this->keybinds.emplace("moveDown2", this->supportedKeys->at("Down"));
	this->keybinds.emplace("moveLeft2", this->supportedKeys->at("Left"));
	this->keybinds.emplace("moveRight2", this->supportedKeys->at("Right"));

}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initKeybinds();
}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "Ending GameState\n";
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();

	//Update player Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("moveUp"))) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("moveUp2"))))
	{
		this->player.move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("moveLeft"))) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("moveLeft2"))))
	{
		this->player.move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("moveDown"))) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("moveDown2"))))
	{
		this->player.move(dt, 0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("moveRight"))) || 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("moveRight2"))))
	{
		this->player.move(dt, 1.f, 0.f);
	}
}

void GameState::update(const float& dt)
{
	this->updateInput(dt);

	this->player.update(dt);
	
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->player.render(this->window);
}
