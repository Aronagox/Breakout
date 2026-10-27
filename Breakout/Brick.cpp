#include "Brick.h"-
#include <iostream>

Brick::Brick(float x, float y, float width, float height, int points, int health)
    : _isDestroyed(false), _pointValue(points), _maxHealth(health)
{
    _currentHealth = _maxHealth;   
    _isColliding = false;

    _shape.setPosition(x, y);
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(calculateColor());
}

sf::Color Brick::calculateColor() {
    sf::Color newColor = { 255,0,0,255 };
    if (_currentHealth > 5) {
        newColor.r -= std::max(0.f, (255.f / 5) * float(_currentHealth - 5));
    }
    if (_currentHealth > 1) {
        newColor.b += std::max(255.f, (255.f / 5) * float(_currentHealth - 1));
    }
    return newColor;
}

void Brick::render(sf::RenderWindow& window)
{
    if (!_isDestroyed) {
        window.draw(_shape);
    }
}

void Brick::setColliding(bool colliding) {
    _isColliding = colliding;
}

void Brick::takeDamage(int damage) {
    _currentHealth -= damage;
    std::cout << "Hit " << _currentHealth << std::endl;
    if (_currentHealth <= 0) {
        _isDestroyed = true;
    }
    else {
        _shape.setFillColor(calculateColor());
    }
}

sf::FloatRect Brick::getBounds() const
{
    return _shape.getGlobalBounds();
}


bool Brick::getDestroyed() { return _isDestroyed; };
int Brick::getHealth() { return _currentHealth; };
int Brick::getPoints() { return _pointValue; };
bool Brick::getColliding() { return _isColliding; };