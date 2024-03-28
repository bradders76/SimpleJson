// *******************************************************
// JSON_Boolean
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Boolean class
//


#include "../include/JSON_Boolean.hpp"

namespace SimpleJSon
{
    JSON_Boolean::JSON_Boolean(bool val): m_value(val){}

    void JSON_Boolean::GetValue(bool &val){ val = m_value;}

    std::string JSON_Boolean::ToString(int depth, bool pretty)
    {
        return (m_value) ? "true" : "false";
    }
}
