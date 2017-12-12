/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include "header/HeaderNormalizer.hpp"
#include "header/HeaderWrapper.hpp"

namespace Zia
{
    HeaderWrapper::HeaderWrapper()
    {}

    HeaderWrapper::~HeaderWrapper()
    {
        this->_headers.clear();
    }

    void HeaderWrapper::addHeader(const Header &header)
    {
        this->_headers.push_back(header);
    }

    const Header &HeaderWrapper::getHeader(const std::string &key) const
    {
        for (auto &header : _headers)
        {
            if (header.getKey() == key)
            {
                return header;
            }
        }
        throw std::exception();
    }

    const std::vector<Header> &HeaderWrapper::getAllHeaders() const
    {
        return this->_headers;
    }

    const std::string HeaderWrapper::render()
    {
        std::string str;

        for (const auto &header : this->_headers)
        {
            str += header.render(HeaderNormalizer::HeaderNormalizationType::ALL) + "\n";
        }
        return str;
    }
}
