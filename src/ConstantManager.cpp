#include "../h/../h/ConstantManager.hpp"
#include <iostream>

ConstantManager& ConstantManager::get()
{
    static ConstantManager instance;
    return instance;
}

std::string getConstant(std::string key)
{
    return ConstantManager::get().getValue(key);
}

void ConstantManager::setDefaults()
{
    m_constants.clear();

    // Collision-Manager
    m_constants["CollisionGridResolutionX"] = "2";
    m_constants["CollisionGridResolutionY"] = "2";
    m_constants["CollisionGridResetDelay"] = "2";

    // Space
    m_constants["SystemSizeX"] = "2000";
    m_constants["SystemSizeY"] = "2000";
    m_constants["SystemCountX"] = "5";
    m_constants["SystemCountY"] = "5";
    m_constants["DefaultSystemX"] = "2";
    m_constants["DefaultSystemY"] = "2";
    m_constants["InactiveSystemUpdateDelay"] = "10";

    // General
    m_constants["ImageFolder"] = "res/";
    m_constants["MenuViewWidth"] = "1600";
    m_constants["MenuViewHeight"] = "1200";

    // Physics
    m_constants["Drag"] = "0.9";

    // Asteroid
    m_constants["AsteroidMinScale"] = "0.05";
    m_constants["AsteroidMaxScale"] = "0.7";
    m_constants["AsteroidMaxSpeed"] = "500";
    m_constants["AsteroidCount"] = "0";
}

int ConstantManager::init()
{
    // TODO: Load constants from file
    return 0;
}

std::string ConstantManager::getValue(std::string key)
{
    auto it = m_constants.find(key);
    if(it == m_constants.end())
    {
        std::cout << "[ConstantManager] Invalid constant requested, code propably won't run as expected" << std::endl;
        return "";
    }
    else
        return it->second;
}
