// *******************************************************
// JSON_UnitTest_Proxy
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 28
//


#include <gtest/gtest.h>
#include <vector>
#include <variant>

#include "../include/JSON.hpp"

// Define a test fixture for parameterized tests
class ProxyTest : public testing::TestWithParam<std::tuple<std::string, std::vector<std::string>>> {
};



TEST_P(ProxyTest,  ForEachTest) {
    auto item = GetParam();

    std::map<std::string, int> random;

    SimpleJSon::JSON_Object objectItem;


    auto [json, requiredList] = GetParam();


    std::shared_ptr<SimpleJSon::JsonProxySettings>   settings = std::make_shared<SimpleJSon::JsonProxySettings>();
    auto head = SimpleJSon::JsonProxy::CreateBlankHead();
    // parse

    SimpleJSon::ParseJson(json, head);


    std::vector<std::string> list;
    unsigned short cnt = 0;
   auto fn =  [&list, &cnt](const SimpleJSon::JSONKey &key, std::shared_ptr<SimpleJSon::IJSON_Item> item){
       std::string  retVal;

       ASSERT_TRUE(std::holds_alternative<unsigned short>(key));

       if(std::holds_alternative<unsigned short>(key))
       {
           ASSERT_EQ( std::get<unsigned short>(key), cnt);
       }

       item->GetValue(retVal);
       list.push_back(retVal);
       cnt++;
   };

    head->for_each(fn);



    ASSERT_EQ(list.size(), requiredList.size());

    for(int i = 0; i < list.size() && i < requiredList.size(); i++)
    {
        ASSERT_EQ(list[i], requiredList[i]);
    }
}


INSTANTIATE_TEST_SUITE_P(
        ProxyTests,                                // Test case name
        ProxyTest,                                 // Test fixture
        testing::Values(                           // Parameter values
                std::make_tuple( R"(
                                      [
                                        "line1",
                                        "line2",
                                        "line3"
                                      ]
                                )",
                                 std::vector<std::string>{"line1","line2", "line3"})
        )
);