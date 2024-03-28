// *******************************************************
// JSON_UnitTest_StringUtils
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 28
//
// Simple Tests of SimpleJson::StringUtils functions
//

#include <gtest/gtest.h>
#include <string>
#include <memory>

#include "../include/StringUtils.hpp"

// Define a test fixture for parameterized tests
class WhiteSpaceTest : public testing::TestWithParam<std::tuple<unsigned char, bool>> {
};

// define Unicode Test
// string from , string to, no throw
class UnicodeTestStringToJson : public testing::TestWithParam<std::tuple<std::string, std::string, bool>> {
};
class UnicodeTestJsonToString : public testing::TestWithParam<std::tuple<std::string, std::string, bool>> {
};


TEST_P(WhiteSpaceTest,  WhiteSpaceFunctionTests) {
    // Get parameters from the test fixture
    auto [c, value] = GetParam();

    // Perform the test
    ASSERT_EQ(SimpleJSon::StringUtils::IsWhiteSpace(c), value);
}

TEST_P(UnicodeTestStringToJson, StringToJsonTests) {
    // Get parameters from the test fixture
    auto [str, json, nothrow] = GetParam();

    std::string json_convert;

    if(nothrow)
    {
       EXPECT_NO_THROW(json_convert = SimpleJSon::StringUtils::StringToJsonString(str));

        // Perform the test
        ASSERT_EQ(json_convert , json);
    }
    else
    {
  //      EXPECT_THROW(json_convert = SimpleJSon::StringUtils::StringToJsonString(str),std::runtime_error);
    }
}


TEST_P(UnicodeTestJsonToString, JsonToStringTests) {
    // Get parameters from the test fixture
    auto [str, json, nothrow] = GetParam();

    std::string string_convert;

    if(nothrow)
    {
        EXPECT_NO_THROW(string_convert = SimpleJSon::StringUtils::JsonStringToString(json));

        // Perform the test
        ASSERT_EQ(string_convert , str);
    }
    else
    {
        EXPECT_THROW(string_convert = SimpleJSon::StringUtils::JsonStringToString(json),std::runtime_error);
    }
}




// Define the parameters for the test cases
INSTANTIATE_TEST_SUITE_P(
    StringToJsonTests,                       // Test case name
    UnicodeTestStringToJson,                             // Test fixture
    testing::Values(                         // Parameter values
        std::make_tuple("a\u1003abcd", "a\\u1003abcd", true),
        std::make_tuple("\u1003abcd", "\\u1003abcd", true),
        std::make_tuple("\u1003abcd", "\\u1003abcd", true),
        std::make_tuple("", "", true)
    )
);


// Define the parameters for the test cases
INSTANTIATE_TEST_SUITE_P(
        JsonToStringTests,                       // Test case name
        UnicodeTestJsonToString,                 // Test fixture
        testing::Values(                         // Parameter values
                std::make_tuple("a\u1003abcd", "a\\u1003abcd", true),
                std::make_tuple("\u1003abcd", "\\u1003abcd", true),
                std::make_tuple("\u1003abcd", "\\u1003abcd", true),
                std::make_tuple("", "", true),
                std::make_tuple( "", "\\ukbcd", false)
        )
);


// Define the parameters for the test cases
INSTANTIATE_TEST_SUITE_P(
    WhiteSpaceFunctionTests,                   // Test case name
    WhiteSpaceTest,                            // Test fixture
    testing::Values(                           // Parameter values
        std::make_tuple('\n', true),        
        std::make_tuple('a', false),
        std::make_tuple('b', false)
    )
);
