//
// Created by sylva on 16/11/2017.
//

#pragma once

#include <vector>
#include <string>

namespace Zia
{
    namespace Utils
    {
        class TextUtils
        {
        public:
            static std::string join(const std::vector<std::string> &elements, const std::string &separator);

            static std::vector<std::string> split(const std::string &s, const char separator);
        };
    }
}
