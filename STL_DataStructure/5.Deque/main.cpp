#include <iostream>
#include <deque>

int main()
{
    std::deque<int> deque;

    deque.emplace_back(100);
    deque.emplace_front(200);

    for (int i = 0; i < (int)deque.size(); ++i)
    {
        std::cout << deque[i] << '\n';
    }

    auto data = deque.back();
    deque.pop_back();

    std::cout << data << '\n';

    deque.clear();
    if (deque.empty())
    {
        std::cout << "덱이 비었습니다\n";
    }

    deque.insert(deque.begin(), { 1, 2, 3, 4, 5 });

    for (int i = 0; i < (int)deque.size(); ++i)
    {
        std::cout << deque[i] << '\n';
    }
}