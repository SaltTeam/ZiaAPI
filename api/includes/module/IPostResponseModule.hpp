/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <string>

namespace Zia
{
    namespace Module
    {
        class IPostResponseModule
        {
        public:
            /**
             * Get the weight of the catchPostResponse method of this module.
             *
             * @return
             */
            virtual int getPostResponseWeight() const = 0;

            /**
             * Catch the response as string after it was build by the httpd and before the sending.
             *
             * @param response
             */
            virtual void catchPostResponse(std::string &response) = 0;
        };
    }
}
