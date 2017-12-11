/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 10/11/2017
 * @package Zia
 */

#include <algorithm>
#include <cctype>
#include <sstream>
#include <ostream>
#include <iostream>
#include <vector>
#include <utils/TextUtils.hpp>

#include "header/HeaderNormalizer.hpp"

namespace Zia
{
    void HeaderNormalizer::normalize(std::string &key, HeaderNormalizationType normalizationType)
    {
        if (normalizationType & HeaderNormalizationType::TRIM)
            trimNormalize(key);
        if (normalizationType & HeaderNormalizationType::DELIMITERS)
            delimitersNormalize(key);
        if (normalizationType & HeaderNormalizationType::CASE)
            caseNormalize(key);
        if (normalizationType & HeaderNormalizationType::CANONICAL)
            canonicalNormalize(key);
    }

    void HeaderNormalizer::trimNormalize(std::string &s)
    {
        // Trim from start
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch)
        {
            return !std::isspace(ch);
        }));
        // Trim from end
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch)
        {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    void HeaderNormalizer::delimitersNormalize(std::string &s)
    {
        std::replace(s.begin(), s.end(), ' ', '-');
        std::replace(s.begin(), s.end(), '_', '-');
    }

    void HeaderNormalizer::caseNormalize(std::string &s)
    {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    }

    void HeaderNormalizer::canonicalNormalize(std::string &s)
    {
        std::vector<std::string> result = Zia::Utils::TextUtils::split(s, '-');
        for (auto &item : result)
        {
            item[0] = (char) std::toupper(item[0]);
        }
        s = Zia::Utils::TextUtils::join(result, "-");
    }
}
