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

/**
 * @namespace Zia
 */
namespace Zia
{
    /**
     * @class ServerError
     * @brief Exception for a internal server error.
     *        Break the execution chain of the response / request.
     *        Immediately send a response according to the given HTTP status.
     */
    class ServerError : public Exception
    {
    private:
        Status _status;

    public:
	/**
	 * @brief Constructor for the ServerError
	 * @param status The HTTP status to send in the response.
	 */
        explicit ServerError(const Status &status);

	/**
	 * @return The HTTP status of the Exception.
	 */
        const Status &getStatus() const;
    };
}
