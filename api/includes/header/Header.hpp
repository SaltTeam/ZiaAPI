/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <string>
#include <map>
#include <vector>

namespace Zia
{
    /**
     * Forward declaration
     */
    enum HeaderNormalizationType : short;

    /**
     * @see https://en.wikipedia.org/wiki/List_of_HTTP_header_fields
     */
    class Header
    {
    public:
        /**
         * All the authorized header for Request
         */
        enum class RequestHeader
        {
            ACCEPT,
            ACCEPT_CHARSET,
            ACCEPT_ENCODING,
            ACCEPT_LANGUAGE,
            ACCEPT_DATETIME,
            ACCESS_CONTROL_REQUEST_METHOD,
            ACCESS_CONTROL_REQUEST_HEADERS,
            AUTHORIZATION,
            CACHE_CONTROL,
            CONNECTION,
            COOKIE,
            CONTENT_LENGTH,
            CONTENT_MD5,
            CONTENT_TYPE,
            DATE,
            EXPECT,
            FORWARDED,
            FROM,
            HOST,
            IF_MATCH,
            IF_MODIFIED_SINCE,
            IF_NONE_MATCH,
            IF_RANGE,
            IF_UNMODIFIED_SINCE,
            MAX_FORWARDS,
            ORIGIN,
            PRAGMA,
            PROXY_AUTHORIZATION,
            RANGE,
            REFERER,
            TE,
            USER_AGENT,
            UPGRADE,
            VIA,
            WARNING,
#ifdef SUPPORT_NON_STANDARD_REQUEST_HEADERS
            X_REQUESTED_WITH,
            DNT,
            X_FORWARDED_FOR,
            X_FORWARDED_HOST,
            X_FORWARDED_PROTO,
            FRONT_END_HTTPS,
            X_HTTP_METHOD_OVERRIDE,
            X_ATT_DEVICEID,
            X_WAP_PROFILE,
            PROXY_CONNECTION,
            X_UIDH,
            X_CSRF_TOKEN,
            X_REQUEST_ID,
            X_CORRELATION_ID
#endif // !SUPPORT_NON_STANDARD_REQUEST_HEADERS
        };

        /**
         * List for all authorized request header
         */
        static const std::map<const RequestHeader, const std::string> requestHeaderText;

        /**
         * All the authorized header for Response
         */
        enum class ResponseHeader
        {
            ACCESS_CONTROL_ALLOW_ORIGIN,
            ACCESS_CONTROL_ALLOW_CREDENTIALS,
            ACCESS_CONTROL_EXPOSE_HEADERS,
            ACCESS_CONTROL_MAX_AGE,
            ACCESS_CONTROL_ALLOW_METHODS,
            ACCESS_CONTROL_ALLOW_HEADERS,
            ACCEPT_PATCH,
            ACCEPT_RANGES,
            AGE,
            ALLOW,
            ALT_SVC,
            CACHE_CONTROL,
            CONNECTION,
            CONTENT_DISPOSITION,
            CONTENT_ENCODING,
            CONTENT_LANGUAGE,
            CONTENT_LENGTH,
            CONTENT_LOCATION,
            CONTENT_MD5,
            CONTENT_RANGE,
            CONTENT_TYPE,
            DATE,
            ETAG,
            EXPIRES,
            LAST_MODIFIED,
            LINK,
            LOCATION,
            P3P,
            PRAGMA,
            PROXY_AUTHENTICATE,
            PUBLIC_KEY_PINS,
            RETRY_AFTER,
            SERVER,
            SET_COOKIE,
            STRICT_TRANSPORT_SECURITY,
            TRAILER,
            TRANSFER_ENCODING,
            TK,
            UPGRADE,
            VARY,
            VIA,
            WARNING,
            WWW_AUTHENTICATE,
            X_FRAME_OPTIONS,
#ifdef SUPPORT_NON_STANDARD_RESPONSE_HEADERS
            CONTENT_SECURITY_POLICY,
            X_CONTENT_SECURITY_POLICY,
            X_WEBKIT_CSP,
            REFRESH,
            STATUS,
            UPGRADE_INSECURE_REQUESTS,
            X_CONTENT_DURATION,
            X_CONTENT_TYPE_OPTIONS,
            X_POWERED_BY,
            X_REQUEST_ID,
            X_CORRELATION_ID,
            X_UA_COMPATIBLE,
            X_XSS_PROTECTION
#endif // !SUPPORT_NON_STANDARD_RESPONSE_HEADERS
        };

        /**
         * List for all authorized response header
         */
        static const std::map<const ResponseHeader, const std::string> responseHeaderText;

    private:
        std::string _key;
        std::string _value;
        bool _isCustom;

    public:
        Header();

        explicit Header(const RequestHeader &requestHeader, const std::string &value = "");

        explicit Header(const ResponseHeader &responseHeader, const std::string &value = "");

        explicit Header(const std::string &key, const std::string &value = "");

        const std::string render(HeaderNormalizationType) const;

        const std::string &getKey() const;

        const std::string &getValue() const;

        void setKey(const std::string &key);

        void setValue(const std::string &value);
    };
}
