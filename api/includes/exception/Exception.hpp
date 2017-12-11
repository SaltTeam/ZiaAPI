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

/**
 * @namespace Zia
 */
namespace Zia
{
    /**
     * @class Exception
     * @brief Generic runtime_error implementation for the ZiaAPI
     */
    class Exception : public std::runtime_error
    {
    public:
        /**
         * @brief Constructor for the Exception class
         * @param msg The error message corresponding to the exception
         */
        explicit Exception(const std::string &msg);
    };
}
