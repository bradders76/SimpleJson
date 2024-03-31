Overview

SimpleJSon is a C++ library that provides functionality for handling JSON objects and arrays with ease. It offers functions for parsing JSON strings and constructing JSON objects or arrays accordingly.

Installation

To use SimpleJSon in your project, simply include the necessary headers and link against the library.

cpp
Copy code
#include "JsonParser.h"
// Include other necessary headers
Features

ParseJson Function
The ParseJson function parses a JSON string and constructs a corresponding JSON object or array.

Function Signature

cpp
Copy code
void ParseJson(std::string inString, std::shared_ptr<IJSON_Item> &head);
Parameters

inString: The JSON string to parse.
head: A reference to a pointer to the head of the JSON structure being constructed.
Example Usage

cpp
Copy code
#include "JsonParser.h"
#include <iostream>

using namespace SimpleJSon;

int main() {
    // JSON string to parse
    std::string jsonString = "{\"name\":\"John\",\"age\":30}";

    // Parse JSON string
    std::shared_ptr<IJSON_Item> jsonObject;
    ParseJson(jsonString, jsonObject);

    // Use the parsed JSON object
    if (jsonObject) {
        // Print the JSON object
        std::cout << "Parsed JSON:\n" << *jsonObject << std::endl;
    } else {
        std::cerr << "Failed to parse JSON." << std::endl;
    }

    return 0;
}


Overview

SimpleJSon is a C++ library that provides functionality for handling JSON objects and arrays with ease. It offers a JsonProxy class that serves as a convenient proxy for interacting with JSON data.

Installation

To use SimpleJSon in your project, simply include the necessary headers and link against the library.

cpp
Copy code
#include "JsonProxy.h"
// Include other necessary headers
Features

JsonProxy Class
The JsonProxy class provides a flexible interface for manipulating JSON objects and arrays. It allows you to perform various operations such as accessing elements by key or index, assigning values, and converting JSON data to a string.

Constructors

JsonProxy(std::shared_ptr<IJSON_Item> item, std::shared_ptr<JsonProxySettings> settings)
JsonProxy(std::shared_ptr<IJSON_Item> item, std::shared_ptr<JSON_Object> parentObject, std::shared_ptr<JsonProxySettings> settings, std::string parentKey)
JsonProxy(std::shared_ptr<IJSON_Item> item, std::shared_ptr<JSON_Array> parentArray, std::shared_ptr<JsonProxySettings> settings, unsigned short parentIndex)
Operators

operator=(const std::shared_ptr<IJSON_Item>& jsonItem)
operator[](const std::string& key)
operator[](unsigned short index)
Methods

std::shared_ptr<IJSON_Item> GetItem() const: Returns the underlying JSON item.
operator std::string() const: Converts the JSON item to a string.
void UpdateParentWithCurrentItem(): Updates the parent object or array with the current JSON item.
Example Usage

cpp
Copy code
#include "JsonProxy.h"
#include <iostream>

using namespace SimpleJSon;

int main() {
    // Create a JSON object
    auto jsonObject = std::make_shared<JSON_Object>();
    
    // Create a JsonProxy for the JSON object
    JsonProxy proxy(jsonObject, nullptr);
    
    // Add key-value pairs
    proxy["name"] = "John";
    proxy["age"] = 30;
    
    // Convert JSON object to string
    std::string jsonString = proxy;
    std::cout << "JSON Object:\n" << jsonString << std::endl;
    
    return 0;
}
