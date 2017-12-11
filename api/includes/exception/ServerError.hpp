/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include "response/Status.hpp"
#include "exception/Exception.hpp"

namespace Zia
{
    class ServerError : public Exception
    {
    private:
        Status _status;

    public:
        explicit ServerError(const Status &status);

        const Status &getStatus() const;
    };
}
