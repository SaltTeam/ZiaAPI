/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include "module/AModule.hpp"

namespace Zia
{
    namespace Module
    {
        AModule::AModule()
                : _configPath("./config/default.json")
        {}

        AModule::~AModule()
        {
            this->_settings.clear();
        }
    }
}
