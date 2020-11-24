#include "Game.h"

//Static Functions

//Init Functions

void Game::initWindow()
{
    //Make window with option from .ini file 
    std::ifstream fileStream("Config/window.ini");

    std::string title = "Error missing window.ini file";
    sf::VideoMode windowSize(800, 600);
    unsigned framerateLimit = 120;
    bool verticalSyncEnabled = false;

    if (fileStream.is_open())
    {
        std::getline(fileStream, title);
        fileStream >> windowSize.width >> windowSize.height;
        fileStream >> framerateLimit;
        fileStream >> verticalSyncEnabled;
        fileStream.close();
    }
    else
    {
        std::cout << "Windows config file missing, need a file named Config/window.ini\n";
    }
    
	this->window = new sf::RenderWindow(windowSize, title);
    this->window->setFramerateLimit(framerateLimit);
    this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

//Constructs Destructs
Game::Game() //construct
{
    this->initWindow();
}

Game::~Game() //destruct
{
	delete this->window;
}

//Functions

void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();

    //system("cls"); See how much time it takes to update
    //std::cout << this->dt << "\n";
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window->clear();
    //Render Items
    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
