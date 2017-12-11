/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include "Content.hpp"
#include "Status.hpp"
#include "header/HeaderWrapper.hpp"

namespace Zia
{
    class Response
    {
    private:
        Content _content;
        Status _status;
        HeaderWrapper _headers;

    public:
        /**
         * Constructor.
         */
        Response();

        /**
         * Copy Constructor.
         *
         * @param other
         */
        Response(Response &other);

        /**
         * Destructor.
         */
        ~Response();

        /**
         * Get the actual content of the response.
         *
         * @return
         */
        Content &getContent();

        /**
         * Get the actual status of the response.
         *
         * @return
         */
        Status &getStatus();

        /**
         * Get the actual headers of the response.
         *
         * @return
         */
        HeaderWrapper &getHeaders();

        /**
         * Alias for getHeaders().addHeader().
         *
         * @param header
         */
        void addHeader(const Header &header);

        /**
         * Set the actual content to a new one.
         *
         * @param content
         */
        void setContent(const Content &content);

        /**
         * Set the actual status to a new one.
         *
         * @param status
         */
        void setStatus(const Status &status);

        /**
         * Set the actual headers to a new one.
         * Should not be called.
         *
         * @param headers
         */
        void setHeaders(const HeaderWrapper &headers);
    };
}
