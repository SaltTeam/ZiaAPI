//
// Created by sylva on 16/11/2017.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>

#include "utils/TextUtils.hpp"

namespace Zia
{
    namespace Utils
    {
        std::string TextUtils::join(const std::vector<std::string> &elements, const std::string &separator)
        {
            switch (elements.size())
            {
                case 0:
                    return "";
                case 1:
                    return elements[0];
                default:
                    std::ostringstream os;
                    std::copy(elements.begin(), elements.end() - 1,
                              std::ostream_iterator<std::string>(os, separator.c_str()));
                    os << *elements.rbegin();
                    return os.str();
            }
        }

        std::vector<std::string> TextUtils::split(const std::string &s, const char separator)
        {
            std::vector<std::string> result;

            std::string::const_iterator cur = s.begin();
            std::string::const_iterator beg = s.begin();
            bool added = false;
            while (cur < s.end())
            {
                if (*cur == separator)
                {
                    if (!added)
                    {
                        added = true;
                        result.insert(result.end(), std::string(beg, cur));
                    }
                    beg = ++cur;
                }
                else
                {
                    added = false;
                    cur++;
                }
            }
            result.insert(result.end(), std::string(beg, cur));
            return result;
        }
    }
}
