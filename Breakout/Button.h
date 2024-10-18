#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:
    Button(float x, float y, std::string text, int fontSize, sf::Color backgroundColour, sf::Color textColour, sf::Font* font, sf::WindowBase* window);
    void update();
    void render(sf::RenderWindow& window);
    void setOnClick(std::function<void()> onClick) { _onClick = onClick; }
    void setText(std::string text);
    void setVisible(bool val) { _shown = val; }
private:
    sf::RectangleShape _shape;
    std::function<void()> _onClick; // callback for when clicked.
    sf::Text _text;
    sf::WindowBase* _window;

    sf::Color _hoveredColour;
    sf::Color _unhoveredColour;

    bool _clicked = false;
    bool _shown = false;
    bool _colourSetToHovered = false;

};

