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



    void JSON_Number::GetValue(double &val)
    {
        std::visit([&val](auto&& v) {
            val = static_cast<double>(v);
        }, m_value);
    }

    void JSON_Number::GetValue(int64_t &val)
    {
        std::visit([&val](auto&& v) {
            if constexpr (std::is_same_v<decltype(v), int64_t>) {
                val = v;
            } else {
                if (std::floor(v) != v)
                    throw std::runtime_error("Floating-point value is not an integer");
                if (v > static_cast<double>(std::numeric_limits<unsigned int>::max()) ||
                    v < static_cast<double>(std::numeric_limits<unsigned int>::min()))
                    throw std::runtime_error("Floating-point value out of int range");
                val = static_cast<int>(v);
            }
        }, m_value);

    }

    void JSON_Number::GetValue(unsigned int &val)
    {
        std::visit([&val](auto&& v) {
            if constexpr (std::is_same_v<decltype(v), int64_t>) {
                if (v > std::numeric_limits<unsigned int>::max() || v < std::numeric_limits<unsigned int>::min())
                    throw std::runtime_error("Value out of unsigned it range");
                val = static_cast<int>(v);
            } else {
                if (std::floor(v) != v)
                    throw std::runtime_error("Floating-point value is not an unsigned integer");
                if (v > static_cast<double>(std::numeric_limits<unsigned int>::max()) ||
                    v < static_cast<double>(std::numeric_limits<unsigned int>::min()))
                    throw std::runtime_error("Floating-point value out of unsigned int range");
                val = static_cast<int>(v);
            }
        }, m_value);
    }


    void JSON_Number::GetValue(int &val)
    {
        std::visit([&val](auto&& v) {
            if constexpr (std::is_same_v<decltype(v), int64_t>) {
                if (v > std::numeric_limits<int>::max() || v < std::numeric_limits<int>::min())
                    throw std::runtime_error("Value out of unsigned it range");
                val = static_cast<int>(v);
            } else {
                if (std::floor(v) != v)
                    throw std::runtime_error("Floating-point value is not an integer");
                if (v > static_cast<double>(std::numeric_limits<int>::max()) ||
                    v < static_cast<double>(std::numeric_limits<int>::min()))
                    throw std::runtime_error("Floating-point value out of int range");
                val = static_cast<int>(v);
            }
        }, m_value);
    }

    std::string JSON_Number::ToString(int depth, bool pretty)
    {
        return std::visit([](auto&& v) -> std::string {
            return std::to_string(v);
        }, m_value);
    }

    std::optional<int> JSON_Number::AsInt()
    {
        int val;
        GetValue(val);
        return val;
    }
    std::optional<unsigned int> JSON_Number::AsUint()
    {
        unsigned int val;
        GetValue(val);
        return val;
    }
    std::optional<int64_t > JSON_Number::AsInt64()
    {
        int64_t val;
        GetValue(val);
        return val;
    }
    std::optional<double> JSON_Number::AsDouble()
    {
        double val;
        GetValue(val);
        return val;
    }
}
