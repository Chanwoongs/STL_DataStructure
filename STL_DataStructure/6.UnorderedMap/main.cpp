#include <iostream>
#include <unordered_map>

// 게임 캐릭터 클래스
class GameCharacter
{
public:
    GameCharacter() = default;
    GameCharacter(int code, int level, int money)
        : code(code), level(level), money(money)
    {

    }
    ~GameCharacter() = default;

    // Getter
    const int Code() const { return code; }
    const int Level() const { return level; }
    const int Money() const { return money; }

    // 출력을 위한 연산자 오버로딩
    friend std::ostream& operator<<(std::ostream& os, const GameCharacter& character)
    {
        return os << "코드: " << character.code << " | 레벨: " << character.level << " | 돈: " << character.money << '\n';
    }

private:
    int code = 0;
    int level = 0;
    int money = 0;
};

int main()
{
    // 해시 테이블 선언
    std::unordered_map<int, GameCharacter> characters;

    GameCharacter character1(10, 1, 30000);
    characters.insert(std::make_pair(character1.Code(), character1));

    GameCharacter character2(20, 3, 4000);
    characters.insert(std::make_pair(character2.Code(), character2));

    std::cout << characters[10];

    for (auto& pair : characters)
    {
        std::cout << pair.second;
    }

    auto it = characters.find(10);
    if (it != characters.end())
    {
        std::cout << it->second;
    }
}