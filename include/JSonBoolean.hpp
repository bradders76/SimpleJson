// *******************************************************
// JSonBoolean
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Boolean class
//

#ifndef JSON_BOOLEAN_HPP
#define JSON_BOOLEAN_HPP

#include "BaseItem.hpp"

namespace SimpleJSon
{
    class JSonBoolean :  public BaseJsonItem
    {
        private:
            bool m_value;
        
        public:

            explicit JSonBoolean(bool val);
        
            void GetValue(bool &val) override;
        
            std::string ToString(int depth, bool pretty) override;
            
    };
}

#endif

