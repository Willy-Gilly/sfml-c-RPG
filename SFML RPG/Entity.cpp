#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::Red);
	this->mouvementSpeed = 250.f;
}

Entity::~Entity()
{
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Entity::move(const float& dt, const float dirX, const float dirY, const float dirZ) //delta time to calculate the time it takes
//x -> position horizontal, y -> position vertical, z -> hauteur
{
	this->shape.move(dirX * this->mouvementSpeed * dt, dirY * this->mouvementSpeed * dt);
}
