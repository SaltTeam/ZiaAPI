/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include <header/HeaderNormalizer.hpp>
#include "header/Header.hpp"

namespace Zia
{
    Header::Header()
            : _key(""), _value(""), _isCustom(true)
    {}

    Header::Header(const Header::RequestHeader &requestHeader, const std::string &value)
            : _key(Header::requestHeaderText.at(requestHeader)), _value(value), _isCustom(false)
    {}

    Header::Header(const Header::ResponseHeader &responseHeader, const std::string &value)
            : _key(Header::responseHeaderText.at(responseHeader)), _value(value), _isCustom(false)
    {}

    Header::Header(const std::string &key, const std::string &value)
            : _key(key), _value(value), _isCustom(true)
    {}

    const std::string Header::render(HeaderNormalizationType type) const
    {
        if (_isCustom)
        {
            std::string normalizedKey = _key;
            HeaderNormalizer::normalize(normalizedKey, type);
            return normalizedKey + ": " + _value;
        }
        return _key + ": " + _value;
    }

    const std::string &Header::getKey() const
    {
        return this->_key;
    }

    const std::string &Header::getValue() const
    {
        return this->_value;
    }

    void Header::setKey(const std::string &key)
    {
        this->_key = key;
    }

    void Header::setValue(const std::string &value)
    {
        this->_value = value;
    }

    const std::map<const Header::RequestHeader, const std::string> Header::requestHeaderText = {
            {Header::RequestHeader::ACCEPT,                         "Accept"},
            {Header::RequestHeader::ACCEPT_CHARSET,                 "Accept-Charset"},
            {Header::RequestHeader::ACCEPT_ENCODING,                "Accept-Encoding"},
            {Header::RequestHeader::ACCEPT_LANGUAGE,                "Accept-Language"},
            {Header::RequestHeader::ACCEPT_DATETIME,                "Accept-Datetime"},
            {Header::RequestHeader::ACCESS_CONTROL_REQUEST_METHOD,  "Accept-Control-Request-Method"},
            {Header::RequestHeader::ACCESS_CONTROL_REQUEST_HEADERS, "Accept-Control-Request-Headers"},
            {Header::RequestHeader::AUTHORIZATION,                  "Authorization"},
            {Header::RequestHeader::CACHE_CONTROL,                  "Cache-Control"},
            {Header::RequestHeader::CONNECTION,                     "Connection"},
            {Header::RequestHeader::COOKIE,                         "Cookie"},
            {Header::RequestHeader::CONTENT_LENGTH,                 "Content-Length"},
            {Header::RequestHeader::CONTENT_MD5,                    "Content-MD5"},
            {Header::RequestHeader::CONTENT_TYPE,                   "Content-Range"},
            {Header::RequestHeader::DATE,                           "Content-Type"},
            {Header::RequestHeader::EXPECT,                         "Expect"},
            {Header::RequestHeader::FORWARDED,                      "Forwarded"},
            {Header::RequestHeader::FROM,                           "From"},
            {Header::RequestHeader::HOST,                           "Host"},
            {Header::RequestHeader::IF_MATCH,                       "If-Match"},
            {Header::RequestHeader::IF_MODIFIED_SINCE,              "If-Modified-Since"},
            {Header::RequestHeader::IF_NONE_MATCH,                  "If-None-Match"},
            {Header::RequestHeader::IF_RANGE,                       "If-Range"},
            {Header::RequestHeader::IF_UNMODIFIED_SINCE,            "If-Unmodified-Since"},
            {Header::RequestHeader::MAX_FORWARDS,                   "Max-Forwards"},
            {Header::RequestHeader::ORIGIN,                         "Origin"},
            {Header::RequestHeader::PRAGMA,                         "Pragma"},
            {Header::RequestHeader::PROXY_AUTHORIZATION,            "Proxy-Authorization"},
            {Header::RequestHeader::RANGE,                          "Range"},
            {Header::RequestHeader::REFERER,                        "Referer"},
            {Header::RequestHeader::TE,                             "TE"},
            {Header::RequestHeader::USER_AGENT,                     "User-Agent"},
            {Header::RequestHeader::UPGRADE,                        "Upgrade"},
            {Header::RequestHeader::VIA,                            "Via"},
            {Header::RequestHeader::WARNING,                        "Warning"},
#ifdef SUPPORT_NON_STANDARD_REQUEST_HEADERS
            {Header::RequestHeader::X_REQUESTED_WITH,               "X-Requested-With"},
            {Header::RequestHeader::DNT,                            "DNT"},
            {Header::RequestHeader::X_FORWARDED_FOR,                "X-Forwarded-For"},
            {Header::RequestHeader::X_FORWARDED_HOST,               "X-Forwarded-Host"},
            {Header::RequestHeader::X_FORWARDED_PROTO,              "X-Forwarded-Proto"},
            {Header::RequestHeader::FRONT_END_HTTPS,                "Front-End-Https"},
            {Header::RequestHeader::X_HTTP_METHOD_OVERRIDE,         "X-Http-Method-Override"},
            {Header::RequestHeader::X_ATT_DEVICEID,                 "X-ATT-DeviceId"},
            {Header::RequestHeader::X_WAP_PROFILE,                  "X-Wap-Profile"},
            {Header::RequestHeader::PROXY_CONNECTION,               "Proxy-Connection"},
            {Header::RequestHeader::X_UIDH,                         "X-UIDH"},
            {Header::RequestHeader::X_CSRF_TOKEN,                   "X-Csrf-Token"},
            {Header::RequestHeader::X_REQUEST_ID,                   "X-Request-ID"},
            {Header::RequestHeader::X_CORRELATION_ID,               "X-Correlation-ID"}
#endif // !SUPPORT_NON_STANDARD_REQUEST_HEADERS
    };

