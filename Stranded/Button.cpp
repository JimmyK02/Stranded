#include "Button.h"

//Constructor
Button::Button(sf::Vector2f size, sf::Vector2f position, std::string text, sf::Font &font, unsigned int charSize, sf::Color idleColor, sf::Color hoverColor, sf::Color clickColor) 
	:font (font)
{
	//Setting the button state to idle
	this->buttonState = BTN_IDLE;

	//Setting the size, position and origin of the button
	this->buttonShape.setSize(size);
	this->buttonShape.setPosition(position);
	this->buttonShape.setOrigin(buttonShape.getSize().x / 2, buttonShape.getSize().y / 2);

	//Setting the font, string, color, character size and position of the text
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(charSize);
	this->text.setPosition(
	    this->buttonShape.getPosition().x  - this->text.getGlobalBounds().width / 2.0f,
		this->buttonShape.getPosition().y  - this->text.getGlobalBounds().height / 2.0f
	);

	//Setting the idle color, hover color and click color of the button
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->clickColor = clickColor;

	//Setting the current color of the button to idle color
	this->buttonShape.setFillColor(this->idleColor);
}

//Checks if the player hovers/clicks on the button and setting the color of the button
void Button::update(sf::Vector2f mousePos) {

	//Setting the state to idle by default
	this->buttonState = BTN_IDLE;
	//If the mouse is within the global bounds of the button
	if (this->buttonShape.getGlobalBounds().contains(mousePos)) {
		//Setting the state to hover
		this->buttonState = BTN_HOVER;
		//If the player is also pressing the left mouse button
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//Setting the state to pressed
			this->buttonState = BTN_PRESSED;
		}
	}

	//Checking in which state the button is, and setting the appropriate color
	switch (this->buttonState) {
	case BTN_IDLE:
		this->buttonShape.setFillColor(this->idleColor);
		break;
	case BTN_HOVER:
		this->buttonShape.setFillColor(this->hoverColor);
		break;
	case BTN_PRESSED:
		this->buttonShape.setFillColor(this->clickColor);
		break;
	}
}

void Button::render(sf::RenderWindow& target) {
	//Drawing the button and text to the window
	target.draw(this->buttonShape);
	target.draw(this->text);
}

bool Button::IsPressed() {
	//Check if the button is pressed, and return true is it is. Else , it returns false.
	if (this->buttonState == BTN_PRESSED)
		return true;
	return false;
}

std::string Button::GetText() {
	//Returns the text of the button
	std::string textString = this->text.getString();
	return textString;
}