#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::RectangleShape& character, sf::Texture& texture, sf::Vector2i& imageCount, float switchTime);
	void Update(float deltaTime, int row, int columns, bool facingRight, bool isDead);
	void DeathAnimation(float deltaTime, int row, bool facingRight);

private:
	sf::RectangleShape& character;
	sf::Texture& texture;
	sf::IntRect uvRect;
	float switchTime;
	float currentTime;
	int currentImage;
};

