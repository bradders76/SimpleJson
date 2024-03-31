// *******************************************************
// JSON_UnitTest_String
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 28
//
// Created by Bradley Crouch on 28/03/2024.
//


#include <gtest/gtest.h>

#include "../include/JSON.hpp"


// Define a test fixture for parameterized tests
class StringTest : public testing::TestWithParam<std::tuple<std::string,std::string>> {
};


TEST_P(StringTest,  ToStringTest)
{
    auto [str, value] = GetParam();

    SimpleJSon::JSON_String stringItem(str);

    ASSERT_EQ(stringItem.ToString(0, false),value);
    ASSERT_EQ(stringItem.ToString(0, true),value);
    ASSERT_EQ(stringItem.ToString(1, false),value);
    ASSERT_EQ(stringItem.ToString(1, true),value);
}

TEST_P(StringTest,  ToValueTest)
{
    auto [str, value] = GetParam();

    SimpleJSon::JSON_String stringItem(str);

    std::string val;
    stringItem.GetValue(val);

    ASSERT_EQ(val,str);
}



INSTANTIATE_TEST_SUITE_P(
        StringFunctionTests,                   // Test case name
        StringTest,                            // Test fixture
        testing::Values(                           // Parameter values
                std::make_tuple("a\u1003abcd", "\"a\\u1003abcd\""),
                std::make_tuple("\u1003abcd", "\"\\u1003abcd\""),
                std::make_tuple("\u1003abcd", "\"\\u1003abcd\"")
        )
);