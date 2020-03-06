#include "Character.h"

//Constructor
Character::Character(sf::Texture& texture, sf::Vector2i imageCount, float switchTime, sf::CircleShape& island, const char* deathSoundLocation, float volume, sf::Vector2f size , sf::Vector2f position , float speed )
	:texture(texture), animation(body, texture, imageCount, switchTime), island(island)
{
	//Setting the speed, amount of images (of the sprite sheet) and the switch time
	this->speed = speed;
	this->imageCount = imageCount;
	this->switchTime = switchTime;

	//Setting isDead to false and make the character face right by default
	isDead = false;
	facingRight = true;
	//Setting the position, size, texture and origin of the character body
	body.setPosition(position);
	body.setSize(size);
	body.setTexture(&texture);
	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);

	//Setting the sound played upon death
	deathSoundBuffer.loadFromFile(deathSoundLocation);
	deathSound.setBuffer(deathSoundBuffer);
	deathSound.setVolume(volume);

	//Getting the corners of the character
	GetCorners();
}

void Character::SetPosition(sf::Vector2f position) {
	//Setting a new position
	body.setPosition(position);
}

void Character::Die(bool die) {
	//Setting isDead to true or false
	isDead = die;
	//If the character died, play his death sound
	if (die)
		deathSound.play();
}

void Character::Draw(sf::RenderWindow& window) {
	//Draw the body to the screen
	 window.draw(body);
}

sf::Vector2f Character::GetPosition() {
	//Return the position of the character
	return sf::Vector2f(body.getPosition());
}

sf::Vector2f Character::GetSize() {
	//Return the size of the character
	return sf::Vector2f(right - left, bottom - top);
}

//Check for circle collision (used to check collision between the characters and the island)
bool Character::CheckCollision(sf::CircleShape &island) {
	//Using the Pythagorean theorem to check if the island and character collide
	if (sqrt(pow(body.getPosition().x - island.getPosition().x, 2) + pow(body.getPosition().y - island.getPosition().y, 2)) >= island.getRadius() + (body.getSize().y / 2) - 5.0f)
		return false;
	return true;
}

void Character::GetCorners(){
	//Getting the corners of the image
	bottom = body.getPosition().y + (body.getSize().y / 2);
	top = body.getPosition().y - (body.getSize().y / 2);
	left = body.getPosition().x - (body.getSize().x / 2);
	right = body.getPosition().x + (body.getSize().x / 2);
}

//Check for box collision (used to check collision between characters)
bool Character::CheckCollision(Character *character)
{	

	//Getting the corners of this character and one other character
	GetCorners();
	character->GetCorners();

	//If the boxes are not overlapping, return false. Else, return true.
	if (right <= character->left || left >= character->right || bottom <= character->top || top >= character->bottom)
		return false;		
	return true;
}

bool Character::IsDead() {
	//Return the isDead boolean
	return this->isDead;
}
 