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

namespace Zia
{
    class Exception : public std::exception
    {
    public:
        explicit Exception(const std::string &msg);
    };
}
