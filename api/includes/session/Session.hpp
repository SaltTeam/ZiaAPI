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
#include <memory>

/**
 * @namespace Zia
 */
namespace Zia
{
    /**
     * @class Session
     * @brief This class correspond to all the session params registered for each unique client
     */
    class Session
    {
    private:
        /**
         * The "key" of the session which corresponding to the ipv4 of the connected client
         */
        std::string _ipv4;

        /**
         * The session params, everything which must be memorized between multiple different connections can be placed into this map
         */
        std::map<std::string, std::string> _params;

    public:
        explicit Session(const std::string &ipv4);

        /**
         * Get the session ipv4
         *
         * @return The session ipv4
         */
        inline const std::string &getIpv4() const;

        /**
         * Get the session params map
         *
         * @return The session params map
         */
        inline std::map<std::string, std::string> &getParams();
    };

    typedef std::unique_ptr<Session> SessionPtr;
}
