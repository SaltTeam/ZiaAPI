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
        std::string _ipv4;
        std::map<std::string, std::string> _params;

    public:
        explicit Session(const std::string &ipv4);

        const std::string &getIpv4() const;

        const std::map<std::string, std::string> &getParams() const;
    };

    typedef std::unique_ptr<Session> SessionPtr;
}
