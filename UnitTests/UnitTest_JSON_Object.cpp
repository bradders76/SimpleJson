// *******************************************************
// JSON_UnitTest_Object
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - April - 1
//
// Created by Bradley Crouch on 01/04/2024.
//


#include <gtest/gtest.h>
#include <list>

#include "../include/JSON.hpp"


// Define a test fixture for parameterized tests
class ObjectTest : public testing::TestWithParam<std::list<std::string>> {
};



TEST_P(ObjectTest,  ToValueTest) {
    auto items = GetParam();

    std::map<std::string, int> random;

    SimpleJSon::JSON_Object objectItem;
    int cnt = 0;

    for(auto const &item:items)
    {
        random[item] = std::rand();

        objectItem.AddItem(item, std::make_shared<SimpleJSon::JSON_Number>(random[item]) );
    }

    for(auto const &item:items)
    {

        ASSERT_TRUE(objectItem.Exists(item));

        auto numberJson = std::dynamic_pointer_cast<SimpleJSon::JSON_Number> (objectItem[item]);

        ASSERT_TRUE(numberJson != nullptr);

        double value;
        numberJson->GetValue(value);
        ASSERT_EQ(value, random[item]);

    }
}


INSTANTIATE_TEST_SUITE_P(
        ObjectFunctionTests,                   // Test case name
        ObjectTest,                            // Test fixture
        testing::Values(                           // Parameter values
                std::list<std::string>
                {
                        "item1",
                        "item2",
                        "item3"
                },
                std::list<std::string>
                {
                        "item1",
                        "item2",
                        "item3"
                }
        )
);