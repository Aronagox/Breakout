#pragma once
#include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(float x, float y, float width, float height, int points);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    int getPoints();
private:
    sf::RectangleShape _shape;
    bool _isDestroyed;
    int _pointValue;
};