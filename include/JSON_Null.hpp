// *******************************************************
// JSON_Null
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Null class
//

#ifndef JSON_NULL_HPP
#define JSON_NULL_HPP

#include "JSON_baseItem.hpp"

namespace SimpleJSon
{
    class JSON_Null : public JSON_BaseItem
    {
        public:
            std::string ToString(int depth, bool pretty) override;

            std::optional<int> AsInt()override;
            std::optional<unsigned int> AsUint() override;
            std::optional<int64_t> AsInt64() override;
            std::optional<double> AsDouble() override;
            std::optional<bool> AsBool() override;
            std::optional<std::string> AsString() override;

    };


}

#endif

