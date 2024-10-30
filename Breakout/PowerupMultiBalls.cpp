#include "PowerupMultiBalls.h"

PowerupMultiBalls::PowerupMultiBalls(sf::RenderWindow* window, Paddle* paddle, Ball* ball, BallManager* ballManager)
	: PowerupBase(window, paddle, ball), _ballManager(ballManager)
{
	_sprite.setFillColor(sf::Color::Blue);
}

PowerupMultiBalls::~PowerupMultiBalls()
{
}

std::pair<POWERUPS, float> PowerupMultiBalls::applyEffect()
{
	_ballManager->SpawnExtraBalls();
	return { extraBalls, 0 };
}
