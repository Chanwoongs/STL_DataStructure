#include <iostream>
#include <list>
#include <algorithm>

// 아이템 구조체
struct Item
{
    Item(int code = 0, int price = 0)
        : code(code), price(price)
    {

    }

    int code = 0;
    int price = 0;
};

// 데이터 출력용 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const Item& item)
{
    return os << "코드: " << item.code << ", 가격: " << item.price;
}

// 데이터 출력용 연산자 오버로딩
std::ostream& operator<<(std::ostream& os, const std::list<Item>& items)
{
    for (auto& item : items)
    {
        os << "코드: " << item.code << ", 가격: " << item.price << '\n';
    }
    return os;
}

struct ItemCodeLessComparer
{
    bool operator()(const Item& left, const Item& right)
    {
        return left.code < right.code;
;    }
};

int main()
{
    std::list<Item> itemList;

    // 데이터 추가
    itemList.emplace_front(Item(1, 200));
    itemList.emplace_front(Item(2, 3200));

    // 뒤에 추가
    itemList.emplace_back(Item(3, 10));
    itemList.emplace_back(Item(4, 1233));

    for (std::list<Item>::iterator iterator = itemList.begin();
        iterator != itemList.end(); ++iterator)
    {
        std::cout << *iterator << '\n';
    }
    std::cout << '\n';

    // 삭제
    itemList.pop_front();

    itemList.emplace_back(Item(5, 5462));
    itemList.emplace_back(Item(6, 2));
    itemList.emplace_back(Item(7, 16));
    std::cout << itemList;
    std::cout << '\n';

    // 정렬
    // 1 
    itemList.sort([](const Item& item1, const Item& item2) -> bool {
        return item1.price <  item2.price;
        });
    std::cout << itemList;
    std::cout << '\n';
    // 2
    itemList.sort(ItemCodeLessComparer());
    std::cout << itemList;
    std::cout << '\n';
}