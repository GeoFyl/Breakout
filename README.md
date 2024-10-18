# Breakout

W Kavanagh. June Summer 2024

## controls

A/D to move the paddle right and left.
P to pause.

## Powerups

big/small paddle (blue)
fast/slow ball (fancy yellow)
fire ball (green)

# Tasklist

## Suggested fixes

* Fix the compiler issues in the code

## Suggested tasks

* Implement mouse input for pad
* Improved VFX (ball trail, paddle hit response, brick particle destruction)
* Better UI (progress bar rather than timer for countdown).
* GameLoop
* Better ball physics (Box2D)
* Leaderboards
* More ball types (e.g., multiball, sticky ball [where you shoot the ball from the paddle every time], tiny ball, big ball, brick-tracking ball)
* Sounds with increasing tone between bounces.
* Implement commentary with calls to an LLM such as LLama

# Time Details and Changelist
Took 3hrs 20m overall
* Fixed compiler error - 10 mins
* Added button class which takes a lambda as a callback for onClick - ~2hrs
* Added replay button to pause/win/lose screens and implemented funtionality to reset the game - ~40m
* Updated comments and added quit button to menu ~15m
* Improved button feedback by changing brightening/darkening the colour based on whether mouse is hovering over - ~15m
