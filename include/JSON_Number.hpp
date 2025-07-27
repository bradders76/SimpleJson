// *******************************************************
// JSON_Number
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Number class
//

#ifndef JSON_NUMBER_HPP
#define JSON_NUMBER_HPP

#include "JSON_baseItem.hpp"
#include <variant>

namespace SimpleJSon
{
    class JSON_Number : public JSON_BaseItem
    {
        private:
            std::variant<int64_t, double> m_value;
        
        public:

            explicit JSON_Number(int64_t val) : m_value(val) {}
            explicit JSON_Number(double val) : m_value(val) {}
            explicit JSON_Number(int val) : m_value(static_cast<int64_t>(val)) {}
            explicit JSON_Number(unsigned int val) : m_value(static_cast<int64_t>(val)) {}

            void GetValue(double &val) override;
            void GetValue(int64_t &val) override;
            void GetValue(int &val) override;
            void GetValue(unsigned int &val) override;

            std::string ToString(int depth, bool pretty) override;
    };
}


#endif

