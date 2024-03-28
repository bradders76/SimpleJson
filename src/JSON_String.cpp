// *******************************************************
// JSON_String
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon string
//

#include "../include/JSON_String.hpp"
#include "../include/StringUtils.hpp"
// overkill and requires cpp 20
//#include <format>
#include <utility>
#include <string>

namespace SimpleJSon
{
    std::string JSON_String::ToString(int depth, bool pretty)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

       // return std::format("\"{}\"", StringUtils::StringToJsonString(m_value));
       return "\""+  StringUtils::StringToJsonString(m_value) + "\"";
    }

    JSON_String::JSON_String(std::string val): m_value(std::move(val)){}

    void JSON_String::GetValue(std::string &val){
        const std::lock_guard<std::mutex> lock(m_mtx);

        val = m_value;
    }
}

