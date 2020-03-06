#include "Menu.h"

Menu::Menu(bool inMenu) {
	//Setting the InMenu boolean to the argument that has been passed
	this->inMenu = inMenu;
	//Setting the click delay to 0.5 seconds, to prevent the player from accidentely clicked a button instantly
	clickDelay = 0.5f;
	//Creating a fading effect, and setting it's size equal to the screen size
	this->fadingEffect.setSize(sf::Vector2f(1000, 600));
	//Setting the alpha to 240, which will be used for the fading effect
	this->fadingAlpha = 240;
	//Setting the color and alpha value of the fading effect
	this->fadingEffect.setFillColor(sf::Color(0, 0, 0, (unsigned int)fadingAlpha));

	//Loading the sound that plays when you click a button
	this->clickSoundBuffer.loadFromFile("Audio/clickSound.wav");
	this->clickSound.setBuffer(this->clickSoundBuffer);
}

void Menu::CreateButton(sf::Vector2f size, sf::Vector2f position, std::string text, sf::Font& font, unsigned int charSize, sf::Color idleColor, sf::Color hoverColor, sf::Color clickColor) {
	//Creating a new button and storing it in a vector
	Button button(size, position, text, font,charSize,  idleColor, hoverColor, clickColor);
	this->buttons.push_back(button);
}

void Menu::CreateText( sf::Vector2f position, std::string textString, sf::Font& font, sf::Color color, unsigned int charSize) {
	//Creating a new text, setting it's string, font, character size, position and color
	sf::Text text;
	text.setString(textString);
	text.setFont(font);
	text.setCharacterSize(charSize);
	text.setPosition(sf::Vector2f(position.x - (text.getGlobalBounds().width / 2.0f), position.y - (text.getGlobalBounds().height / 2.0f)));
	text.setFillColor(color);
	//Storing the text in a vector
	this->textVector.push_back(text);
}

void Menu::CreateSprite(sf::Texture& texture, sf::Vector2f position, sf::Color fillColor, sf::Vector2f scale) {
	//Creating a new sprite, and setting it's texture, color, scale, origin and position
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setColor(fillColor);
	sprite.setScale(scale);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position);
	//Storing the sprite in a vector
	sprites.push_back(sprite);
}

void Menu::CreateSound(sf::SoundBuffer &buffer) {
	//Creating a new sound and storing it in a vector
	sf::Sound sound;
	sound.setBuffer(buffer);
	sounds.push_back(sound);
}

void Menu::CreateRect(sf::Vector2f size, sf::Vector2f position, sf::Color fillColor) {
	//Creating a new rectangle, and setting it's size, position, color, and origin
	sf::RectangleShape rect;
	rect.setSize(size);
	rect.setPosition(position);
	rect.setFillColor(fillColor);
	rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
	//Storing the rectangle in a vector
	rects.push_back(rect);
}

bool Menu::IsInMenu() {
	//Returns true if the menu is opened, and false if the menu is not opened
	return this->inMenu;
}

void Menu::InMenu(bool inMenu) {
	//Used to open and close the menu
	this->inMenu = inMenu;
	//Setting the click delay to 0.5 seconds
	clickDelay = 0.5f;
	//Setting the alpha back to 240
	fadingAlpha = 240;
	//If the menu was opened, play the sounds that have been created using CreateSound function
	if (inMenu == true)
		for (unsigned int i = 0; i < sounds.size(); i++)
			sounds[i].play();
}

//Checks if the player clicked on a button, and takes care of the fading effect and click delay
void Menu::update(sf::Vector2f mousePos, float deltaTime) {
	//Updating the buttons: check if the player clicked on them
	for (unsigned int i = 0; i < this->buttons.size(); i++)
		this->buttons[i].update(mousePos);

	//If the clickdelay is bigger than 0 , decreasing it by deltaTime
	if (clickDelay > 0.0f) {
		clickDelay -= deltaTime;
	}

	//If the fadingalpha is bigger than 0, decreasing it by deltaTime multiplied by 150
	if (fadingAlpha > 0)
		fadingAlpha -= (150 * deltaTime);
	if (fadingAlpha < 0)
		fadingAlpha = 0;
	//Setting the color and alpha value of the fading effect
	fadingEffect.setFillColor(sf::Color(0, 0, 0, (unsigned int)fadingAlpha));
}

//Drawing everything to the screen
void Menu::render(sf::RenderWindow& target) {	
	//Drawing all created rects to the screen
	for (unsigned int i = 0; i < this->rects.size(); i++)
		target.draw(rects[i]);
	//Drawing all created buttons to the screen
	for (unsigned int i = 0; i < this->buttons.size(); i++)
		this->buttons[i].render(target);
	//Drawing all created sprites to the screen
	for (unsigned int i = 0; i < this->sprites.size(); i++)
		target.draw(sprites[i]);
	//Drawing all created texts to the screen
	for (unsigned int i = 0; i < this->textVector.size(); i++)
		target.draw(textVector[i]);

	//Drawing the fading effect to the screen
	target.draw(fadingEffect);

}

bool Menu::IsButtonPressed() {
	//Checking all buttons in the buttons vector
	for (unsigned int i = 0; i < buttons.size(); i++) {
		//If a button is pressed and the click delay is 0
		if (buttons[i].IsPressed() && clickDelay <= 0.0f) {
			//Setting the pressed button's name to the text of the button that has been clicked
			this->pressedButtonName = buttons[i].GetText();
			//Playing the click sound
			this->clickSound.play();
			//Returning true if a button has been clicked, else returning false
			return true;
		}
	}
	return false;
}

std::string Menu::GetPressedButton() {
	//Get the name of the button that has been pressed
	return this->pressedButtonName;
}
