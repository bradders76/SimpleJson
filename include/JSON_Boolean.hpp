// *******************************************************
// JSON_Boolean
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Boolean class
//

#ifndef JSON_BOOLEAN_HPP
#define JSON_BOOLEAN_HPP

#include "JSON_baseItem.hpp"

namespace SimpleJSon
{
    class JSON_Boolean : public JSON_BaseItem
    {
        private:
            bool m_value;
        
        public:
            explicit JSON_Boolean(bool val);
        
            void GetValue(bool &val) override;
        
            std::string ToString(int depth, bool pretty) override;
    };
}

#endif

