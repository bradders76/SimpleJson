#include <iostream>
#include <stdexcept>
#include <sstream>

#include "../include/JSon.hpp"

int main(int argc, const char * argv[])
{
    auto head = SimpleJSon::JsonProxy::CreateBlankHead();

    // test a simple reading of JSon item...

    std::string testString = R"(
        {
            "name": "John Doe",
            "age": 30,
            "isEmployed": true,
            "address": {
                "city": "New York",
                "postalCode": "10001"
            },
            "phoneNumbers": ["123-456-7890", "987-654-3210"]
        }
    )";

    try{
        // parse
        SimpleJSon::ParseJson(testString, head);

        // geta proxy handler, allows easy access of JSon object
        auto proxy = SimpleJSon::JsonProxy(head);

        proxy["phoneNumbers"][9]            = 1;
        proxy["phoneTest"]                  = "9999";

        auto val =  proxy["phoneNumbers"][0];
        val      = "123";

        // get entire JSon txt
        std::string str = proxy;
        std::cout << str  << std::endl;

        // output a one object, will output all child items
        str = proxy["phoneNumbers"];
        std::cout << str  << std::endl;


    }
   catch (std::exception &e)
   {
        std::cout << e.what() << std::endl;
   }


   return 0;
}
