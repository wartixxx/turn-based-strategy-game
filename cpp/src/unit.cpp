#include "unit.hpp"
#include "field.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace tbs 
{

Unit::Unit(int maxHealth, int attackDamage, double attackRange, int posX, int posY, Field* field, Side side)
    : m_health{ maxHealth }
    , m_maxHealth{ maxHealth }
    , m_attackDamage{ attackDamage }
    , m_attackRange{ attackRange }
    , m_posX{ posX }
    , m_posY{ posY }
    , m_field{ field }
    , m_side{ side }
{
    if (maxHealth <= 0)
        throw std::invalid_argument("max health must be positive");
    if (attackDamage < 0)
        throw std::invalid_argument("attack damage must be non-negative");
    if (attackRange <= 0.0)
        throw std::invalid_argument("attack range must be positive");
    if (field == nullptr)
        throw std::invalid_argument("field must not be null");
    if (!field->IsInside(posX, posY))
        throw std::invalid_argument("position is outside the field");
}

Unit::~Unit()
{
    std::cout << "Unit уничтожается\n";
}

bool Unit::IsAlive() const
{
    return m_health > 0;
}

void Unit::Heal(int amount)
{
    if (amount < 0)
        throw std::invalid_argument("amount must be non-negative");
    m_health = std::min(m_health + amount, m_maxHealth);
}

void Unit::TakeDamage(int damage)
{
    if (damage < 0)
        throw std::invalid_argument("damage must be non-negative");
    m_health = std::max(m_health - damage, 0);
}

bool Unit::MoveTo(int x, int y)
{
    if (!m_field->IsInside(x, y))
        return false;
    m_posX = x;
    m_posY = y;
    return true;
}

bool Unit::IsInRange(int x, int y) const
{
    return m_field->Distance(m_posX, m_posY, x, y) <= m_attackRange;
}

bool Unit::IsEnemy(const Unit &other) const
{
    return m_side != other.m_side;
}


int Unit::GetHealth() const
{
    return m_health;
}

int Unit::GetMaxHealth() const
{
    return m_maxHealth;
}

int Unit::GetAttackDamage() const
{
    return m_attackDamage;
}

double Unit::GetAttackRange() const
{
    return m_attackRange;
}

int Unit::GetPosX() const
{
    return m_posX;
}

int Unit::GetPosY() const
{
    return m_posY;
}

Side Unit::GetSide() const
{
    return m_side;
}

}





