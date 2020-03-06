#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Text
{

public:
	Text(std::string text, int &score, sf::Font &font, int fontSize, sf::Color fillColor, float outlineThickness = 0.0f, sf::Color outlineColor = sf::Color::Black);
	void Update(sf::Vector2f position, int newFontSize);
	void Draw(sf::RenderWindow& window);
	void SetOrigin(sf::Vector2f origin);

	//Accessors
	sf::FloatRect GetSize();

private:
	sf::String basicText;
	int& score;
	sf::Text totalText;
};

