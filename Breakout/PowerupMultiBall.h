#pragma once
#include "PowerupBase.h"
#include "BallManager.h"

class PowerupMultiBall :  public PowerupBase
{
public:
    PowerupMultiBall(sf::RenderWindow* window, Paddle* paddle, Ball* ball, BallManager* ballManager);
    ~PowerupMultiBall();

    std::pair<POWERUPS, float> applyEffect() override; // Method to apply the power-up effect

private:
    BallManager* _ballManager;
};

