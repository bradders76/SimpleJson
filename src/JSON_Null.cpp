// *******************************************************
// JSON_Null
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Null class
//

#include "../include/JSON_Null.hpp"

namespace SimpleJSon
{
    std::string JSON_Null::ToString(int depth, bool pretty)
    {
        return "null";
    }

    std::optional<int> JSON_Null::AsInt()
    {
        return std::nullopt;
    }
    std::optional<unsigned int> JSON_Null::AsUint()
    {
        return std::nullopt;
    }
    std::optional<int64_t> JSON_Null::AsInt64()
    {
        return std::nullopt;
    }

    std::optional<double> JSON_Null::AsDouble()
    {
        return std::nullopt;
    }

    std::optional<bool> JSON_Null::AsBool()
    {
        return std::nullopt;
    }
    std::optional<std::string> JSON_Null::AsString()
    {
        return std::nullopt;
    }

}
