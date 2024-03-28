// *******************************************************
// JSonUtil
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Util class
//

#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <string>

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <cstdlib>


namespace SimpleJSon
{
    class StringUtils
    {
        public:
            static bool IsWhiteSpace(char c);

            static std::string LongToHexString(unsigned long decimalValue);

            static std::string Trim(const std::string &inString);

            static std::string JsonStringToString(const std::string &value);

            static std::string StringToJsonString(const std::string &value);

            static std::vector<std::string> Split(const std::string &string, char sep);
    };
}
#endif

