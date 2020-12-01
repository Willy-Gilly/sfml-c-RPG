#include "MainMenuState.h"
#include "Button.h"

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/pkmndp.ttf"))
	{
		throw("Error : couldn't lood ttf file ");
	}
}

void MainMenuState::initKeybinds()
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

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initFonts();
	this->initKeybinds();
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Green);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::endState()
{
	std::cout << "Ending MainMenuState\n";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);

	this->updateMousePosition();

	system("cls"); //Clear console
	std::cout << "pos view :" << this->mousePosView.x << "," << this->mousePosView.y <<
		"\npos screen : " << this->mousePosScreen.x << "," << this->mousePosScreen.y <<
		"\npos window : " << this->mousePosWindow.x << "," << this->mousePosWindow.y;
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(this->background);
}
