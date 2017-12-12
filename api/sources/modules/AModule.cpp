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

        inline void AModule::updateSettings(const std::map<std::string, std::string> &settings)
        {
            this->_settings = settings;
        }

        inline const std::string &AModule::getSetting(const std::string &key) const
        {
            return this->_settings.at(key);
        }

        inline const std::map<std::string, std::string> &AModule::getAllSettings() const
        {
            return this->_settings;
        }

        inline const std::string &AModule::getConfigPathFile() const
        {
            return this->_configPath;
        }
    }
}
