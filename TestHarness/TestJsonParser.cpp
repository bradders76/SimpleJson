// *******************************************************
// TestHarness
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 31
//
// Simple TestJsonParser
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
      "users": [
        {
          "id": 1,
          "name": "John Doe",
          "age": 30,
          "email": "john.doe@example.com",
          "address": {
            "street": "123 Main St",
            "city": "Anytown",
            "zipcode": "12345"
          }
        },
        {
          "id": 2,
          "name": "Jane Smith",
          "age": 25,
          "email": "jane.smith@example.com",
          "address": {
            "street": "456 Elm St",
            "city": "Othertown",
            "zipcode": "54321"
          }
        },
        {
          "id": 3,
          "name": "Bob Johnson",
          "age": 35,
          "email": "bob.johnson@example.com",
          "address": {
            "street": "789 Oak St",
            "city": "Somewhere",
            "zipcode": "67890"
          }
        },
        {
          "id": 4,
          "name": "Alice Williams",
          "age": 28,
          "email": "alice.williams@example.com",
          "address": {
            "street": "101 Pine St",
            "city": "Nowhere",
            "zipcode": "13579"
          }
        },
        {
          "id": 5,
          "name": "Michael Brown",
          "age": 40,
          "email": "michael.brown@example.com",
          "address": {
            "street": "202 Maple St",
            "city": "Everywhere",
            "zipcode": "24680"
          }
        }
      ]
    }
    )";

    try{
        // parse
        SimpleJSon::ParseJson(testString, head);

        // get user number 2 (id 3)
        auto proxy = SimpleJSon::JsonProxy(head);
        auto item =  proxy["users"][2];

        std::cout << item;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}
