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

#include "utils/TextUtils.hpp"
#include "header/HeaderNormalizer.hpp"

namespace Zia
{
    namespace HeaderNormalizer
    {
        void trimNormalize(std::string &s)
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

        void delimitersNormalize(std::string &s)
        {
            std::replace(s.begin(), s.end(), ' ', '-');
            std::replace(s.begin(), s.end(), '_', '-');
        }

        void caseNormalize(std::string &s)
        {
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        }

        void canonicalNormalize(std::string &s)
        {
            std::vector<std::string> result = Zia::Utils::TextUtils::split(s, '-');
            for (auto &item : result)
            {
                item[0] = (char) std::toupper(item[0]);
            }
            s = Zia::Utils::TextUtils::join(result, "-");
        }

        void normalize(std::string &key, HeaderNormalizationType normalizationType)
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
    }
}
