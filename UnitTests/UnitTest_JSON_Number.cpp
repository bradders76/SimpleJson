// JSON_UnitTest_Number
// *******************************************************
//
// Created by Bradley Crouch on 28/03/2024.
//

#include <gtest/gtest.h>

#include "../include/JSON.hpp"


// Define a test fixture for parameterized tests
class NumberTest : public testing::TestWithParam<std::tuple<std::string, double>> {
};


TEST_P(NumberTest,  ToStringTest)
{
    auto [str, value] = GetParam();

    SimpleJSon::JSON_Number numberItem(value);

    auto strValue = numberItem.ToString(0, false);

    ASSERT_EQ(numberItem.ToString(0, true),strValue);
    ASSERT_EQ(numberItem.ToString(1, false),strValue);


    auto strDouble = stod(strValue);

    ASSERT_DOUBLE_EQ(strDouble, value);

}


TEST_P(NumberTest,  ToValueTest)
{
    auto [str, value] = GetParam();

    SimpleJSon::JSON_Number numberItem(value);

    double val;
    numberItem.GetValue(val);

    ASSERT_DOUBLE_EQ( value, val);

}


INSTANTIATE_TEST_SUITE_P(
        NumberFunctionTests,                   // Test case name
        NumberTest,                            // Test fixture
        testing::Values(                           // Parameter values
                std::make_tuple("1.1", 1.1),
                std::make_tuple("2", 2),
                std::make_tuple("-2.1", -2.1)
        )
);