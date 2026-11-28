#include "squad.hpp"

#include "field.hpp"
#include "unit.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include<algorithm>

namespace tbs 
{

Squad::Squad(Side side, Field* field)
    : m_side{ side }
    , m_field{ field }
{
    if (field == nullptr)
        throw std::invalid_argument("field must not be null");
}

Squad::~Squad()
{
    for (Unit* unit : m_units)
        delete unit;

    m_units.clear();
    std::cout << "Отряд уничтожается\n";
}

Unit* Squad::CreateUnit(int x, int y, int maxHealth, int attackDamage, double attackRange)
{
    Unit* unit = new Unit(maxHealth, attackDamage, attackRange, x, y, m_field, m_side);
    m_units.push_back(unit);
    return unit;
}

bool Squad::HasAliveUnits() const
{
    return std::any_of(m_units.begin(), m_units.end(), [](const Unit* unit) { return unit->IsAlive(); });

}

bool Squad::Contains(const Unit* unit) const
{
    return std::find(m_units.begin(), m_units.end(), unit) != m_units.end();
}

const std::vector<Unit*>& Squad::GetUnits() const
{
    return m_units;
}

}  //namespace tbs
