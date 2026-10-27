#include "Brick.h"

Brick::Brick(float x, float y, float width, float height, int points, int health)
    : _isDestroyed(false), _pointValue(points), _health(health)
{
    _shape.setPosition(x, y);
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(sf::Color::Red);
}

void Brick::render(sf::RenderWindow& window)
{
    if (!_isDestroyed) {
        window.draw(_shape);
    }
}

bool Brick::getDestroyed() {
    return _isDestroyed;
}

void Brick::takeDamage(int damage) {
    _health -= damage;
    if (_health <= 0) {
        _isDestroyed = true;
    }
}

int Brick::getHealth() {
    return _health;
}

sf::FloatRect Brick::getBounds() const
{
    return _shape.getGlobalBounds();
}

int Brick::getPoints() { return _pointValue; };
