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
        Method getMethod() const;

        /**
         * Get the Request Method in string.
         *
         * @return
         */
        const std::string &getMethodText() const;

        /**
         * Get the Request URI.
         *
         * @return
         */
        const std::string &getUri() const;

        /**
         * Get the Request HTTP Version.
         *
         * @return
         */
        const std::string &getHttpVersion() const;

        /**
         * Get the Request Headers.
         *
         * @return
         */
        const HeaderWrapper &getHeaders() const;

        /**
         * Get the Request Body.
         *
         * @return
         */
        const std::string &getBody() const;

        /**
         * Get the Request params parsed from the body.
         *
         * @return
         */
        std::map<std::string, std::string> &getParams();
        
#ifdef REQUEST_SETTERS
        void setMethod(Method method);

        void setMethodText(const std::string &methodText);

        void setUri(const std::string &uri);

        void setHttpVersion(const std::string &httpVersion);

        void setHeaders(const HeaderWrapper &headers);

        void setBody(const std::string &body);
#endif // !REQUEST_SETTERS
    };
}
