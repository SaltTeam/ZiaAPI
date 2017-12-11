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

namespace Zia
{
    /**
     * Status class which focus to handle the http response status.
     */
    class Status
    {
    public:
        /**
         * List of Http Status Code
         *
         * @see https://en.wikipedia.org/wiki/List_of_HTTP_status_codes
         */
        enum StatusCode : unsigned int
        {
            UNKNOWN                         = 0,
            /**
             * 1xx Informational responses
             */
            CONTINUE                        = 100,
            SWITCHING_PROTOCOLS             = 101,
            PROCESSING                      = 102,
            /**
             * 2xx Success
             */
            OK                              = 200,
            CREATED                         = 201,
            ACCEPTED                        = 202,
            NON_AUTHORITATIVE_INFORMATION   = 203,
            NO_CONTENT                      = 204,
            RESET_CONTENT                   = 205,
            PARTIAL_CONTENT                 = 206,
            MULTI_STATUS                    = 207,
            ALREADY_REPORTED                = 208,
            IM_USED                         = 226,
            /**
             * 3xx Redirection
             */
            MULTIPLE_CHOICES                = 300,
            MOVED_PERMANENTLY               = 301,
            FOUND                           = 302,
            SEE_OTHER                       = 302,
            NOT_MODIFIED                    = 303,
            USE_PROXY                       = 304,
            SWITCH_PROXY                    = 304,
            TEMPORARY_REDIRECT              = 305,
            PERMANENT_REDIRECT              = 306,
            /**
             * 4xx Client errors
             */
            BAD_REQUEST                     = 400,
            UNAUTHORIZED                    = 401,
            PAYEMENT_REQUIRED               = 402,
            FORBIDDEN                       = 403,
            NOT_FOUND                       = 404,
            METHOD_NOT_ALLOWED              = 405,
            NOT_ACCEPTABLE                  = 406,
            PROXY_AUTHENTICATION_REQUIRED   = 407,
            REQUEST_TIMEOUT                 = 408,
            CONFLICT                        = 409,
            GONE                            = 410,
            LENGHT_REQUIRED                 = 411,
            PRECONDITION_FAILED             = 412,
            PAYLOAD_TOO_LARGE               = 413,
            URI_TOO_LONG                    = 414,
            UNSUPPORTED_MEDIA_TYPE          = 415,
            RANGE_NOT_SATISFIABLE           = 416,
            EXPECTATION_FAILED              = 417,
            IM_A_TEAPOT                     = 418,
            MISDIRECTED_REQUEST             = 421,
            UNPROCESSABLE_ENTITY            = 422,
            LOCKED                          = 423,
            FAILED_DEPENDENCY               = 424,
            UPGRADE_REQUIRED                = 426,
            PRECONDITION_REQUIRED           = 428,
            TOO_MANY_REQUEST                = 429,
            REQUEST_HEADER_FIELDS_TOO_LARGE = 430,
            UNAVAILABLE_FOR_LEGAL_REASONS   = 451,
            /**
             * 5xx Server errors
             */
            INTERNAL_SERVER_ERROR           = 500,
            NOT_IMPLEMENTED                 = 501,
            BAD_GATEWAY                     = 502,
            SERVICE_UNAVAILABLE             = 503,
            GATEWAY_TIMEOUT                 = 504,
            HTTP_VERSION_NOT_SUPPORTED      = 505,
            VARIANT_ALSO_NEGOTIATES         = 506,
            INSUFFICIENT_STORAGE            = 507,
            LOOP_DETECTED                   = 508,
            NOT_EXTENDED                    = 510,
            NETWORK_AUTHENTICATION_REQUIRED = 511,
#ifdef SUPPORT_UNOFFICIAL_STATUS_CODE_ACTIVATED
            /**
            * Unofficial codes
            */
            CHECKPOINT                      = 103,
            LOGIN_TIME_OUT                  = 440,
            NO_RESPONSE                     = 444,
            RETRY_WITH                      = 449,
            SSL_CERTIFICATE_ERROR           = 495,
            SSL_CERTIFICATE_REQUIRED        = 496,
            HTTP_REQUEST_SENT_TO_HTTPS_PORT = 497,
            CLIENT_CLOSED_REQUEST           = 499,
            BANDWIDTH_LIMIT_EXCEEDED        = 509,
            UNKNOWN_ERROR                   = 520,
            WEB_SERVER_IS_DOWN              = 521,
            CONNECTION_TIMED_OUT            = 522,
            ORIGIN_IS_UNREACHABLE           = 523,
            A_TIMEOUT_OCCURRED              = 524,
            SSL_HANDSHAKE_FAILED            = 525,
            INVALID_SSL_CERTIFICATE         = 526,
            SITE_IS_FROZEN                  = 530,
            NETWORK_READ_TIMEOUT_ERROR      = 598
#endif // SUPPORT_UNOFFICIAL_STATUS_CODE_ACTIVATED
        };

        static const std::map<const unsigned int, const std::string> statusText;

    private:
        unsigned int _code;
        std::string _text;

    public:
        /**
         * Constructor.
         * Set the status to OK.
         */
        Status();

        /**
         * Constructor with standard code and text.
         *
         * @param code
         */
        Status(StatusCode code);

        /**
         * Destructor.
         */
        ~Status();

        /**
         * Set the status respecting the Http RFC.
         *
         * @param code
         */
        void setStandardStatus(StatusCode code);

        /**
         * Set the status with custom status code and status text.
         *
         * @param code
         * @param text
         */
        void setCustomStatus(unsigned int code, const std::string &text);

        /**
         * Get the actual status code.
         *
         * @return
         */
        unsigned int getCode() const;

        /**
         * Get the actual status text.
         *
         * @return
         */
        const std::string &getText() const;
    };
}
