#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "Button.h"

class Menu
{

public:
	Menu(bool inMenu);
	
	void CreateButton(sf::Vector2f size, sf::Vector2f position, std::string text, sf::Font& font, unsigned int fontSize, sf::Color idleColor, sf::Color hoverColor, sf::Color clickColor);
	void CreateText(sf::Vector2f position, std::string textString, sf::Font& font, sf::Color color, unsigned int charSize);
	void CreateSprite(sf::Texture& texture, sf::Vector2f position, sf::Color fillColor, sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f));
	void CreateSound(sf::SoundBuffer& buffer);
	void CreateRect(sf::Vector2f size, sf::Vector2f position, sf::Color fillColor);

	void InMenu(bool inMenu);
	void update(sf::Vector2f mousePos, float deltaTime);
	void render(sf::RenderWindow& target);

	//Accessors
	bool IsButtonPressed();
	std::string GetPressedButton();
	bool IsInMenu();


private:
	sf::SoundBuffer clickSoundBuffer;
	sf::Sound clickSound;
	sf::RectangleShape fadingEffect;
	float fadingAlpha;
	std::string pressedButtonName;
	bool inMenu;
	std::vector<Button> buttons;
	std::vector<sf::Text> textVector;
	std::vector<sf::Sprite> sprites;
	std::vector<sf::Sound> sounds;
	std::vector<sf::RectangleShape> rects;
	float clickDelay;
};

