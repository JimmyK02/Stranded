#include "Player.h"

//This class is inherited from the Character class

Player::Player(sf::Vector2f size, sf::Vector2f position, sf::Texture& texture, float speed, float jumpHeight, sf::Vector2i imageCount, float switchTime, sf::CircleShape& island, const char* deathSoundLocation, float volume)
	:Character(texture, imageCount, switchTime, island, deathSoundLocation, volume, size, position, speed)
{
	//Setting the jumpHeight
	this->jumpHeight = jumpHeight;
	//Setting canJump to false by default, the player first has to hit the ground before being able to jump
	canJump = false;
}

void Player::GetCorners() {
	//Getting the corners of the player body. 
	//The reason that I substract/add some values to it, is to exclude the empty pixels of the texture
	bottom = body.getPosition().y + (body.getSize().y / 2) - (10 * (body.getSize().y / (texture.getSize().y / imageCount.y)));
	top = body.getPosition().y - (body.getSize().y / 2) + (19 * (body.getSize().y / (texture.getSize().y / imageCount.y)));
	left = body.getPosition().x - (body.getSize().x / 2)+ (26 * (body.getSize().x / (texture.getSize().x / imageCount.x)));
	right = body.getPosition().x + (body.getSize().x/ 2) - (24 * (body.getSize().x / (texture.getSize().x / imageCount.x)));
}

//Updating the position of the player (and updating the animation)
void Player::Update(float deltaTime) {
	
	int row, columns;
	//Resetting the horizontal velocity to 0
	velocity.x = 0;

	//Check if the player pressed A
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		//Set the horizontal velocity equal to the speed --> move to right
		velocity.x += speed;
	//Check if the player pressed D
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		//Set the horizontal velocity equal to negative speed --> move to left
		velocity.x += -speed;

	//Checking if the player hit the Space button, and if the player is able to jump (canJump boolean)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump) {
		//Setting canJump to false
		canJump = false;
		//Set the vertical velocity to -jumpHeight --> move upwards
		velocity.y = -jumpHeight;
	}
	//Check if the player collided with the island
	else if (CheckCollision(island)) {
		//Calculating how far they overlap each other, and pushing the player back out of the island (negative velocity --> up)
		//The further they overlap, how harder the player gets pushed out
		velocity.y = -((island.getRadius() + (body.getSize().y / 2) - 10.0f) - (sqrt(pow(body.getPosition().x - island.getPosition().x, 2) + pow(body.getPosition().y - island.getPosition().y, 2)))) * 10.0f;
		//Set canJump to true, because the player hit the ground (the island)
		canJump = true;
	}
	//If the player is not touching the island
	else
		//Apply gravity to pull the player down
		velocity.y += GRAVITY * deltaTime;

	//If the player did not move horizontally
	if (velocity.x == 0) {
		//Setting the row to 0 (idle animation)
		row = 0;
		//Row 0 contains 8 sprites, so we set the amount of columns to 8
		columns = 8;
	}
	//If the player moved to the left
	else if (velocity.x < 0) {
		//Set the row to 2 (walking animation)
		row = 2;
		//Row 0 contains 6 sprites, so we set the amount of columns to 6
		columns = 6;
		//Setting facing right to false
		facingRight = false;
	}
	//If the played moved to the left
	else {
		//Set the row to 2 (walking animation)
		row = 2;
		//Row 0 contains 6 sprites, so we set the amount of columns to 6
		columns = 6;
		//Setting facing right to true
		facingRight = true;
	}

	//Moving the player by the total velocity, multiplied by deltaTime to create the same effect on every computer
	body.move(velocity * deltaTime);

	//Check if the body X position is bigger than 875 (end of the island)
	if (body.getPosition().x > 875)
		//Set it back to 875 , so the player can't leave the island
		body.setPosition(875, body.getPosition().y);
	//Check if the body X position is smaller than 125 (end of the island)
	else if (body.getPosition().x < 125)
		//Set it back to 125 , so the player can't leave the island
		body.setPosition(125, body.getPosition().y);
	
	//Updating the animation
	animation.Update(deltaTime, row, columns, facingRight, isDead);

}
