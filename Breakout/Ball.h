#pragma once
#include <SFML/Graphics.hpp>


class GameManager;  // forward declaration
class BallManager;


class Ball {
public:
    Ball(sf::RenderWindow* window, float velocity, GameManager* gameManager, BallManager* ballManager);
    ~Ball();
    void update(float dt);
    void render();
    void setVelocity(float coeff, float duration);
    void resetVelocity(float velocity, float direction_x, float direction_y);
    void setFireBall(float duration);
    void setPosition(float x, float y);

    inline float getVelocity() { return _velocity; }
    inline const sf::Vector2f& getDirection() { return _direction; }
    void setExtra(bool value);

    void setAlive(bool val) { _isAlive = val; }
    bool getAlive() { return _isAlive; }
private:
    sf::CircleShape _sprite;
    sf::Vector2f _direction;
    sf::RenderWindow* _window;
    float _velocity;
    bool _isAlive;
    bool _isFireBall;
    bool _isExtra = true;
    float _timeWithPowerupEffect;

    GameManager* _gameManager;  // Reference to the GameManager
    BallManager* _ballManager;

    static constexpr float RADIUS = 10.0f;      
    static constexpr float VELOCITY = 350.0f;   // for reference.
};

