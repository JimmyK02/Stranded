#pragma once
#include "Character.h"

class Player: public Character
{
public:
	Player(sf::Vector2f size, sf::Vector2f position, sf::Texture& texture, float speed, float jumpHeight, sf::Vector2i imageCount, float switchTime, sf::CircleShape& island, const char* deathSoundLocation, float volume);
	void Update(float deltaTime);
	void GetCorners();

private:
	float jumpHeight;
    bool canJump;
};

