#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>

#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

class State
{
	private:
		std::vector<sf::Texture> textures;
	public:
		State();
		virtual ~State();

		virtual void update() = 0; //Virtual est l'�quivalent des abstract qui doivent �tre d�finies imp�rativement dans la classe qui h�rite de State
		virtual void render() = 0;
};

