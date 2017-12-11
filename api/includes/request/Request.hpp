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
     *
     * @class Request
     */
    class Request
    {
    public:
        /**
         * All the standard available Method
         *
         * @enum Method
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
         * @return The HTTP method of the request
         */
        Method getMethod() const;

        /**
         * Get the Request Method in string.
         *
         * @return A string containing the request's HTTP method
         */
         std::string &getMethodText();

        /**
         * Get the Request URI.
         *
         * @return A string containing the request URI
         */
         std::string &getUri();

        /**
         * Get the Request HTTP Version.
         *
         * @return A string containing the HTTP version of the request.
         */
         std::string &getHttpVersion();

        /**
         * Get the Request Headers.
         *
         * @return A container containing the HTTP headers of the request.
         */
         HeaderWrapper &getHeaders();

        /**
         * Get the Request Body.
         *
         * @return The raw data of the request.
         */
         std::string &getBody();

        /**
         * Get the Request params parsed from the body.
         *
         * @return The params of the request
         */
        std::map<std::string, std::string> &getParams();
    };

    typedef std::unique_ptr<Request> RequestPtr;
}
