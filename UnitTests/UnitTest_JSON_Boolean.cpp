//
// Created by Bradley Crouch on 28/03/2024.
//

#include <gtest/gtest.h>

#include "../include/JSON.hpp"


// Define a test fixture for parameterized tests
class BooleanTest : public testing::TestWithParam<std::tuple<std::string, bool>> {
};


TEST_P(BooleanTest,  ToStringTest)
{
    auto [str, value] = GetParam();

    SimpleJSon::JSON_Boolean boolItem(value);

    ASSERT_EQ(boolItem.ToString(0, false),str);
    ASSERT_EQ(boolItem.ToString(0, false),str);
    ASSERT_EQ(boolItem.ToString(1, true),str);
    ASSERT_EQ(boolItem.ToString(1, true),str);
}


INSTANTIATE_TEST_SUITE_P(
        BooleanFunctionTests,                   // Test case name
        BooleanTest,                            // Test fixture
        testing::Values(                           // Parameter values
                std::make_tuple("true", true),
                std::make_tuple("false", false)
        )
);