/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include "session/Session.hpp"
#include "response/Response.hpp"
#include "request/ConstRequest.hpp"
#include "request/Request.hpp"

namespace Zia
{
    namespace Module
    {
        /**
         * @class IPreResponseModule
         */
        class IPreResponseModule
        {
        public:
            /**
             * Get the weight of the catchPreResponse method of this module.
             *
             * @return The weight of the catchPreResponse method of this module.
             */
            virtual int getPreResponseWeight() const = 0;

            /**
             * Catch the response after it was created from the request and before the response is parse and create as string.
             *
             * @param request The Request object associated to the response.
             * @param response The response object to pass to the module.
             */
            virtual void catchPreResponse(Zia::Session &session, const Zia::ConstRequest &request, Zia::Response &response) = 0;
        };
    }
}
