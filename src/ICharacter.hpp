#pragma once

#include <SFML/Graphics.hpp>

enum class Action
{
    NONE,
    WALKING,
    ATTACKING,
    DYING
};

class ICharacter
{
public:
    virtual void setAction(Action l_action) = 0;
    virtual Action getAction() = 0;
    virtual sf::Vector2f getPosition() = 0;
    virtual int getHealth() = 0;
    virtual void changeHealth(int l_value) = 0;

    virtual void attack(ICharacter* l_enemy) = 0;
    virtual bool canAttack() = 0;

    virtual void update() = 0;
    virtual void render(sf::RenderWindow& l_window) = 0;
};
