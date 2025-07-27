// JSON_UnitTest_Null
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 28
//
// Created by Bradley Crouch on 28/03/2024.
//

#include <gtest/gtest.h>
#include <memory>

#include "../include/JSON.hpp"


TEST(JSON_Null_ClassTest,  ToStringTest)
{
    SimpleJSon::JSON_Null nullItem;

    ASSERT_EQ(nullItem.ToString(0, false), "null");
    ASSERT_EQ(nullItem.ToString(1, false), "null");
}
