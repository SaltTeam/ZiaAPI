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
