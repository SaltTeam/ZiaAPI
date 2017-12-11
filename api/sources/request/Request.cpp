/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include "request/Request.hpp"

namespace Zia
{
    Request::Request()
            : _method(Method::CUSTOM), _methodText(""), _uri(""), _httpVersion(""), _headers(), _body("")
    {}

    Request::~Request()
    {}

    const std::map<const std::string, const Request::Method> Request::methodText = {
            {"GET",     Request::Method::GET},
            {"POST",    Request::Method::POST},
            {"PUT",     Request::Method::PUT},
            {"DELETE",  Request::Method::DELETE},
            {"PATCH",   Request::Method::PATCH},
            {"HEAD",    Request::Method::HEAD},
            {"OPTIONS", Request::Method::OPTIONS},
            {"CONNECT", Request::Method::CONNECT},
            {"TRACE",   Request::Method::TRACE}
    };

    Request::Method Request::getMethod()
    { return this->_method; }

     std::string &Request::getMethodText()
    { return this->_methodText; }

     std::string &Request::getUri()
    { return this->_uri; }

     std::string &Request::getHttpVersion()
    { return this->_httpVersion; }

     HeaderWrapper &Request::getHeaders()
    { return this->_headers; }

     std::string &Request::getBody()
    { return this->_body; }

    std::map<std::string, std::string> &Request::getParams()
    { return _params; }
}
