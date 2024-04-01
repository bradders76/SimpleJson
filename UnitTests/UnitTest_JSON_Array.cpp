// *******************************************************
// JSON_UnitTest_Array
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - April - 1
//
// Created by Bradley Crouch on 01/04/2024.
//


#include <gtest/gtest.h>
#include <set>

#include "../include/JSON.hpp"


// Define a test fixture for parameterized tests
class ArrayTest : public testing::TestWithParam<std::set<int>> {
};



TEST_P(ArrayTest,  ToValueTest) {
    auto set = GetParam();

    std::map<int, int> random;

    SimpleJSon::JSON_Array arrayItem;
    int cnt = 0;

    for(int i = 0; i < 100; i++)
    {
        if(set.find(i) != set.end())
        {
            random[i] = std::rand();

            arrayItem.AddItem(i, std::make_shared<SimpleJSon::JSON_Number>(random[i]) );
        }
    }

    cnt = 0;
    for(int i = 0; i < 100; i++) {
        if (set.find(i) != set.end())
        {
            ASSERT_TRUE(arrayItem.Exists(i));
            auto item = std::dynamic_pointer_cast<SimpleJSon::JSON_Number> (arrayItem[i]);

            ASSERT_TRUE(item != nullptr);

            double value;
            item->GetValue(value);
            ASSERT_EQ(value, random[i]);
        }
        else
        {
             ASSERT_FALSE(arrayItem.Exists(i));
        }
    }


}


INSTANTIATE_TEST_SUITE_P(
        ArrayFunctionTests,                   // Test case name
        ArrayTest,                            // Test fixture
        testing::Values(                           // Parameter values
                std::set<int>
                {
                    1,2,3,4,10
                },
                std::set<int>
                {

                },
                std::set<int>
                {
                    0,1,2,3,4,10,12,99
                }
        )
);