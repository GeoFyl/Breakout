#include "GameManager.h"
#include "Ball.h"
#include "PowerupManager.h"
#include <iostream>

GameManager::GameManager(sf::RenderWindow* window)
    : _window(window), _paddle(nullptr), _ball(nullptr), _brickManager(nullptr), _powerupManager(nullptr),
    _messagingSystem(nullptr), _ui(nullptr), _pause(false), _time(0.f), _lives(3), _pauseHold(0.f), _levelComplete(false),
    _powerupInEffect({ none,0.f }), _timeLastPowerupSpawned(0.f)
{
    _font.loadFromFile("font/montS.ttf");
    _masterText.setFont(_font);
    _masterText.setPosition(50, 400);
    _masterText.setCharacterSize(48);
    _masterText.setFillColor(sf::Color::Yellow);
}

void GameManager::initialize()
{
    _paddle = new Paddle(_window);
    _brickManager = new BrickManager(_window, this);
    _messagingSystem = new MessagingSystem(_window);
    _ball = new Ball(_window, 400.0f, this); 
    _powerupManager = new PowerupManager(_window, _paddle, _ball);
    _ui = new UI(_window, _lives, this);

    // Create bricks
    _brickManager->createBricks(5, 10, 80.0f, 30.0f, 5.0f);

    // Create buttons
    sf::Vector2 screenSize = _window->getSize();
    Button* replay_button = _ui->addButton(screenSize.x / 2, screenSize.y / 2, 48, sf::Color::White, sf::Color::Black, "Replay", "ReplayButton"); // Replay button
    replay_button->setOnClick([&] {restart(); }); // Sets restart as the callback function to be called by the replay button
}

void GameManager::update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) exit(0);

    _powerupInEffect = _powerupManager->getPowerupInEffect();
    _ui->updatePowerupText(_powerupInEffect);
    _ui->updateButtons();
    _powerupInEffect.second -= dt;

    // pause and pause handling
    if (_pauseHold > 0.f) _pauseHold -= dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        if (!_pause && _pauseHold <= 0.f)
        {
            _pause = true;
            _masterText.setString("paused.");
            _pauseHold = PAUSE_TIME_BUFFER;
        }
        if (_pause && _pauseHold <= 0.f)
        {
            _pause = false;
            _masterText.setString("");
            _pauseHold = PAUSE_TIME_BUFFER;
        }
    }

    if (_pause)
    {
        // Show the replay button
        _ui->getButton("ReplayButton")->setVisible(true);
        return;
    }
    else if (_lives <= 0)
    {
        _masterText.setString("Game over.");
        // Show the replay button
        _ui->getButton("ReplayButton")->setVisible(true);
        return;
    }
    else if (_levelComplete)
    {
        _masterText.setString("Level completed.");
        // Show the replay button
        _ui->getButton("ReplayButton")->setVisible(true);
        return;
    }
    else _ui->getButton("ReplayButton")->setVisible(false); // Hide the replay button

    // timer.
    _time += dt;


    if (_time > _timeLastPowerupSpawned + POWERUP_FREQUENCY && rand()%700 == 0)      // TODO parameterise
    {
        _powerupManager->spawnPowerup();
        _timeLastPowerupSpawned = _time;
    }

    // move paddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _paddle->moveRight(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _paddle->moveLeft(dt);

    // update everything 
    _paddle->update(dt);
    _ball->update(dt);
    _powerupManager->update(dt);
}

void GameManager::loseLife()
{
    _lives--;
    _ui->lifeLost(_lives);

    // TODO screen shake.
}

void GameManager::render()
{
    _paddle->render();
    _ball->render();
    _brickManager->render();
    _powerupManager->render();
    _window->draw(_masterText);
    _ui->render();
}

void GameManager::levelComplete()
{
    _levelComplete = true;
}

// restart the game. called by replay button
void GameManager::restart()
{
    _levelComplete = false;
    _pause = false;
    _lives = 3;
    _masterText.setString("");
    _ball->setPosition(0, 300);
    _ball->resetVelocity(400, 1, 1);
    _ui->resetLife();
    _brickManager->resetBricks();
}

sf::RenderWindow* GameManager::getWindow() const { return _window; }
UI* GameManager::getUI() const { return _ui; }
Paddle* GameManager::getPaddle() const { return _paddle; }
BrickManager* GameManager::getBrickManager() const { return _brickManager; }
PowerupManager* GameManager::getPowerupManager() const { return _powerupManager; }
