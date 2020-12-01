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

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys));
    this->states.push(new GameState(this->window, &this->supportedKeys));
}

void Game::initKeys()
{
    std::ifstream ifs("Config/supportedKeys.ini");

    if (ifs.is_open())
    {
        std::string key;
        int keyValue;

        while (ifs >> key >> keyValue)
        {
            this->supportedKeys[key] = keyValue;
        }
    }
    else
    {
        std::cout << "Problem with Config/supportedKeys.ini file";
    }
    ifs.close();

    /* All the keys are in supportedKeys.ini
    * each line is "KeyName KeyValue"
    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
    this->supportedKeys["C"] = sf::Keyboard::Key::C;

    this->supportedKeys["Z"] = sf::Keyboard::Key::Z;
    this->supportedKeys["Q"] = sf::Keyboard::Key::Q;
    this->supportedKeys["S"] = sf::Keyboard::Key::S;
    this->supportedKeys["D"] = sf::Keyboard::Key::D;

    this->supportedKeys["Up"] = sf::Keyboard::Key::Up;
    this->supportedKeys["Down"] = sf::Keyboard::Key::Down;
    this->supportedKeys["Left"] = sf::Keyboard::Key::Left;
    this->supportedKeys["Right"] = sf::Keyboard::Key::Right;
    */

    //Debug lines
    for (auto i : this->supportedKeys)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}

//Constructs Destructs
Game::Game() //construct
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game() //destruct
{
	delete this->window;

    while (!this->states.empty()) //We will remove each state one by one while closing
    {
        delete this->states.top();
        this->states.pop();
    }
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

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt); // Update the state at top.
        //But if we want to quit the state : 
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top(); // We delete the item from memory
            this->states.pop(); //Then we remove it from the stack (list)
        }
    }
    else // Game close
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();
    //Render Items
    if (!this->states.empty())
    {
        this->states.top()->render(); // Render the state at top.
    }

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

void Game::endApplication()
{
    std::cout << "Closing game!\n";
}
