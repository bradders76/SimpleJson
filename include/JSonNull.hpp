// *******************************************************
// JSonNull
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Null class
//

#ifndef JSON_NULL_HPP
#define JSON_NULL_HPP

#include "BaseItem.hpp"

namespace SimpleJSon
{
    class JSonNull : public BaseJsonItem
    {
        public:
            std::string ToString(int depth, bool pretty) override;
    };
}

#endif

