/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include "exception/Exception.hpp"

namespace Zia
{
    Exception::Exception(const std::string &msg)
            : exception(msg.c_str())
    {}
}
