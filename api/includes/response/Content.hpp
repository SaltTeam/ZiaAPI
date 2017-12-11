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
    /**
     * The content (body) of the response with some utils added.
     *
     * @class Content
     */
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
         * @return content The actual content
         */
        const std::string &get() const;

        /**
         * Set the content to the new content.
         *
         * @param content The new content
         */
        void set(const std::string &content);

        /**
         * Prepend the actual content to the given string.
         *
         * @param content The data to prepend
         */
        void prepend(const std::string &content);

        /**
         * Append the actual content to the given string.
         *
         * @param content The data to append
         */
        void append(const std::string &content);
    };
}
