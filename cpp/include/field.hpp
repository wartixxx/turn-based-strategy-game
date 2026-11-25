#pragma once

namespace tbs
{

class Field
{
private:
    int m_size{};

public:
    explicit Field(int size);

    [[nodiscard]] int GetSize() const;
    [[nodiscard]] bool IsInside(int x, int y) const;
    [[nodiscard]] double Distance(int x1, int y1, int x2, int y2) const;

};
}  // namespace tbs
