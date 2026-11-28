#include "field.hpp"

#include <cmath>
#include <stdexcept>
#include <iostream>

namespace tbs
{

Field::Field(int size)
    : m_size{ size }
{
    if (size <= 0)
        throw std::invalid_argument("size must be positive");
}

Field::~Field()
{
    std::cout << "Field уничтожается\n"; 
}

int Field::GetSize() const
{
    return m_size;
}

bool Field::IsInside(int x, int y) const
{
    return x >= 0 && x < m_size && y >= 0 && y < m_size;
}

double Field::Distance(int x1, int y1, int x2, int y2) const
{
    int x = x2 - x1;
    int y = y2 - y1;
    return std::sqrt(x*x + y*y);
}

}  // namespace tbs
