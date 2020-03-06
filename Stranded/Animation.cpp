#include "Animation.h"

//Constructor
Animation::Animation(sf::RectangleShape& character, sf::Texture& texture, sf::Vector2i& imageCount, float switchTime)
	:character(character), texture(texture)
{
	//Setting the switchtime to the given switchtime float
	this->switchTime = switchTime;
	//Setting the current time and current image to 0
	currentTime = 0.0f;
	currentImage = 0; 
	//Calculating the width and height of each sprite, by dividing the size of the total texture by the amount of sprites in the texture
	uvRect.width = texture.getSize().x / imageCount.x;
	uvRect.height = texture.getSize().y / imageCount.y;
	//Setting the character's texture rect to the calculated rect
	character.setTextureRect(uvRect);
}

//Updates the part of the sprite sheet that is displayed (to create walking animations , ...)
void Animation::Update(float deltaTime, int row, int columns, bool facingRight, bool isDead) {

	//Calculating the Y value from where the rect starts, based on the given row and the height of each sprite
	uvRect.top = row * uvRect.height;

	//Increasing currentTime by deltaTime
	currentTime += deltaTime;
	//If the current time is bigger than the switch time
	if (currentTime >= switchTime) {
		//Substract the switchtime from the current time
		currentTime -= switchTime;
		//Go to the next image in the row 
		currentImage++;
	}

	//If the character is not dead
	if (!isDead) {
		//Check if the character is facing to the right or left
		if (facingRight) {
			//If the rect is further than the last image in the sprite sheet, setting the rect back to the first image in the row
			if (uvRect.left >= abs(uvRect.width) * columns) {
				currentImage = 0;
			}
			//Setting the width to a positive number, because we want the texture to display from the left to the right side (so the character faces to the right)
			uvRect.width = abs(uvRect.width);
			//Calculating the X value from where the rect starts
			uvRect.left = currentImage * uvRect.width;
		}
		else {
			//If the rect is further than the last image in the sprite sheet, setting the rect back to the first image in the row
			if (uvRect.left > abs(uvRect.width)* columns) {
				currentImage = 0;
			}
			//Setting the width to a negative number, because we want the texture to display from the right to the left side(so the character faces to the left)
			uvRect.width = -abs(uvRect.width);
			//Calculating the X value from where the rect starts
			uvRect.left = (currentImage + 1) * abs(uvRect.width);
		}
	}
	else
		//If the character is dead, doing a death animation
		DeathAnimation(deltaTime, row, facingRight);

	//Set the texture rect of the character to the new rect
	character.setTextureRect(uvRect);
}

//The animation that will play when the character dies
void Animation::DeathAnimation(float deltaTime, int row, bool facingRight) {
	//Calculating the Y value from where the rect starts
	uvRect.top = row * uvRect.height;
	//Increasing currentTime by deltaTime
	currentTime += deltaTime;
	//If the currenttime is bigger than the switch time
	if (currentTime >= switchTime) {
		//Substracting the switch time from the current time
		currentTime -= switchTime;
		//Going to the next image in the row
		currentImage++;
	}

	//If the character is facing to the right
	if (facingRight) {
		//Setting the width to a positive number, because we want the texture to display from the left to the right side (so the character faces to the right)
		uvRect.width = abs(uvRect.width);
		//Calculating the X value from where the rect starts
		uvRect.left = currentImage * uvRect.width;
	}
	//If the character is facing to the left
	else {
		//Setting the width to a negative number, because we want the texture to display from the right to the left side(so the character faces to the left)
		uvRect.width = -abs(uvRect.width);
		//Calculating the X value from where the rect starts
		uvRect.left = (currentImage + 1) * abs(uvRect.width);
	}
}