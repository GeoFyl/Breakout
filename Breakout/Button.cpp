#include "Button.h"
#include <iostream>

Button::Button(float x, float y, std::string text, int fontSize, sf::Color backgroundColour, sf::Color textColour, sf::Font* font, sf::WindowBase* window) :
    _window(window)
{
    _text.setFont(*font);
    _text.setPosition(x,y);
    _text.setCharacterSize(fontSize);
    _text.setFillColor(textColour);
    _text.setString(text);

    // box fits around the text
    _shape.setPosition(_text.getGlobalBounds().getPosition() - _text.getGlobalBounds().getSize() * 0.05f);
    _shape.setSize(_text.getGlobalBounds().getSize() * 1.1f);
    _shape.setFillColor(backgroundColour);
}

void Button::update()
{
    // if visible and not clicked yet and mouse down and mouse over button 
    if (_shown && !_clicked && sf::Mouse::isButtonPressed(sf::Mouse::Left) && _shape.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*_window))) {
        _clicked = true;
        _onClick();
    }

    // Check if clicked in general. prevents clicking off the button then holding and dragging over from counting as clicking on the button
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        _clicked = true;
    }
    else {
        _clicked = false;
    }
}

void Button::render(sf::RenderWindow& window)
{
    // render only when visible
    if (_shown) { 
        window.draw(_shape);
        window.draw(_text);
    }
}

void Button::setText(std::string text)
{
    _text.setString(text);
}
