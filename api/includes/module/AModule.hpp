/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <string>
#include <map>

#include "IModule.hpp"

namespace Zia
{
    namespace Module
    {
        /**
         * Module Abstract.
         *
         * If you want to have all the settings code already set, you should extends from this class.
         *
         * @class AModule
         */
        class AModule : public IModule
        {
        protected:
            const std::string _configPath;
            std::map<std::string, std::string> _settings;

        public:
            /**
             * Constructor.
             */
            AModule();

            /**
             * Destructor.
             * Clear the settings map
             */
            ~AModule();

            /**
             * Final implementation of the updateSettings method
             *
             * @see Zia::Modules::IModule::updateSettings for more details
             *
             * @param settings The new settings sent by Https server
             */
            void updateSettings(const std::map<std::string, std::string> &settings) final;

            /**
             * Final implementation of the getSetting method
             *
             * @see Zia::Modules::IModule::getSetting for more details
             *
             * @param key The key of the setting we attempt to get.
             * @return The corresponding setting
             */
            const std::string &getSetting(const std::string &key) const final;

            /**
             * Final implementation of the getAllSettings method
             *
             * @see Zia::Modules::IModule::getAllSettings for more details
             *
             * @return The whole settings map
             */
            const std::map<std::string, std::string> &getAllSettings() const final;

            /**
             * Final implementation of the getConfigPathFile
             *
             * @see Zia::Modules::IModule::getConfigPathFile for more details
             *
             * @return The configuration path file of the module
             */
            const std::string &getConfigPathFile() const final;

            //
            // Interface's methods not-implemented
            //

            /**
             * @see Zia::Modules::IModule::initialize for more details
             */
            virtual bool initialize() = 0;

            /**
             * @see Zia::Modules::IModule::shutdown for more details
             */
            virtual void shutdown() = 0;
        };
    }
}
