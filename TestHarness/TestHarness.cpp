// *******************************************************
// TestHarness
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2025
//
// Simple TestHarness
//


#include <iostream>
#include <stdexcept>
#include <sstream>

#include "../include/JSON.hpp"

int main(int argc, const char * argv[])
{
    auto head = SimpleJSon::JsonProxy::CreateBlankHead();

    // test a simple reading of JSon item...

    std::string testString = R"(
        {
            "name":"\nJohn Doe","age": 30,
            "isEmployed": true,
            "address": {
                "city": "New York",
                "postalCode": "10001"
            },
            "phoneNumbers": ["123-456-7890", "987-654-3210"]
        }
    )";

    std::string testString2 = R"({"asset":{"generator":"a,b","version":"2.0"}})";

    try{
        std::shared_ptr<SimpleJSon::JsonProxySettings>   settings = std::make_shared<SimpleJSon::JsonProxySettings>();

        // parse
        SimpleJSon::ParseJson(testString2, head);
        std::cout << head << std::endl;

        // geta proxy handler, allows easy access of JSon object
        auto proxy = SimpleJSon::JsonProxy(head, settings);




        proxy["phoneNumbers"][9]            = 1;
        proxy["phoneTest"]                  = "9999";

        proxy["phoneTest2"]["test"]                  = "9999";
        auto val =  proxy["phoneNumbers"][0];
        val      = "123";

        // get entire JSon txt
        std::string str = proxy;
        std::cout << str  << std::endl;

        // output a one object, will output all child items
        str = proxy["phoneNumbers"];
        std::cout << str  << std::endl;


        settings->setBoolSetting(SimpleJSon::eAllowObjectCreation, true);

        proxy["phoneTest2"]["testbrad"]                  = "9999";

    }
   catch (std::exception &e)
   {
        std::cout << e.what() << std::endl;
   }


   return 0;
}
