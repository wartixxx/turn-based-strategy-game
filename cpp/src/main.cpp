#include "field.hpp"
#include "squad.hpp"
#include "unit.hpp"

#include <iostream>

int main()
{
    //Статическая инициализация
    tbs::Field field(10);
    std::cout << "Поле " << field.GetSize() << "x" << field.GetSize() << " создано\n";
    
    //Агрегация: поле создано отдельно и передается отряду указателем
    tbs::Squad squad(tbs::Side::ePlayer,&field);
    std::cout << "\nДо создания:\n" << "есть живые:" << squad.HasAliveUnits() << ", юнитов: " << squad.GetUnits().size() << "\n";

    //Композиция: юнитов создает отряд
    tbs::Unit* warrior = squad.CreateUnit(2, 3, 200, 30, 1.5);
    tbs::Unit* archer = squad.CreateUnit(3, 3, 150, 20, 4.0);

    std::cout << "\nПосле создания:\n" << " есть живые: " << squad.HasAliveUnits() << ", юнитов: " << squad.GetUnits().size() << "\n";

    for (const tbs::Unit* unit : squad.GetUnits())
    {
        std::cout << "  HP " << unit->GetHealth() << " на (" << unit->GetPosX() << ", " << unit->GetPosY() << ")\n";
    }

    std::cout << "\n   Работа по ссылке и указателю   \n";

    tbs::Unit& ref = *warrior;          // ссылка — второе имя того же объекта

    std::cout << "HP через указатель: " << warrior->GetHealth() << "\n";
    std::cout << "HP через ссылку:    " << ref.GetHealth() << "\n";

    ref.TakeDamage(30);                 // меняем через ссылку
    std::cout << "После TakeDamage через ссылку:\n";
    std::cout << "  указатель: " << warrior->GetHealth() << "\n";
    std::cout << "  ссылка:    " << ref.GetHealth() << "\n";

    warrior->TakeDamage(20);            // меняем через указатель
    std::cout << "После TakeDamage через указатель:\n";
    std::cout << "  указатель: " << warrior->GetHealth() << "\n";
    std::cout << "  ссылка:    " << ref.GetHealth() << "\n";
    
    std::cout << "\n   Проверка правил    \n";
    // 1. Корректное перемещение
    std::cout << "Корректное: MoveTo(4, 3) -> " << warrior->MoveTo(4, 3) << "\n";
    std::cout << "  позиция: (" << warrior->GetPosX() << ", "
          << warrior->GetPosY() << ")\n";

    // 2. Нарушение: за границу поля
    std::cout << "Нарушение: MoveTo(-1, 0) -> " << warrior->MoveTo(-1, 0) << "\n";
    std::cout << "  позиция не изменилась: (" << warrior->GetPosX() << ", "
          << warrior->GetPosY() << ")\n";

    warrior->TakeDamage(1000);

    std::cout << "\n после смерти первого:\n" << "есть живые: " << squad.HasAliveUnits() << ", юнитов: " << squad.GetUnits().size() << "\n";

    archer->TakeDamage(1000);

    std::cout << "\n после смерти второго:\n" << "есть живые: " << squad.HasAliveUnits() << ", юнитов: " << squad.GetUnits().size() << "\n";

    //Динамическая инициализация
    std::cout << "\n Динамическая инициализация\n";
    tbs::Unit* solo = new tbs::Unit(120, 15, 2.0, 6, 6, &field, tbs::Side::eEnemy);
    std::cout << "Адрес:" << solo << ", HP: " << solo->GetHealth() << ", позиция (" <<solo->GetPosX() << ", " << solo->GetPosY() << ")\n";
    delete solo;
    solo = nullptr;
    std::cout << "Объект удален вручную\n";
   
    std::cout << "\n    Динамический массив объектов    \n";

    tbs::Field* fields = new tbs::Field[2]{ tbs::Field(10), tbs::Field(12) };

    std::cout << "Поле 0: " << fields[0].GetSize() << "\n";
    std::cout << "Поле 1: " << fields[1].GetSize() << "\n";

    delete[] fields;      
    fields = nullptr;

    std::cout << "Массив объектов удалён\n";

    std::cout << "\n   Массив динамических объектов   \n";

    tbs::Field** fieldPointers = new tbs::Field*[2];

    fieldPointers[0] = new tbs::Field(8);
    fieldPointers[1] = new tbs::Field(14);

    std::cout << "Поле 0: " << fieldPointers[0]->GetSize() << "\n";
    std::cout << "Поле 1: " << fieldPointers[1]->GetSize() << "\n";

    delete fieldPointers[0];
    delete fieldPointers[1];
    delete[] fieldPointers;
    fieldPointers = nullptr;

    std::cout << "Массив указателей удалён\n";

    static tbs::Field staticField(16);
    std::cout << "Статическое поле: " << staticField.GetSize() << "\n";

    return 0;
}