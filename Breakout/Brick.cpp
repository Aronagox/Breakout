#include "Brick.h"-


Brick::Brick(float x, float y, float width, float height, int points, int health)
    : _isDestroyed(false), _pointValue(points), _maxHealth(health)
{
    _currentHealth = _maxHealth;   
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

bool Brick::getDestroyed() {
    return _isDestroyed;
}

void Brick::takeDamage(int damage) {
    _currentHealth -= damage;
    if (_currentHealth <= 0) {
        _isDestroyed = true;
    }
    else {
        _shape.setFillColor(calculateColor());
    }
}

int Brick::getHealth() {
    return _currentHealth;
}

sf::FloatRect Brick::getBounds() const
{
    return _shape.getGlobalBounds();
}

int Brick::getPoints() { return _pointValue; };
