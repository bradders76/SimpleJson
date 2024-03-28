// *******************************************************
// JSON_Number
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Number class
//

#include "../include/JSON_Number.hpp"

namespace SimpleJSon
{
    JSON_Number::JSON_Number(double val): m_value(val)
    {

    }

    void JSON_Number::GetValue(double &val){ val = m_value;}

    std::string JSON_Number::ToString(int depth, bool pretty)
    {
        return std::to_string(m_value);
    }
}
