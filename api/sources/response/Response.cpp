/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include "header/HeaderNormalizer.hpp"
#include "response/Response.hpp"

namespace Zia
{
    Response::Response()
    {}

    Response::Response(Response &other)
    {
        this->_content = other.getContent();
        this->_status = other.getStatus();
        this->_headers = other.getHeaders();
    }

    Response::~Response()
    {}

    Content &Response::getContent()
    {
        return this->_content;
    }

    Status &Response::getStatus()
    {
        return this->_status;
    }

    HeaderWrapper &Response::getHeaders()
    {
        return this->_headers;
    }

    void Response::addHeader(const Header &header)
    {
        _headers.addHeader(header);
    }

    void Response::setContent(const Content &content)
    {
        this->_content = content;
    }

    void Response::setStatus(const Status &status)
    {
        this->_status = status;
    }

    void Response::setHeaders(const HeaderWrapper &headers)
    {
        this->_headers = headers;
    }

    std::string &Response::getHttpVersion()
    {
        return this->_httpVersion;
    }

    void Response::setHttpVersion(const std::string &httpVersion)
    {
        this->_httpVersion = httpVersion;
    }

    const std::string Response::render(bool setAutoLength)
    {
        std::string str;

        str = this->getHttpVersion() + " " + this->getStatus().render() + "\n";
        if (setAutoLength)
        {
            this->getHeaders().addHeader(
                    Header{Header::ResponseHeader::CONTENT_LENGTH, std::to_string(this->getContent().get().length())});
        }
        str += this->getHeaders().render() + "\n";
        str += this->getContent().get();

        return str;
    }
}
