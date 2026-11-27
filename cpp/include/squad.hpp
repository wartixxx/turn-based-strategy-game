#pragma once

#include "side.hpp"
#include <vector>

namespace tbs
{

class Unit;
class Field;

class Squad
{
private:
    std::vector<Unit*> m_units{};
    Side m_side{};
    Field* m_field{};

public:
    Squad(Side side, Field* field);
    ~Squad();

    [[nodiscard]] Unit* CreateUnit(int x, int y, int maxHealth, int attackDamage, double attackRange);
    [[nodiscard]] bool HasAliveUnits() const;
    [[nodiscard]] bool Contains(const Unit* unit) const;
    [[nodiscard]] const std::vector<Unit*>& GetUnits() const;

    Squad(const Squad&) = delete;
    Squad& operator=(const Squad&) = delete;
};

}  // namespace tbs
