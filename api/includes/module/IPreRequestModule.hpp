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
        class IPreRequestModule
        {
        public:
            /**
             * Get the weight of the catchPreRequest method of this module.
             *
             * @return
             */
            virtual int getPreRequestWeight() const = 0;

            /**
             * Catch the request as string after the receiving and before the Request object is parsed and created.
             *
             * @param request
             */
            virtual void catchPreRequest(std::string &request) = 0;
        };
    }
}
