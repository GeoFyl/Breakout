#pragma once
#include "PowerupBase.h"
#include "BallManager.h"

class PowerupMultiBalls : public PowerupBase
{
public:
    PowerupMultiBalls(sf::RenderWindow* window, Paddle* paddle, Ball* ball, BallManager* ballManager);
    ~PowerupMultiBalls();

    std::pair<POWERUPS, float> applyEffect() override; // Method to apply the power-up effect

private:
    BallManager* _ballManager;
};

