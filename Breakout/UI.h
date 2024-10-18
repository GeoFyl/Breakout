#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "CONSTANTS.h"
#include "PowerupManager.h"
#include "Button.h"

class GameManager;

class UI
{
public:
	UI(sf::RenderWindow* window, int lives, GameManager* gameManager);
	~UI();

	void updatePowerupText(std::pair<POWERUPS, float>);
	Button* addButton(float x, float y, int fontSize, sf::Color backgroundColour, sf::Color textColour, std::string text, std::string name);
	Button* getButton(std::string name);
	void updateButtons();
	void lifeLost(int lives);
	void resetLife();
	void render();

private:
	GameManager* _gameManager;
	
	sf::RenderWindow* _window;
	sf::Font _font;
	sf::Text _powerupText;

	std::vector<sf::CircleShape> _lives;
	std::unordered_map<std::string, Button*> _buttons;

	static constexpr float LIFE_RADIUS = 15.0f;
	static constexpr float LIFE_PADDING = 20.0f;
};

