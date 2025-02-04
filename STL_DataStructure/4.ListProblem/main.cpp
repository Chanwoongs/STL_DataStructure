#include <iostream>
#include <list>
#include <string>
#include <vector>

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
    list.push_back(Point("D", Vector2(20, 80)));
    list.push_back(Point("D", Vector2(150, 80)));
    list.push_back(Point("D", Vector2(1780, 80)));
    list.push_back(Point("D", Vector2(1311, 80)));
    list.push_back(Point("E", Vector2(100, 200)));

    std::cout << list;

    if (Find(list, "D") != list.end())
    {
        list.insert(Find(list, "D"), Point("F", Vector2(180, 150)));
    }
    std::cout << '\n';
    std::cout << list;

    auto it = std::find_if(list.begin(), list.end(), [](const Point& p) {
        return p.name == "D";
        });
    
    std::cout << '\n';
    std::cout << (*it).name;

    std::cout << '\n';
    std::vector<std::list<Point>::iterator> v;
    it = list.begin();
    while (it != list.end())
    {
        //// 조건
        if ((*it).name == "D")
        {
            v.push_back(it);
        }
        ++it;





        it = std::find_if(it, list.end(), [](const Point& p) {
            return p.name == "D";
            });
        if (it != list.end())
        {
            v.push_back(it);
            ++it;
        }
    }
    std::cin.get();
}

