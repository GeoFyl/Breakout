#include "BallManager.h"

BallManager::BallManager(sf::RenderWindow* window, float velocity, GameManager* gameManager)
{
	_playerBall = new Ball(window, velocity, gameManager, this);

	for (int i = 0; i < 9; i++) {
		_extraBallsDead.push_back(new Ball(*_playerBall));
	}

	_playerBall->setExtra(false);
}

void BallManager::Update(float dt)
{
	_playerBall->update(dt);

	if (!_extraBallsActive.empty()) {
		for (auto it = _extraBallsActive.begin(); it != _extraBallsActive.end();) {
			while (it != _extraBallsActive.end() && !(*it)->getAlive()) {
				_extraBallsDead.push_back(*it);
				it = _extraBallsActive.erase(it);
			}
			if (it != _extraBallsActive.end()) {
				(*it)->update(dt);
				it++;
			}
		}
	}
}

void BallManager::Render()
{
	_playerBall->render();

	if (!_extraBallsActive.empty()) {
		for (Ball* ball : _extraBallsActive) {
			ball->render();
		}
	}
}

void BallManager::ExtraBallsActive()
{
	sf::Vector2f dir = { 1,1 };

	float i = 0;

	while (!_extraBallsDead.empty()) {
		Ball* ball = _extraBallsDead.front();
		ball->setAlive(true);
		ball->resetVelocity(400, dir.x + i, dir.y + i);
		_extraBallsActive.push_back(ball);
		_extraBallsDead.pop_front();
		i+= 0.2f;
	}
}
