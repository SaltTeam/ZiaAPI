/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include "exception/ServerError.hpp"

namespace Zia
{
    ServerError::ServerError(const Status &status)
            : Exception(status.getText()), _status(status)
    {}

    const Status &ServerError::getStatus() const
    {
        return _status;
    }
}
