/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <session/Session.hpp>
#include "response/Response.hpp"
#include "request/Request.hpp"

namespace Zia
{
    namespace Module
    {
        /**
         * @class IPostRequestModule
         */
        class IPostRequestModule
        {
        public:
            /**
             * Get the weight of the catchPostRequest method of this module.
             *
             * @return The weight of the catchPostRequest method of this module
             */
            virtual int getPostRequestWeight() const = 0;

            /**
             * Catch the request as object after the httpd parsed and created it and before the Response was created.
             *
             * @param request The request to pass to the module.
             * @return A ResponsePtr pointing to the response to send or nullptr otherwise.
             */
            virtual Zia::ResponsePtr catchPostRequest(Zia::Session &session, Zia::Request &request) = 0;
        };
    }
}
