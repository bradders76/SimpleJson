// *******************************************************
// JSonNumber
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Number class
//

#ifndef JSON_NUMBER_HPP
#define JSON_NUMBER_HPP

#include "BaseItem.hpp"


namespace SimpleJSon
{
    class JSonNumber :  public BaseJsonItem
    {
        private:
            double m_value;
        
        public:
            explicit JSonNumber(double val);

            void GetValue(double &val) override;
            
            std::string ToString(int depth, bool pretty) override;
    };
}


#endif

