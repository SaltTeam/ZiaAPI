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
#include <request/Request.hpp>
#include <response/Response.hpp>

namespace Zia
{
    /**
     * @namespace Module
     */
    namespace Module
    {
        /**
         * Module Interface.
         *
         * Every modules must implements this interface to be compatible with the Zia Httpd server.
         *
         * @class IModule
         */
        class IModule
        {
        public:
            /**
             * Initialize the module.
             * Instantiate every needed resources.
             */
            virtual bool initialize() = 0;

            /**
             * Shutdown the module
             * Clear or pause every need resources.
             */
            virtual void shutdown() = 0;

            /**
             * Update the settings.
             * Called from the Zia Http Server.
             *
             * @param settings The settings gave by the configuration parser.
             */
            virtual void updateSettings(const std::map<std::string, std::string> &settings) = 0;

            /**
             * Get one setting from this module's settings
             *
             * @param key The settings directive.
             * @return The value associated to the directive.
             */
            virtual const std::string &getSetting(const std::string &key) const = 0;

            /**
             * Get the whole module's settings
             *
             * @return The map containing the settings
             */
            virtual const std::map<std::string, std::string> &getAllSettings() const = 0;

            /**
             * Get the configuration path file of the module.
             *
             * @return The configuration path file of the module
             */
            virtual const std::string &getConfigPathFile() const = 0;
        };
    }
}
