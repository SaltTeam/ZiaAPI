/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include "response/Content.hpp"

namespace Zia
{
    Content::Content()
            : _content("")
    {}

    Content::~Content()
    {}

    const std::string &Content::get() const
    { return this->_content; }

    void Content::set(const std::string &content)
    { this->_content = content; }

    void Content::prepend(const std::string &content)
    { this->_content = content + this->_content; }

    void Content::append(const std::string &content)
    { this->_content += content; }
}
