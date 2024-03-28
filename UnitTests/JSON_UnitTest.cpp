#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <memory>

#include "../include/JSON.hpp"

#include "../include/StringUtils.hpp"

// Define a test fixture for parameterized tests
class WhiteSpaceTest : public testing::TestWithParam<std::tuple<unsigned char, bool>> {
};

class UnicodeTest : public testing::TestWithParam<std::tuple<std::string, std::string>> {
};

class MockJSonItem : public SimpleJSon::JSON_BaseItem {
public:
    MOCK_METHOD2(ToString, std::string(int depth, bool pretty));
    MOCK_METHOD1(GetValue, void(double &value));
    MOCK_METHOD1(GetValue, void(std::string &value));
    MOCK_METHOD1(GetValue, void(bool &value));
    MOCK_METHOD1(Exists, bool(unsigned short));
    MOCK_METHOD1(Exists, bool(const std::string&));
    
    MOCK_METHOD1(BracketOp, std::shared_ptr<SimpleJSon::IJSON_Item> & (unsigned short));
    MOCK_METHOD1(BracketOp, std::shared_ptr<SimpleJSon::IJSON_Item> &(const std::string&));
    

    std::shared_ptr<SimpleJSon::IJSON_Item>& operator[](unsigned short index){ return BracketOp(index);};
    std::shared_ptr<SimpleJSon::IJSON_Item>& operator[](const std::string& index){ return BracketOp(index);};
    
};

TEST_P(WhiteSpaceTest,  WhiteSpaceFunctionTests) {
    // Get parameters from the test fixture
    auto [c, value] = GetParam();
    

    // Perform the test
    ASSERT_EQ(SimpleJSon::StringUtils::IsWhiteSpace(c), value);
}

TEST_P(UnicodeTest, StringToJsonTests) {
    // Get parameters from the test fixture
    auto [str, json] = GetParam();
    

    auto json_convert = SimpleJSon::StringUtils::StringToJsonString(str);
    
    
    // Perform the test
    ASSERT_EQ(json_convert , json);
}


TEST(SimpeMockTest, TestMock)
{
   // MockJSonItem test;

    std::cout << std::string("\u1003abcd") << std::endl;
    std::cout <<      SimpleJSon::StringUtils::StringToJsonString(std::string("\u1003abcd")) << std::endl;
    
        EXPECT_THROW(SimpleJSon::StringUtils::JsonStringToString(std::string("\\ukbcd")), std::runtime_error);
        EXPECT_NO_THROW(SimpleJSon::StringUtils::JsonStringToString(std::string("\\u0123a")));
}

// Define the parameters for the test cases
INSTANTIATE_TEST_SUITE_P(
    StringToJsonTests,                             // Test case name
    UnicodeTest,                            // Test fixture
    testing::Values(                         // Parameter values
        std::make_tuple("a\u1003abcd", "a\\u1003abcd"),
        std::make_tuple("\u1003abcd", "\\u1003abcd"),
        std::make_tuple("", "" )
    )
);

// Define the parameters for the test cases
INSTANTIATE_TEST_SUITE_P(
    WhiteSpaceFunctionTests,                   // Test case name
    WhiteSpaceTest,                            // Test fixture
    testing::Values(                     // Parameter values
        std::make_tuple('\n', true),        
        std::make_tuple('a', false),
        std::make_tuple('b', false)
    )
);

