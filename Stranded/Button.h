#pragma once
#include <SFML/Graphics.hpp>
#include <string>

enum button_state {BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button
{

public:
	Button(sf::Vector2f size, sf::Vector2f position, std::string text, sf::Font &font, unsigned int charSize, sf::Color idleColor, sf::Color hoverColor, sf::Color clickColor);
	void render(sf::RenderWindow& target);
	void update(sf::Vector2f mousePos);

	//Accessors
	bool IsPressed();
	std::string GetText();

private:
	unsigned short buttonState;

	sf::RectangleShape buttonShape;
	sf::Text text;
	sf::Font &font;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color clickColor;

};

