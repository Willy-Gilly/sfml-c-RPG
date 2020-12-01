#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Entity
{
private:

protected:
	sf::RectangleShape shape;
	float mouvementSpeed;
public:
	Entity();
	virtual ~Entity();

	//Functions
	void update(const float& dt);
	void render(sf::RenderTarget* target);

	virtual void move(const float& dt,const float x, const float y, const float z = 0);

};

