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

    const std::string Status::render()
    {
        return std::to_string(this->getCode()) + " " + this->getText();
    }

    const std::map<const unsigned int, const std::string> Status::statusText = {
            {StatusCode::UNKNOWN,                         ""},
            {StatusCode::CONTINUE,                        "Continue"},
            {StatusCode::SWITCHING_PROTOCOLS,             "Switching Protocols"},
            {StatusCode::PROCESSING,                      "Processing"},
            {StatusCode::OK,                              "OK"},
            {StatusCode::CREATED,                         "Created"},
            {StatusCode::ACCEPTED,                        "ACCEPTED"},
            {StatusCode::NON_AUTHORITATIVE_INFORMATION,   "Non-Authoritative Information"},
            {StatusCode::NO_CONTENT,                      "No Content"},
            {StatusCode::RESET_CONTENT,                   "Reset Content"},
            {StatusCode::PARTIAL_CONTENT,                 "Partial Content"},
            {StatusCode::MULTI_STATUS,                    "Multi-Status"},
            {StatusCode::ALREADY_REPORTED,                "Already Reported"},
            {StatusCode::IM_USED,                         "IM Used"},
            {StatusCode::MULTIPLE_CHOICES,                "Multiple Choices"},
            {StatusCode::MOVED_PERMANENTLY,               "Moved Permanently"},
            {StatusCode::FOUND,                           "Found"},
            {StatusCode::SEE_OTHER,                       "See Other"},
            {StatusCode::NOT_MODIFIED,                    "Not Modified"},
            {StatusCode::USE_PROXY,                       "Use Proxy"},
            {StatusCode::SWITCH_PROXY,                    "Switch Proxy"},
            {StatusCode::TEMPORARY_REDIRECT,              "Temporary Redirect"},
            {StatusCode::PERMANENT_REDIRECT,              "Permanent Redirect"},
            {StatusCode::BAD_REQUEST,                     "Bad Request"},
            {StatusCode::UNAUTHORIZED,                    "Unauthorized"},
            {StatusCode::PAYEMENT_REQUIRED,               "Payment Required"},
            {StatusCode::FORBIDDEN,                       "Forbidden"},
            {StatusCode::NOT_FOUND,                       "Not Found"},
            {StatusCode::METHOD_NOT_ALLOWED,              "Method Not Allowed"},
            {StatusCode::NOT_ACCEPTABLE,                  "Not Acceptable"},
            {StatusCode::PROXY_AUTHENTICATION_REQUIRED,   "Proxy Authentication Required"},
            {StatusCode::REQUEST_TIMEOUT,                 "Request Timeout"},
            {StatusCode::CONFLICT,                        "Conflict"},
            {StatusCode::GONE,                            "Gone"},
            {StatusCode::LENGHT_REQUIRED,                 "Length Required"},
            {StatusCode::PRECONDITION_FAILED,             "Precondition Failed"},
            {StatusCode::PAYLOAD_TOO_LARGE,               "Payload Too Large"},
            {StatusCode::URI_TOO_LONG,                    "URI Too Long"},
            {StatusCode::UNSUPPORTED_MEDIA_TYPE,          "Unsupported Media Type"},
            {StatusCode::RANGE_NOT_SATISFIABLE,           "Range Not Satisfiable"},
            {StatusCode::EXPECTATION_FAILED,              "Expectation Failed"},
            {StatusCode::IM_A_TEAPOT,                     "I'm a teapot"},
            {StatusCode::MISDIRECTED_REQUEST,             "Misdirected Request"},
            {StatusCode::UNPROCESSABLE_ENTITY,            "Unprocessable Entity"},
            {StatusCode::LOCKED,                          "Locked"},
            {StatusCode::FAILED_DEPENDENCY,               "Failed Dependency"},
            {StatusCode::UPGRADE_REQUIRED,                "Upgrade Required"},
            {StatusCode::PRECONDITION_REQUIRED,           "Precondition Required"},
            {StatusCode::TOO_MANY_REQUEST,                "Too Many Requests"},
            {StatusCode::REQUEST_HEADER_FIELDS_TOO_LARGE, "Request Header Fields Too Large"},
            {StatusCode::UNAVAILABLE_FOR_LEGAL_REASONS,   "Unavailable For Legal Reasons"},
            {StatusCode::INTERNAL_SERVER_ERROR,           "Internal Server Error"},
            {StatusCode::NOT_IMPLEMENTED,                 "Not Implemented"},
            {StatusCode::BAD_GATEWAY,                     "Bad Gateway"},
            {StatusCode::SERVICE_UNAVAILABLE,             "Service Unavailable"},
            {StatusCode::GATEWAY_TIMEOUT,                 "Gateway Timeout"},
            {StatusCode::HTTP_VERSION_NOT_SUPPORTED,      "HTTP Version Not Supported"},
            {StatusCode::VARIANT_ALSO_NEGOTIATES,         "Variant Also Negotiates"},
            {StatusCode::INSUFFICIENT_STORAGE,            "Insufficient Storage"},
            {StatusCode::LOOP_DETECTED,                   "Loop Detected"},
            {StatusCode::NOT_EXTENDED,                    "Not Extended"},
            {StatusCode::NETWORK_AUTHENTICATION_REQUIRED, "Network Authentication Required"},
#ifdef SUPPORT_UNOFFICIAL_STATUS_CODE_ACTIVATED
            {StatusCode::CHECKPOINT,                      "Checkpoint"},
            {StatusCode::LOGIN_TIME_OUT,                  "Login Time-out"},
            {StatusCode::NO_RESPONSE,                     "No Response"},
            {StatusCode::RETRY_WITH,                      "Retry With"},
            {StatusCode::SSL_CERTIFICATE_ERROR,           "SSL Certificate Error"},
            {StatusCode::SSL_CERTIFICATE_REQUIRED,        "SSL Certificate Required"},
            {StatusCode::HTTP_REQUEST_SENT_TO_HTTPS_PORT, "HTTP Request Sent to HTTPS Port"},
            {StatusCode::CLIENT_CLOSED_REQUEST,           "Client Closed Request"},
            {StatusCode::BANDWIDTH_LIMIT_EXCEEDED,        "Bandwidth Limit Exceeded"},
            {StatusCode::UNKNOWN_ERROR,                   "Unknown Error"},
            {StatusCode::WEB_SERVER_IS_DOWN,              "Web Server Is Down"},
            {StatusCode::CONNECTION_TIMED_OUT,            "Connection Timed Out"},
            {StatusCode::ORIGIN_IS_UNREACHABLE,           "Origin Is Unreachable"},
            {StatusCode::A_TIMEOUT_OCCURRED,              "A Timeout Occurred"},
            {StatusCode::SSL_HANDSHAKE_FAILED,            "SSL Handshake Failed"},
            {StatusCode::INVALID_SSL_CERTIFICATE,         "Invalid SSL Certificate"},
            {StatusCode::SITE_IS_FROZEN,                  "Site is frozen"},
            {StatusCode::NETWORK_READ_TIMEOUT_ERROR,      "Network read timeout error"}
#endif // SUPPORT_UNOFFICIAL_STATUS_CODE_ACTIVATED
    };
}
