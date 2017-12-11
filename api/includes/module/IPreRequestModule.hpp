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
        /**
         * @class IPreRequestModule
         */
        class IPreRequestModule
        {
        public:
            /**
             * Get the weight of the catchPreRequest method of this module.
             *
             * @return The weight of the catchPreRequest method of this module.
             */
            virtual int getPreRequestWeight() const = 0;

            /**
             * Catch the request as string after the receiving and before the Request object is parsed and created.
             *
             * @param request A string containing the raw data of the request.
             */
            virtual void catchPreRequest(Zia::Session &session, std::string &request) = 0;
        };
    }
}
