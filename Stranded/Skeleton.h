#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>

class Skeleton: public Character
{
public:
	Skeleton(sf::Texture& texture, sf::Vector2i imageCount, float switchTime, Character* p, sf::CircleShape& island, const char* deathSoundLocation, float volume, sf::Vector2f size = sf::Vector2f(0, 0), sf::Vector2f position = sf::Vector2f(0, 0), float speed = 0.0f);
	void Update(float deltaTime);
	void GetCorners();
	void ResetStats();

private:
	Character* character;
};

