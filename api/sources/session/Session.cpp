/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include "session/Session.hpp"

namespace Zia
{
    Session::Session(const std::string &ipv4)
            : _ipv4(ipv4)
    {}

    const std::string &Session::getIpv4() const
    { return _ipv4; }

    std::map<std::string, std::string> &Session::getParams()
    { return _params; }
}
