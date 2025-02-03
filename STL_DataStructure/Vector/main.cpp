#include <iostream>
#include <vector>

int main()
{
    // vector 변수 선언
    std::vector<int> vector;

    // 비었는지 확인
    //if (vector.size() == 0)
    // 사이즈를 0으로 비교할 거면 empty()를 사용하라.
    if (vector.empty())
    {
        std::cout << "vector가 비었음\n";
    }

    // 자료 삽입
    for (int i = 0; i < 1000; ++i)
    {
        // 예전에는 push_back에 rvalue reference가 지원이 안되었는데 이제는 똑같다.
        // vector.push_back(i + 1);
        // 예전 C++에는 아직 차이가 있어서 emplace_back이 성능이 좋다.
        vector.emplace_back(i + 1);
    }

    // 요소 삭제 (안되는 케이스)
    //for (int i = 0; i < 1000; i += 10)
    //{
    //    // 삭제를 원하는 위치의 반복자 저장
    //    auto iterator = vector.begin() + i;

    //    // 앞에서 구한 반복자를 활용해 배열 원소 삭제
    //    vector.erase(iterator);
    //}

    // 요소 삭제 (맞는 케이스)
    for (auto it = vector.begin(); it != vector.end();)
    {
        it = vector.erase(it);
        if (it != vector.end())
        {
            ++it;
        }
    }

    // 모두 소거, capacity는 그대로, 저장 공간은 남아있다.
    // 내부 저장 변수가 포인터인 경우에는 delete 해야함.
    vector.clear();

    if (vector.empty())
    {
        std::cout << "vector가 비었음\n";
    }

    // 크기 조정
    vector.resize(0);

    // 공간 확보 (처음 크기나 공간을 알 때, 재할당 방지, 공간 최적화)
    vector.reserve(0);

    // 실제 원소가 있는 만큼 사이즈를 줄이기
    vector.shrink_to_fit();

    std::cin.get();
}