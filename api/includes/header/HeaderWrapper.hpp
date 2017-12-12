/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <vector>
#include <memory>

#include "Header.hpp"
#include "exception/Exception.hpp"

/**
 * @namespace Zia
 */
namespace Zia
{
    /**
     * Manage the Headers for the Request and Response class.
     * Just a simple container for the Headers.
     *
     * @class HeaderWrapper
     */
    class HeaderWrapper
    {
    private:
        std::vector<Header> _headers;

    public:
        /**
         * Constructor
         */
        HeaderWrapper() = default;

        /**
         * Destructor
         */
        virtual ~HeaderWrapper();

        /**
         * Render all headers
         *
         * @return
         */
        const std::string render();

        /**
         * Add the given Header to the current Header list
         *
         * @param header The Header to add.
         */
	inline void addHeader(const Header &header)
	{
	    this->_headers.push_back(header);
	}


	/**
         * Get the first Header in the list with a name corresponding to key.
         *
         * @param key The name of the Header to get.
         * @return
         */
	inline const Header &getHeader(const std::string &key) const
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

        /**
         * Get the vector of headers.
         *
         * @return The vector of Headers
         */
	inline const std::vector<Header> &getAllHeaders() const
	{
	    return this->_headers;
	}

		/**
		 * deleted member functions
		 */
	public:
		HeaderWrapper(HeaderWrapper const& other) = delete;
		HeaderWrapper const& operator>>(HeaderWrapper const& other) = delete;
    };

}
