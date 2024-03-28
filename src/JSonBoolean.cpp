// *******************************************************
// JSonBoolean
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Boolean class
//


#include "../include/JSonBoolean.hpp"

namespace SimpleJSon
{
    JSonBoolean::JSonBoolean(bool val): m_value(val){}

    void JSonBoolean::GetValue(bool &val){val = m_value;}

    std::string JSonBoolean::ToString(int depth, bool pretty)
    {
        return (m_value) ? "true" : "false";
    }
}
