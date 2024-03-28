// *******************************************************
// JSON_String
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon String class
//

#ifndef JSON_STRING_HPP
#define JSON_STRING_HPP

#include "JSON_baseItem.hpp"
#include <string>
#include <mutex>

namespace SimpleJSon
{
    class JSON_String : public JSON_BaseItem
    {
        private:
            std::mutex m_mtx;
            std::string m_value;

        public:
            explicit JSON_String(std::string val);
        
            void GetValue(std::string &val) override;
            std::string ToString(int depth, bool pretty) override;
    };
}


#endif

