#pragma once
#include <SFML/Graphics.hpp>

class Cloud
{

public:
	Cloud(const char* texturePath, sf::Vector2f beginPosition, float moveSpeed);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::Texture texture;
	sf::Sprite sprite;
	float moveSpeedX;

};