    const std::map<const Header::ResponseHeader, const std::string> Header::responseHeaderText = {
            {Header::ResponseHeader::ACCESS_CONTROL_ALLOW_ORIGIN,      "Access-Control-Allow-Origin"},
            {Header::ResponseHeader::ACCESS_CONTROL_ALLOW_CREDENTIALS, "Access-Control-Allow-Credentials"},
            {Header::ResponseHeader::ACCESS_CONTROL_EXPOSE_HEADERS,    "Access-Control-Expose-Headers"},
            {Header::ResponseHeader::ACCESS_CONTROL_MAX_AGE,           "Access-Control-Max-Age"},
            {Header::ResponseHeader::ACCESS_CONTROL_ALLOW_METHODS,     "Access-Control-Allow-Methods"},
            {Header::ResponseHeader::ACCESS_CONTROL_ALLOW_HEADERS,     "Access-Control-Allow-Headers"},
            {Header::ResponseHeader::ACCEPT_PATCH,                     "Accept-Path"},
            {Header::ResponseHeader::ACCEPT_RANGES,                    "Accept-Ranges"},
            {Header::ResponseHeader::AGE,                              "Age"},
            {Header::ResponseHeader::ALLOW,                            "Allow"},
            {Header::ResponseHeader::ALT_SVC,                          "Alt-Svc"},
            {Header::ResponseHeader::CACHE_CONTROL,                    "Cache-Control"},
            {Header::ResponseHeader::CONNECTION,                       "Connection"},
            {Header::ResponseHeader::CONTENT_DISPOSITION,              "Content-Disposition"},
            {Header::ResponseHeader::CONTENT_ENCODING,                 "Content-Encoding"},
            {Header::ResponseHeader::CONTENT_LANGUAGE,                 "Content-Language"},
            {Header::ResponseHeader::CONTENT_LENGTH,                   "Content-Length"},
            {Header::ResponseHeader::CONTENT_LOCATION,                 "Content-Location"},
            {Header::ResponseHeader::CONTENT_MD5,                      "Content-MD5"},
            {Header::ResponseHeader::CONTENT_RANGE,                    "Content-Range"},
            {Header::ResponseHeader::CONTENT_TYPE,                     "Content-Type"},
            {Header::ResponseHeader::DATE,                             "Date"},
            {Header::ResponseHeader::ETAG,                             "ETag"},
            {Header::ResponseHeader::EXPIRES,                          "Expires"},
            {Header::ResponseHeader::LAST_MODIFIED,                    "Last-Modified"},
            {Header::ResponseHeader::LINK,                             "Link"},
            {Header::ResponseHeader::LOCATION,                         "Location"},
            {Header::ResponseHeader::P3P,                              "P3P"},
            {Header::ResponseHeader::PRAGMA,                           "Pragma"},
            {Header::ResponseHeader::PROXY_AUTHENTICATE,               "Proxy-Authenticate"},
            {Header::ResponseHeader::PUBLIC_KEY_PINS,                  "Public-Key-Pins"},
            {Header::ResponseHeader::RETRY_AFTER,                      "Retry-With"},
            {Header::ResponseHeader::SERVER,                           "Server"},
            {Header::ResponseHeader::SET_COOKIE,                       "Set-Cookie"},
            {Header::ResponseHeader::STRICT_TRANSPORT_SECURITY,        "Strict-Transport-Security"},
            {Header::ResponseHeader::TRAILER,                          "Trailer"},
            {Header::ResponseHeader::TRANSFER_ENCODING,                "Trasnfer-Encoding"},
            {Header::ResponseHeader::TK,                               "TK"},
            {Header::ResponseHeader::UPGRADE,                          "Upgrade"},
            {Header::ResponseHeader::VARY,                             "Vary"},
            {Header::ResponseHeader::VIA,                              "Via"},
            {Header::ResponseHeader::WARNING,                          "Warning"},
            {Header::ResponseHeader::WWW_AUTHENTICATE,                 "WWW-Authenticate"},
            {Header::ResponseHeader::X_FRAME_OPTIONS,                  "X-Frame-Options"},
#ifdef SUPPORT_NON_STANDARD_RESPONSE_HEADERS
            {Header::ResponseHeader::CONTENT_SECURITY_POLICY,          "Content-Security-Policy"},
            {Header::ResponseHeader::X_CONTENT_SECURITY_POLICY,        "X-Content-Security-Policy"},
            {Header::ResponseHeader::X_WEBKIT_CSP,                     "X-Webkit-CSP"},
            {Header::ResponseHeader::REFRESH,                          "Refresh"},
            {Header::ResponseHeader::STATUS,                           "Status"},
            {Header::ResponseHeader::UPGRADE_INSECURE_REQUESTS,        "Upgrade-Insecure-Requests"},
            {Header::ResponseHeader::X_CONTENT_DURATION,               "X-Content-Duration"},
            {Header::ResponseHeader::X_CONTENT_TYPE_OPTIONS,           "X-Content-Type-Options"},
            {Header::ResponseHeader::X_POWERED_BY,                     "X-Powered-By"},
            {Header::ResponseHeader::X_REQUEST_ID,                     "X-Request-ID"},
            {Header::ResponseHeader::X_CORRELATION_ID,                 "X-Correlation-ID"},
            {Header::ResponseHeader::X_UA_COMPATIBLE,                  "X-UA-Compatible"},
            {Header::ResponseHeader::X_XSS_PROTECTION,                 "X-XSS-Protection"}
#endif // !SUPPORT_NON_STANDARD_RESPONSE_HEADERS
    };
}