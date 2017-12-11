/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include "response/Response.hpp"
#include "request/Request.hpp"

namespace Zia
{
    namespace Module
    {
        class IPostRequestModule
        {
        public:
            /**
             * Get the weight of the catchPostRequest method of this module.
             *
             * @return
             */
            virtual int getPostRequestWeight() const = 0;

            /**
             * Catch the request as object after the httpd parsed and created it and before the Response was created.
             *
             * @param request
             * @return
             */
            virtual Zia::ResponsePtr catchPostRequest(Zia::Request &request) = 0;
        };
    }
}
