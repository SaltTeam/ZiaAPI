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
	inline const std::string &get() const
	{
	    return this->_content;
	}

        /**
         * Set the content to the new content.
         *
         * @param content The new content
         */
	inline void set(const std::string &content)
	{
	    this->_content = content;
	}

        /**
         * Prepend the actual content to the given string.
         *
         * @param content The data to prepend
         */
	inline void prepend(const std::string &content)
	{
	    this->_content = content + this->_content;
	}

        /**
         * Append the actual content to the given string.
         *
         * @param content The data to append
         */
	inline void append(const std::string &content)
	{
	    this->_content += content;
	}
    };
}
