# SimpleJSon

## Overview

SimpleJSon is a C++ library that provides functionality for handling JSON objects and arrays with ease. It offers classes and functions for parsing JSON strings, constructing JSON objects or arrays, and configuring proxy settings for JSON manipulation.

Currently this is a new library and features will be added.

## Installation

To use SimpleJSon in your project, simply include the necessary headers and link against the library.

```cpp
Copy code
#include "JsonParser.h"
#include "JsonProxy.h"
#include "JsonProxySettings.h"
// Include other necessary headers
```

## Features

## ParseJson Function

The ParseJson function parses a JSON string and constructs a corresponding JSON object or array.

**Function Signature**

```cpp
Copy code
void ParseJson(std::string inString, std::shared_ptr<IJSON_Item> &head);
```
**Parameters**

* inString: The JSON string to parse.
* head: A reference to a pointer to the head of the JSON structure being constructed.

## JsonProxy Class


The JsonProxy class provides a flexible interface for manipulating JSON objects and arrays. It allows you to perform various operations such as accessing elements by key or index, assigning values, and converting JSON data to a string.

**Constructors**

* JsonProxy(std::shared_ptr<IJSON_Item> item, std::shared_ptr<JsonProxySettings> settings)
* JsonProxy(std::shared_ptr<IJSON_Item> item, std::shared_ptr<JSON_Object> parentObject, std::shared_ptr<JsonProxySettings> settings, std::string parentKey)
* JsonProxy(std::shared_ptr<IJSON_Item> item, std::shared_ptr<JSON_Array> parentArray, std::shared_ptr<JsonProxySettings> settings, unsigned short parentIndex)

**Operators**

* operator=(const std::shared_ptr<IJSON_Item>& jsonItem)
* operator[](const std::string& key)
* operator[](unsigned short index)

**Methods**

* std::shared_ptr<IJSON_Item> GetItem() const: Returns the underlying JSON item.
* operator std::string() const: Converts the JSON item to a string.
* void UpdateParentWithCurrentItem(): Updates the parent object or array with the current JSON item.

## JsonProxySettings Class

The JsonProxySettings class allows you to configure settings for JSON proxy operations.

**Constructors**

* JsonProxySettings(bool allowCreation = true): Constructs a JsonProxySettings object with default settings.

**Methods**

* bool getBoolSetting(eJsonProxyOptions option): Gets the boolean value of the specified proxy option.
* void setBoolSetting(eJsonProxyOptions option, bool value): Sets the boolean value of the specified proxy option.

**Example Usage**

```cpp
Copy code
#include "JsonParser.h"
#include "JsonProxy.h"
#include "JsonProxySettings.h"
#include <iostream>

using namespace SimpleJSon;

int main() {
// JSON string to parse
std::string jsonString = "{\"name\":\"John\",\"age\":30}";

    // Parse JSON string
    std::shared_ptr<IJSON_Item> jsonObject;
    ParseJson(jsonString, jsonObject);

    // Configure proxy settings
    JsonProxySettings settings;
    settings.setBoolSetting(eJsonProxyOptions::eAllowObjectCreation, true);
    settings.setBoolSetting(eJsonProxyOptions::eAllowArrayCreation, false);

    // Use the parsed JSON object with proxy settings
    if (jsonObject) {
        // Construct a JsonProxy object with settings
        JsonProxy proxy(jsonObject, nullptr, std::make_shared<JsonProxySettings>(settings));

        // Access JSON elements using the proxy
        std::cout << "Name: " << proxy["name"] << std::endl;
        std::cout << "Age: " << proxy["age"] << std::endl;
    } else {
        std::cerr << "Failed to parse JSON." << std::endl;
    }

    return 0;
}
```

## Contributing

Contributions to SimpleJSon are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request on the GitHub repository.

## License

This project is licensed under the MIT License - see the LICENSE file for details.


