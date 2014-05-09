#include "../h/Weapon.hpp"

void Weapon::update(float fTime) {
    // reload countdown
    if (m_reload_time > 0) {
        if (m_reload_time >= fTime) {
            m_reload_time -= fTime;
        } else {
            m_reload_time = 0;
        }
    }
}
