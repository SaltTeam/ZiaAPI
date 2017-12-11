/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <exception>
#include <string>
#include <stdexcept>

namespace Zia
{
    class Exception : public std::runtime_error
    {
    public:
        explicit Exception(const std::string &msg);
    };
}
