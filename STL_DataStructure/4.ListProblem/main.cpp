#include <iostream>
#include <list>
#include <string>

struct Vector2
{
    int x, y;

    Vector2(int x = 0, int y = 0)
        : x(x), y(y)
    {

    }
};

struct Point
{
    std::string name;
    Vector2 position;

    Point(std::string name, Vector2&& position)
        : name(name)
    {
        this->position = std::move(position);
    }
};

std::ostream& operator<<(std::ostream& os, const std::list<Point>& points)
{
    for (auto& point : points)
    {
        os << point.name << ": (" << point.position.x << ", " << point.position.y << ")\n";
    }
    return os;
}

std::list<Point>::iterator Find(std::list<Point>& list, const std::string value)
{
    for (auto it = list.begin(); it != list.end(); it++)
    {
        if ((*it).name == value)
        {
            return it;
        }
    }
    return list.end();
}

int main()
{
    std::list<Point> list;

    list.push_back(Point("A", Vector2(50, 200)));
    list.push_back(Point("B", Vector2(20, 80)));
    list.push_back(Point("C", Vector2(75, 10)));
    list.push_back(Point("D", Vector2(130, 80)));
    list.push_back(Point("E", Vector2(100, 200)));

    std::cout << list;

    if (Find(list, "D") != list.end())
    {
        list.insert(Find(list, "D"), Point("F", Vector2(180, 150)));
    }
    std::cout << '\n';
    std::cout << list;
}

