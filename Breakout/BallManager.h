#pragma once
#include "Ball.h"
#include <list>

class BallManager
{
public:
	BallManager(sf::RenderWindow* window, float velocity, GameManager* gameManager);

	void Update(float dt);
	void Render();

	void ExtraBallsActive();
	//void SetExtraBallInactive(Ball* ball);

	Ball* GetPlayerBall() { return _playerBall; }

private:
	Ball* _playerBall;
	std::list<Ball*> _extraBallsActive;
	std::list<Ball*> _extraBallsDead;
};

