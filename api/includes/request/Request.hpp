/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <string>
#include <unordered_map>
#include <map>
#include <memory>

#include "header/HeaderWrapper.hpp"

namespace Zia
{
    /**
     * @see https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol
     */
    class Request
    {
    public:
        /**
         * All the standard available Method
         */
        enum class Method
        {
            CUSTOM,
            GET,
            POST,
            PUT,
            DELETE,
            PATCH,
            HEAD,
            OPTIONS,
            CONNECT,
            TRACE
        };

        /**
         * Used to recover the correct Method enum
         */
        static const std::map<const std::string, const Method> methodText;

    private:
        /**
         * The Request Method.
         */
        Method _method;

        /**
         * The Request Method (string) in case of Method::CUSTOM.
         */
        std::string _methodText;

        /**
         * The Request URI.
         */
        std::string _uri;

        /**
         * The Request HTTP Version.
         * eg. HTTP/1.1
         */
        std::string _httpVersion;

        /**
         * The Request Headers.
         */
        HeaderWrapper _headers;

        /**
         * The Request Body.
         * Have to be parsed to recover params. eg. POST
         */
        std::string _body;

        std::map<std::string, std::string> _params;

    public:
        Request();

        ~Request();

        /**
         * Get the Request Method.
         *
         * @return
         */
        Method getMethod();

        /**
         * Get the Request Method in string.
         *
         * @return
         */
         std::string &getMethodText();

        /**
         * Get the Request URI.
         *
         * @return
         */
         std::string &getUri();

        /**
         * Get the Request HTTP Version.
         *
         * @return
         */
         std::string &getHttpVersion();

        /**
         * Get the Request Headers.
         *
         * @return
         */
         HeaderWrapper &getHeaders();

        /**
         * Get the Request Body.
         *
         * @return
         */
         std::string &getBody();

        /**
         * Get the Request params parsed from the body.
         *
         * @return
         */
        std::map<std::string, std::string> &getParams();
        
#ifdef REQUEST_SETTERS
        void setMethod(Method method);

        void setMethodText( std::string &methodText);

        void setUri( std::string &uri);

        void setHttpVersion( std::string &httpVersion);

        void setHeaders( HeaderWrapper &headers);

        void setBody( std::string &body);
#endif // !REQUEST_SETTERS
    };

    typedef std::unique_ptr<Request> RequestPtr;
}
