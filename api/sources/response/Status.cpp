/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include "response/Status.hpp"

namespace Zia
{
    Status::Status()
    { this->setStandardStatus(StatusCode::OK); }

    Status::Status(Status::StatusCode code)
    { this->setStandardStatus(code); }

    Status::~Status()
    {}

    void Status::setStandardStatus(StatusCode code)
    {
        this->_code = code;
        this->_text = statusText.at(code);
    }

    void Status::setCustomStatus(unsigned int code, const std::string &text)
    {
        this->_code = code;
        this->_text = text;
    }

    unsigned int Status::getCode() const
    {
        return this->_code;
    }

    const std::string &Status::getText() const
    {
        return this->_text;
    }

    const std::map<const unsigned int, const std::string> Status::statusText = {
            {StatusCode::UNKNOWN,                         ""},
            {StatusCode::CONTINUE,                        "100 Continue"},
            {StatusCode::SWITCHING_PROTOCOLS,             "101 Switching Protocols"},
            {StatusCode::PROCESSING,                      "102 Processing"},
            {StatusCode::OK,                              "200 OK"},
            {StatusCode::CREATED,                         "201 Created"},
            {StatusCode::ACCEPTED,                        "202 ACCEPTED"},
            {StatusCode::NON_AUTHORITATIVE_INFORMATION,   "203 Non-Authoritative Information"},
            {StatusCode::NO_CONTENT,                      "204 No Content"},
            {StatusCode::RESET_CONTENT,                   "205 Reset Content"},
            {StatusCode::PARTIAL_CONTENT,                 "206 Partial Content"},
            {StatusCode::MULTI_STATUS,                    "207 Multi-Status"},
            {StatusCode::ALREADY_REPORTED,                "208 Already Reported"},
            {StatusCode::IM_USED,                         "226 IM Used"},
            {StatusCode::MULTIPLE_CHOICES,                "300 Multiple Choices"},
            {StatusCode::MOVED_PERMANENTLY,               "301 Moved Permanently"},
            {StatusCode::FOUND,                           "302 Found"},
            {StatusCode::SEE_OTHER,                       "303 See Other"},
            {StatusCode::NOT_MODIFIED,                    "304 Not Modified"},
            {StatusCode::USE_PROXY,                       "305 Use Proxy"},
            {StatusCode::SWITCH_PROXY,                    "306 Switch Proxy"},
            {StatusCode::TEMPORARY_REDIRECT,              "307 Temporary Redirect"},
            {StatusCode::PERMANENT_REDIRECT,              "308 Permanent Redirect"},
            {StatusCode::BAD_REQUEST,                     "400 Bad Request"},
            {StatusCode::UNAUTHORIZED,                    "401 Unauthorized"},
            {StatusCode::PAYEMENT_REQUIRED,               "402 Payment Required"},
            {StatusCode::FORBIDDEN,                       "403 Forbidden"},
            {StatusCode::NOT_FOUND,                       "404 Not Found"},
            {StatusCode::METHOD_NOT_ALLOWED,              "405 Method Not Allowed"},
            {StatusCode::NOT_ACCEPTABLE,                  "406 Not Acceptable"},
            {StatusCode::PROXY_AUTHENTICATION_REQUIRED,   "407 Proxy Authentication Required"},
            {StatusCode::REQUEST_TIMEOUT,                 "408 Request Timeout"},
            {StatusCode::CONFLICT,                        "409 Conflict"},
            {StatusCode::GONE,                            "410 Gone"},
            {StatusCode::LENGHT_REQUIRED,                 "411 Length Required"},
            {StatusCode::PRECONDITION_FAILED,             "412 Precondition Failed"},
            {StatusCode::PAYLOAD_TOO_LARGE,               "413 Payload Too Large"},
            {StatusCode::URI_TOO_LONG,                    "414 URI Too Long"},
            {StatusCode::UNSUPPORTED_MEDIA_TYPE,          "415 Unsupported Media Type"},
            {StatusCode::RANGE_NOT_SATISFIABLE,           "416 Range Not Satisfiable"},
            {StatusCode::EXPECTATION_FAILED,              "417 Expectation Failed"},
            {StatusCode::IM_A_TEAPOT,                     "418 I'm a teapot"},
            {StatusCode::MISDIRECTED_REQUEST,             "421 Misdirected Request"},
            {StatusCode::UNPROCESSABLE_ENTITY,            "422 Unprocessable Entity"},
            {StatusCode::LOCKED,                          "423 Locked"},
            {StatusCode::FAILED_DEPENDENCY,               "424 Failed Dependency"},
            {StatusCode::UPGRADE_REQUIRED,                "426 Upgrade Required"},
            {StatusCode::PRECONDITION_REQUIRED,           "428 Precondition Required"},
            {StatusCode::TOO_MANY_REQUEST,                "429 Too Many Requests"},
            {StatusCode::REQUEST_HEADER_FIELDS_TOO_LARGE, "431 Request Header Fields Too Large"},
            {StatusCode::UNAVAILABLE_FOR_LEGAL_REASONS,   "451 Unavailable For Legal Reasons"},
            {StatusCode::INTERNAL_SERVER_ERROR,           "500 Internal Server Error"},
            {StatusCode::NOT_IMPLEMENTED,                 "501 Not Implemented"},
            {StatusCode::BAD_GATEWAY,                     "502 Bad Gateway"},
            {StatusCode::SERVICE_UNAVAILABLE,             "503 Service Unavailable"},
            {StatusCode::GATEWAY_TIMEOUT,                 "504 Gateway Timeout"},
            {StatusCode::HTTP_VERSION_NOT_SUPPORTED,      "505 HTTP Version Not Supported"},
            {StatusCode::VARIANT_ALSO_NEGOTIATES,         "506 Variant Also Negotiates"},
            {StatusCode::INSUFFICIENT_STORAGE,            "507 Insufficient Storage"},
            {StatusCode::LOOP_DETECTED,                   "508 Loop Detected"},
            {StatusCode::NOT_EXTENDED,                    "510 Not Extended"},
            {StatusCode::NETWORK_AUTHENTICATION_REQUIRED, "511 Network Authentication Required"},
#ifdef SUPPORT_UNOFFICIAL_STATUS_CODE_ACTIVATED
            {StatusCode::CHECKPOINT,                      "103 Checkpoint"},
            {StatusCode::LOGIN_TIME_OUT,                  "440 Login Time-out"},
            {StatusCode::NO_RESPONSE,                     "444 No Response"},
            {StatusCode::RETRY_WITH,                      "449 Retry With"},
            {StatusCode::SSL_CERTIFICATE_ERROR,           "495 SSL Certificate Error"},
            {StatusCode::SSL_CERTIFICATE_REQUIRED,        "496 SSL Certificate Required"},
            {StatusCode::HTTP_REQUEST_SENT_TO_HTTPS_PORT, "497 HTTP Request Sent to HTTPS Port"},
            {StatusCode::CLIENT_CLOSED_REQUEST,           "499 Client Closed Request"},
            {StatusCode::BANDWIDTH_LIMIT_EXCEEDED,        "509 Bandwidth Limit Exceeded"},
            {StatusCode::UNKNOWN_ERROR,                   "520 Unknown Error"},
            {StatusCode::WEB_SERVER_IS_DOWN,              "521 Web Server Is Down"},
            {StatusCode::CONNECTION_TIMED_OUT,            "522 Connection Timed Out"},
            {StatusCode::ORIGIN_IS_UNREACHABLE,           "523 Origin Is Unreachable"},
            {StatusCode::A_TIMEOUT_OCCURRED,              "524 A Timeout Occurred"},
            {StatusCode::SSL_HANDSHAKE_FAILED,            "525 SSL Handshake Failed"},
            {StatusCode::INVALID_SSL_CERTIFICATE,         "526 Invalid SSL Certificate"},
            {StatusCode::SITE_IS_FROZEN,                  "530 Site is frozen"},
            {StatusCode::NETWORK_READ_TIMEOUT_ERROR,      "598 Network read timeout error"}
#endif // SUPPORT_UNOFFICIAL_STATUS_CODE_ACTIVATED
    };
}
