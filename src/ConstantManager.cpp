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
    m_constants["SystemCountX"] = "5";
    m_constants["SystemCountY"] = "5";
    m_constants["DefaultSystemX"] = "2";
    m_constants["DefaultSystemY"] = "2";

    m_constants["InactiveSystemUpdateDelay"] = "1";
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
        return "";
    else
        return it->second;
}
