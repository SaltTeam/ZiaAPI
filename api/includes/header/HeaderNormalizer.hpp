/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#pragma once

#include <string>

#include "Header.hpp"

/**
 * @namespace Zia
 */
namespace Zia
{
    /**
     * Normalization Type for your header name. You should never have to use it.
     *
     * @enum HeaderNormalizationType
     */
    enum HeaderNormalizationType : short
    {
        NONE = 0x0000,
        TRIM = 0x0001,
        DELIMITERS = 0x0010,
        CASE = 0x0100,
        CANONICAL = 0x1000,

        ALL = 0x1111
    };

    /**
     * Class dedicated to Header Name normalization.
     * You should never use this.
     * The Header class already use it.
     *
     * @class HeaderNormalizer
     */
    class HeaderNormalizer
    {
    public:
        /**
         * Normalize the header with the given normalization type.
         * By default ALL is selected.
         *
         * @param key A header name
         * @param normalizationType The normalization to apply to the header name
         */
        static void normalize(std::string &key, HeaderNormalizationType normalizationType = HeaderNormalizationType::ALL);

    private:
        static void trimNormalize(std::string &s);

        static void delimitersNormalize(std::string &s);

        static void caseNormalize(std::string &s);

        static void canonicalNormalize(std::string &s);
    };
}
