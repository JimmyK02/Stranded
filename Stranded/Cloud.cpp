#include "Cloud.h"

//Constructor
Cloud::Cloud(const char* texturePath, sf::Vector2f beginPosition, float moveSpeed) {
	//Loading a texture 
	sf::Texture texture;
	texture.loadFromFile(texturePath);
	this->texture = texture;
	//Setting the sprite texture and position
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(beginPosition);
	//Setting the horizontal move speed
	this->moveSpeedX = moveSpeed;

	//Setting the origin of the sprite to the center
	this->sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
}

//Update the position of the clouds
void Cloud::Update(float deltaTime) {
	//Move the sprite
	sprite.move( moveSpeedX * deltaTime, 0);

	//If the sprite is out of reach of the screen, assigning a new position to the cloud
	if (sprite.getPosition().x > 1750) 
		sprite.setPosition(-750, sprite.getPosition().y);
	else if (sprite.getPosition().x < -750)
		sprite.setPosition(1750, sprite.getPosition().y);
}

void Cloud::Draw(sf::RenderWindow &window) {
	//Drawing the cloud to the screen
	window.draw(sprite);
}
