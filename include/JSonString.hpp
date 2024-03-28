// *******************************************************
// JSonString
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon String class
//

#ifndef JSON_STRING_HPP
#define JSON_STRING_HPP

#include "BaseItem.hpp"
#include <string>
#include <mutex>

namespace SimpleJSon
{
    class JSonString :  public BaseJsonItem
    {
        private:
            std::mutex m_mtx;
            std::string m_value;

        public:
            explicit JSonString(std::string val);
        
            void GetValue(std::string &val) override;
            std::string ToString(int depth, bool pretty) override;
    };
}


#endif

