/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <response/Response.hpp>
#include "request/Request.hpp"

namespace Zia
{
    namespace Module
    {
        class IPreResponseModule
        {
        public:
            /**
             * Get the weight of the catchPreResponse method of this module.
             *
             * @return
             */
            virtual int getPreResponseWeight() const = 0;

            /**
             * Catch the response after it was created from the request and before the response is parse and create as string.
             *
             * @param request
             * @param response
             */
            virtual void catchPreResponse(const Zia::Request &request, Zia::Response &response) = 0;
        };
    }
}
