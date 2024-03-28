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
    };
}

#endif

