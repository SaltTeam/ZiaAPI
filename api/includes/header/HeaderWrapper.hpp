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
        HeaderWrapper();

	/**
	 * Destructor
	 */
        ~HeaderWrapper();

	/**
	 * Add the given Header to the current Header list
	 *
	 * @param header The Header to add.
	 */
        void addHeader(const Header &header);

	/**
	 * Get the first Header in the list with a name corresponding to key.
	 *
	 * @param key The name of the Header to get.
	 * @return
	 */
        const Header &getHeader(const std::string &key) const;

	/**
	 * Get the vector of headers.
	 *
	 * @return The vector of Headers
	 */
        const std::vector<Header> &getAllHeaders() const;
    };
}
