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


namespace SimpleJSon
{
    class JSON_Number : public JSON_BaseItem
    {
        private:
            double m_value;
        
        public:
            explicit JSON_Number(double val);

            void GetValue(double &val) override;
            
            std::string ToString(int depth, bool pretty) override;
    };
}


#endif

