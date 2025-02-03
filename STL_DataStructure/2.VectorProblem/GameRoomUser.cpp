#include "GameRoomUser.h"

GameRoomUser::GameRoomUser()
{
    users.reserve(6);
}

GameRoomUser::~GameRoomUser()
{
}

bool GameRoomUser::AddUser(UserInfo& userInfo)
{
    if (users.size() >= maxCount) return false;

    if (masterUserName == "")
    {
        masterUserName = userInfo.userName;
    }

    users.push_back(userInfo);

    return true;
}

bool GameRoomUser::DeleteUser(const char* userName)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if (strcmp((*it).userName.c_str(), userName) == 0)
        {
            it = users.erase(it);

            if (it == users.begin())
            {
                masterUserName = (*it).userName;
            }

            return true;
        }
    }
    return false;
}

bool GameRoomUser::IsEmpty()
{
    return users.empty();
}

bool GameRoomUser::IsFull()
{
    return users.size() == maxCount;
}

bool GameRoomUser::GetUserOfName(const char* userName, UserInfo& userInfo)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if (strcmp((*it).userName.c_str(), userName) == 0)
        {
            userInfo = (*it);
            return true;
        }
    }
    return false;
}

UserInfo& GameRoomUser::GetMasterUser()
{
    return users.front();
}

UserInfo& GameRoomUser::GetUserOfLastOrder()
{
    return users.back();
}

bool GameRoomUser::BanUser(int orderNum)
{
    if (users.size() < orderNum) return false;
    
    auto it = users.begin() + orderNum - 1;
    it = users.erase(it);

    if (orderNum == 1)
    {
        masterUserName = (*it).userName;
    }

    return true;
}

void GameRoomUser::Clear()
{
    users.clear();
    masterUserName = "";
}
