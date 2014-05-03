#include "../h/../h/ConstantManager.hpp"

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
    m_constants["CollisionGridResolutionX"] = "3";
    m_constants["CollisionGridResolutionY"] = "3";
    m_constants["CollisionGridResetDelay"] = "2";

    m_constants["SystemSizeX"] = "2000";
    m_constants["SystemSizeY"] = "2000";
    m_constants["GalaxySizeX"] = "5";
    m_constants["GalaxySizeY"] = "5";
}

int ConstantManager::init()
{
    return 0;
}

std::string ConstantManager::getValue(std::string key)
{
    auto it = m_constants.find(key);
    if(it == m_constants.end())
        return "";
    else
        return it->second;
}
