#pragma once

#include "side.hpp"

namespace tbs
{

class Field;

class Unit 
{
private:
    int m_health{};
    int m_maxHealth{};
    int m_attackDamage{};
    double m_attackRange{};
    int m_posX{};
    int m_posY{};
    Field* m_field{};
    Side m_side{};

public:
    Unit(int maxHealth, int attackDamage, double attackRange, int posX, int posY, Field* field, Side side);
    ~Unit();

    [[nodiscard]] bool IsAlive() const;
    void Heal(int amount);
    void TakeDamage(int damage);

    [[nodiscard]] bool MoveTo(int x, int y);
    [[nodiscard]] bool IsInRange(int x, int y) const;
    [[nodiscard]] bool IsEnemy(const Unit& other) const;

    [[nodiscard]] int GetHealth() const;
    [[nodiscard]] int GetMaxHealth() const;
    [[nodiscard]] int GetAttackDamage() const;
    [[nodiscard]] double GetAttackRange() const;
    [[nodiscard]] int GetPosX() const;
    [[nodiscard]] int GetPosY() const;
    [[nodiscard]] Side GetSide() const;

    Unit(const Unit&) = delete;
    Unit& operator=(const Unit&) = delete;
};

}  // namespace tbs