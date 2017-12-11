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

    Request::Method Request::getMethod() const
    { return this->_method; }

    const std::string &Request::getMethodText() const
    { return this->_methodText; }

    const std::string &Request::getUri() const
    { return this->_uri; }

    const std::string &Request::getHttpVersion() const
    { return this->_httpVersion; }

    const HeaderWrapper &Request::getHeaders() const
    { return this->_headers; }

    const std::string &Request::getBody() const
    { return this->_body; }

    std::map<std::string, std::string> &Request::getParams()
    { return _params; }
}
