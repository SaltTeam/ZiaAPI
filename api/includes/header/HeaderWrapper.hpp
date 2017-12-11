/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <vector>

#include "Header.hpp"

namespace Zia
{
    class HeaderWrapper
    {
    private:
        std::vector<Header> _headers;

    public:
        HeaderWrapper();

        ~HeaderWrapper();

        void addHeader(const Header &header);

        const Header &getHeader(const std::string &key) const;

        const std::vector<Header> &getAllHeaders() const;
    };
}
