#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <ctime>
#include "Player.h"
#include "Skeleton.h"
#include "Menu.h"
#include "Cloud.h"
#include "Text.h"

int TotalScoreNeeded(int currentWave);
sf::Sprite NewSprite(sf::Texture &texture,  sf::Color fillColor, sf::Vector2f origin,  sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f));
bool HitDetection(sf::RenderWindow &window, sf::Vector2f mouseLocation, Player &character, Skeleton* skeleton);
void CloseGame(const int skeletonAmount, Skeleton**& skeletons, sf::RenderWindow& window);