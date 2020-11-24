#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

class State
{
	private:
		sf::RenderWindow* window;
		std::vector<sf::Texture> textures;
	public:
		State(sf::RenderWindow* window);
		virtual ~State();

		virtual void endState() = 0;

		virtual void update(const float& dt) = 0; //Virtual est l'équivalent des abstract qui doivent être définies impérativement dans la classe qui hérite de State
		virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

