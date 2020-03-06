#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Animation.h"
#include <cmath>
#include <algorithm>


class Character
{
public:
	Character( sf::Texture& texture, sf::Vector2i imageCount, float switchTime, sf::CircleShape& island, const char* deathSoundLocation, float volume, sf::Vector2f size = sf::Vector2f(0,0), sf::Vector2f position = sf::Vector2f(0, 0), float speed = 0.0f);
	void Draw(sf::RenderWindow &window);
	virtual void Update(float deltaTime) = 0;
	bool CheckCollision(sf::CircleShape &island);
	bool CheckCollision(Character *character);
	virtual void GetCorners();
	void Die(bool die);
	void SetPosition(sf::Vector2f position);

	//Accessors
	sf::Vector2f GetSize();
	bool IsDead();
	sf::Vector2f GetPosition();

private:
	sf::SoundBuffer deathSoundBuffer;
	sf::Sound deathSound;

protected:
	sf::Vector2f velocity;
	sf::RectangleShape body;
	sf::CircleShape &island;
	sf::Texture& texture;
	sf::Vector2i imageCount;
	float switchTime;
	Animation animation;
	float speed;
	bool facingRight;
	const float GRAVITY = 981.0f;
	bool isDead;

public:
	float bottom, top, right, left;

};

