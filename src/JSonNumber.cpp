// *******************************************************
// JSonNumber
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Number class
//

#include "../include/JSonNumber.hpp"

namespace SimpleJSon
{
    JSonNumber::JSonNumber(double val): m_value(val)
    {

    }

    void JSonNumber::GetValue(double &val){val = m_value;}

    std::string JSonNumber::ToString(int depth, bool pretty)
    {
        return std::to_string(m_value);
    }
}
