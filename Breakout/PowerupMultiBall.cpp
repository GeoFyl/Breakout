#include "PowerupMultiBall.h"

PowerupMultiBall::PowerupMultiBall(sf::RenderWindow* window, Paddle* paddle, Ball* ball, BallManager* ballManager)
	: PowerupBase(window, paddle, ball), _ballManager(ballManager)
{
	_sprite.setFillColor(sf::Color(250, 125, 0));
}

PowerupMultiBall::~PowerupMultiBall()
{
}

std::pair<POWERUPS, float> PowerupMultiBall::applyEffect()
{
	_ballManager->ExtraBallsActive();
	return { extraBalls, 5 };
}
