#include "Skeleton.h"

//This class is inherited from the Character class

Skeleton::Skeleton(sf::Texture& texture, sf::Vector2i imageCount, float switchTime, Character* p, sf::CircleShape& island, const char* deathSoundLocation, float volume, sf::Vector2f size, sf::Vector2f position ,float speed )
	:Character(texture, imageCount, switchTime, island, deathSoundLocation, volume, size, position, speed), character(p)
{
}

void Skeleton::GetCorners() {
	//Getting the corners of the Skeleton. I added/subtracted some values to exclude the empty pixels of the image.
	bottom = body.getPosition().y + (body.getSize().y/2) - (3 * (body.getSize().y / (texture.getSize().y / imageCount.y)));
	top = body.getPosition().y - (body.getSize().y / 2) + (20 * (body.getSize().y / (texture.getSize().y / imageCount.y)));
	left = body.getPosition().x - (body.getSize().x / 2) + (22 * (body.getSize().x / (texture.getSize().x / imageCount.x)));
	right = body.getPosition().x + (body.getSize().x /2) - (24 * (body.getSize().x / (texture.getSize().x / imageCount.x)));
}

//Updating the position of the skeleton (and updating the animation)
void Skeleton::Update(float deltaTime) {

	//Setting the row to 1 (walking animation) and the columns to 4 (amount of sprites in row 1) by default
	int row = 1, columns = 4; 

	//If the skeleton is not dead
	if (!isDead) {
		//If the player is on the right, move to the right (towards the player)
		if (character->GetPosition().x > body.getPosition().x) {
			velocity.x = speed;
		}
		//If the player is on the left, move to the left (towards the player)
		else if (character->GetPosition().x < body.getPosition().x) {
			velocity.x = -speed;
		}

		//If the skeleton is inside the island
		if (CheckCollision(island))
			//Push the skeleton up
			velocity.y = -((island.getRadius() + (body.getSize().y / 2) - 10.0f) - (sqrt(pow(body.getPosition().x - island.getPosition().x, 2) + pow(body.getPosition().y - island.getPosition().y, 2)))) * 10.0f;
		//If the skeleton is at the bottom of the screen (when walking inside the water), set the vertical velocity to 0
		else if (body.getPosition().y >= (600 + (body.getSize().x / 2)))
			velocity.y = 0;
		//If the skeleton is not colliding with the island and is not at the bottom of the screen, applying gravity
		else
			velocity.y += deltaTime * GRAVITY;

		//If the skeleton is moving to the left
		if (velocity.x < 0) {
			//Set the facingRight boolean to false
			facingRight = false;
		}
		//If the skeleton is moving to the right
		else {
			//Set the facingRight bool to true
			facingRight = true;
		}

		//Move the skeleton body and multiplying it by deltaTime, so we get the same result on different computers
		body.move(velocity * deltaTime);
	}
	else {
		//If the skeleton is dead, set the row to 3 (dead animation) and set columns to 7 (because row 3 contains 7 sprites)
		row = 3;
		columns = 7;
	}

	//Update the animation of the skeleton
	animation.Update(deltaTime, row, columns, facingRight, isDead);
}

//Used to create a 'new' skeleton (new size, new position and new speed)
void Skeleton::ResetStats() {
	//Getting a new random size between 75 and 150
	float newSize = float(rand() % 75 + 75);

	//Getting a new random speed between 40 and 120
	float newSpeed = float(rand() % 80 + 40);

	float newxPosition;

	//There is 50% chance it will return true --> around 50% will come from left side and around 50% from right side
	if ((int)newSize % 2 == 0) {
		//Getting a new X position between 1250 and 1750 (skeleton comes from right side)
		newxPosition = float(rand() % 500 + 1250);
	}
	else {
		//Getting a new X position between -750 and -250 (skeleton comes from left side)
		newxPosition = float(rand() % 500 - 750);
	}

	//Updating the skeleton's stats (new size, new position and new speed)
	this->body.setSize(sf::Vector2f(newSize, newSize));
	this->body.setOrigin(body.getSize().x / 2, body.getSize().y / 2); //Setting the origin back to the center of the skeleton
	this->SetPosition(sf::Vector2f(newxPosition, 600));
	this->speed = newSpeed;

	/*Since we are reusing the same skeletons , which probably have already been killed in previous waves,
	we need to reset the isDead boolean of the skeletons to false */
	this->isDead = false;

}