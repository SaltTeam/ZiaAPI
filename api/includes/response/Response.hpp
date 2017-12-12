/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <memory>

#include "Content.hpp"
#include "Status.hpp"
#include "header/HeaderWrapper.hpp"

namespace Zia
{
    /**
     * The Response class
     *
     * @class Response
     */
    class Response
    {
    private:
        Content _content;
        Status _status;
        HeaderWrapper _headers;

        /**
         * The Request HTTP Version.
         * eg. HTTP/1.1
         */
        std::string _httpVersion;

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
         * Render the response to std::string
         *
         * @param setAutoLength
         * @return
         */
        const std::string render(bool setAutoLength = true);

        /**
         * Get the actual content of the response.
         *
         * @return The actual content of the response
         */
        inline Content &getContent();

        /**
         * Get the actual status of the response.
         *
         * @return The actual status of the response
         */
        inline Status &getStatus();

        /**
         * Get the actual headers of the response.
         *
         * @return The actual headers of the response
         */
        inline HeaderWrapper &getHeaders();

        /**
         * Get the Request HTTP Version.
         *
         * @return A string containing the HTTP version of the request.
         */
        inline std::string &getHttpVersion();

        /**
         * Alias for getHeaders().addHeader().
         *
         * @param header The Header to add.
         */
        inline void addHeader(const Header &header);

        /**
         * Set the actual content to a new one.
         *
         * @param content The new content
         */
        inline void setContent(const Content &content);

        /**
         * Set the actual status to a new one.
         *
         * @param status The new status
         */
        inline void setStatus(const Status &status);

        /**
         * Set the HttpVersion
         *
         * @param httpVersion
         */
        inline void setHttpVersion(const std::string &httpVersion);

        /**
         * Set the actual headers to a new one.
         * Should not be called.
         *
         * @param headers The new headers
         */
        inline void setHeaders(const HeaderWrapper &headers);
    };

    typedef std::unique_ptr<Response> ResponsePtr;
}
