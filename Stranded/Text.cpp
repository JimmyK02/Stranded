#include "Text.h"

Text::Text(std::string text, int& score, sf::Font& font, int fontSize, sf::Color fillColor, float outlineThickness, sf::Color outlineColor)
	:score(score)
{
	//Convert the score int to a string
	std::string scoreString = std::to_string(score);
	//Set the basic text(for example "Score: ") 
	this->basicText = text;
	//Creating a string that contains the total text(for example "Score: 0")
	std::string totalString = this->basicText + scoreString;
	//Setting the totalText string, font, character size, color, outline thickness and outline color
	this->totalText.setString(totalString);
	this->totalText.setFont(font);
	this->totalText.setCharacterSize(fontSize);
	this->totalText.setFillColor(fillColor);
	this->totalText.setOutlineThickness(outlineThickness);
	this->totalText.setOutlineColor(outlineColor);
}

//Used to update the text and to change the position and character size of the text
void Text::Update(sf::Vector2f position, int newFontSize) {
	//Converting the score int to a string
	std::string scoreText = std::to_string(this->score);
	//Updating the total text string, character size and position
	this->totalText.setString(this->basicText + scoreText);
	this->totalText.setCharacterSize(newFontSize);
	this->totalText.setPosition(position);
}

void Text::Draw(sf::RenderWindow &window) {
	//Drawing the text to the screen
	window.draw(this->totalText);
}

sf::FloatRect Text::GetSize() {
	//Get the size of the text
	return this->totalText.getGlobalBounds();
}

void Text::SetOrigin(sf::Vector2f origin) {
	//Set the origin of the text
	this->totalText.setOrigin(origin);
}