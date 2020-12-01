#include "GameState.h"

void GameState::initKeybinds()
{
	std::ifstream ifs("Config/gameStateKeybinds.ini");

	if (ifs.is_open())
	{
		std::string key;
		std::string keyValue;

		while (ifs >> key >> keyValue)
		{
			this->keybinds[key] = this->supportedKeys->at(keyValue);
		}
	}
	else
	{
		throw("Problem with Config/gameStateKeybinds.ini file");
	}
	ifs.close();
	/* Now keys are into "Config/gameStateKeybinds.ini" file
	this->keybinds["close"] = this->supportedKeys->at("Escape");
	this->keybinds["c"] = this->supportedKeys->at("C");

	this->keybinds["moveUp"] = this->supportedKeys->at("Z");
	this->keybinds["moveDown"] = this->supportedKeys->at("S");
	this->keybinds["moveLeft"] = this->supportedKeys->at("Q");
	this->keybinds["moveRight"] = this->supportedKeys->at("D");

	this->keybinds["moveUp2"] = this->supportedKeys->at("Up");
	this->keybinds["moveDown2"] = this->supportedKeys->at("Down");
	this->keybinds["moveLeft2"] = this->supportedKeys->at("Left");
	this->keybinds["moveRight2"] = this->supportedKeys->at("Right");
	*/
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
	this->updateMousePosition();

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
