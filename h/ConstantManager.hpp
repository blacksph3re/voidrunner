#ifndef CONSTANTMANAGER_HPP_INCLUDED
#define CONSTANTMANAGER_HPP_INCLUDED

#include <string>
#include <map>

class ConstantManager
{
private:
    std::map<std::string, std::string> m_constants;

    void setDefaults();
    ConstantManager() {setDefaults();}
    ConstantManager(const ConstantManager& rhs) {}
public:
    static ConstantManager& get();
    int init();
    std::string getValue(std::string key);
};

std::string getConstant(std::string key);

#endif // CONSTANTMANAGER_HPP_INCLUDED
