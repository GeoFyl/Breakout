#include "BallManager.h"
#include "CONSTANTS.h"

BallManager::BallManager(sf::RenderWindow* window, float velocity, GameManager* gameManager)
{
	_playerBall = new Ball(window, velocity, gameManager);

	for (int i = 0; i < EXTRA_BALLS; i++) {
		_extraBallsDead.push_back(new Ball(*_playerBall));
	}

	_playerBall->setExtra(false);
}

void BallManager::Update(float dt)
{
	_playerBall->update(dt);

	if (!_extraBallsAlive.empty()) {
		for (auto it = _extraBallsAlive.begin(); it != _extraBallsAlive.end();) {
			while (it != _extraBallsAlive.end() && !(*it)->getAlive()) {
				_extraBallsDead.push_back(*it);
				it = _extraBallsAlive.erase(it);
			}
			if (it != _extraBallsAlive.end()) {
				(*it)->update(dt);
				it++;
			}
		}
	}
}

void BallManager::Render()
{
	_playerBall->render();

	if (!_extraBallsAlive.empty()) {
		for (Ball* ball : _extraBallsAlive) {
			ball->render();
		}
	}
}

void BallManager::SpawnExtraBalls()
{
	sf::Vector2f dir = { 1,1 };
	float i = 0;

	while (!_extraBallsDead.empty()) {
		Ball* ball = _extraBallsDead.front();
		ball->setAlive(true);
		ball->resetVelocity(400, dir.x + i, dir.y + i);
		_extraBallsAlive.push_back(ball);
		_extraBallsDead.pop_front();
		i += 0.2f;
	}
}
