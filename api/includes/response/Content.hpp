/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <string>

namespace Zia
{
    class Content
    {
    private:
        std::string _content;

    public:
        /**
         * Constructor.
         */
        Content();

        /**
         * Destructor.
         */
        ~Content();

        /**
         * Get the actual content.
         *
         * @return content
         */
        const std::string &get() const;

        /**
         * Set the content to the new content.
         *
         * @param content
         */
        void set(const std::string &content);

        /**
         * Prepend the actual content to the given string.
         *
         * @param content
         */
        void prepend(const std::string &content);

        /**
         * Append the actual content to the given string.
         *
         * @param content
         */
        void append(const std::string &content);
    };
}
