/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include <utility>

#include "request/Request.hpp"
#include "request/ConstRequest.hpp"

namespace Zia
{
    ConstRequest::ConstRequest(Request request)
    {
        this->_body = request.getBody();
        this->_headers = request.getHeaders();
        this->_httpVersion = request.getHttpVersion();
        this->_method = request.getMethod();
        this->_methodText = request.getMethodText();
        this->_params = request.getParams();
        this->_uri = request.getUri();
    }

    void  ConstRequest::operator>>(ConstRequest request) {
        this->_body = request.getBody();
        this->_headers = request.getHeaders();
        this->_httpVersion = request.getHttpVersion();
        this->_method = request.getMethod();
        this->_methodText = request.getMethodText();
        this->_params = request.getParams();
        this->_uri = request.getUri();
    }

    ConstRequest::ConstRequest(Request::Method method, std::string uri,
                               std::string httpVersion, std::string body)
    {
        this->_method = method;
        this->_uri = uri;
        this->_httpVersion = httpVersion;
        this->_body = body;
    }

    ConstRequest::ConstRequest(Request::Method method, std::string methodText,
                               std::string uri, std::string HttpVersion,
                               std::string body)
    {
        this->_body = body;
        this->_httpVersion = HttpVersion;
        this->_method = method;
        this->_methodText = methodText;
        this->_uri = uri;
    }

    ConstRequest::~ConstRequest()
    {}

    inline Request::Method ConstRequest::getMethod() const
    {
        return this->_method;
    }

    inline const std::string &ConstRequest::getMethodText() const
    {
        return this->_methodText;
    }

    inline const std::string &ConstRequest::getUri() const
    {
        return this->_uri;
    }

    inline const std::string &ConstRequest::getHttpVersion() const
    {
        return this->_httpVersion;
    }

    inline const HeaderWrapper &ConstRequest::getHeaders() const
    {
        return this->_headers;
    }

    inline const std::string &ConstRequest::getBody() const
    {
        return this->_body;
    }

    inline const std::map<std::string, std::string> &ConstRequest::getParams() const
    {
        return _params;
    }

#ifdef REQUEST_SETTERS
    void Request::setMethod(Request::Method method)
      { this->_method = method; }

      void Request::setMethodText(const std::string &methodText)
      { this->_methodText = methodText; }

      void Request::setUri(const std::string &uri)
      { this->_uri = uri; }

      void Request::setHttpVersion(const std::string &httpVersion)
      { this->_httpVersion = httpVersion; }

      void Request::setHeaders(const HeaderWrapper &headers)
      { this->_headers = headers; }

      void Request::setBody(const std::string &body)
      { this->_body = body; }
#endif // !REQUEST_SETTERS
}
