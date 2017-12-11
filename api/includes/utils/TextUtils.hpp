//
// Created by sylva on 16/11/2017.
//

#pragma once

#include <vector>
#include <string>

namespace Zia
{
    /**
     * @namespace Utils
     */
    namespace Utils
    {
	/**
	 * @class TextUtils
	 */
        class TextUtils
        {
        public:
	    /**
	     * Concat all the elements separated by the separator
	     */
            static std::string join(const std::vector<std::string> &elements, const std::string &separator);

	    /**
	     * Split the string at every separator
	     */
            static std::vector<std::string> split(const std::string &s, const char separator);
        };
    }
}
