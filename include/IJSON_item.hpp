// *******************************************************
// IJSON_Item
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// IJSON_Item, abstract to a Json Object
//

#ifndef IJSON_ITEM_HPP
#define IJSON_ITEM_HPP


#include <memory>
#include <string>
#include <functional>
#include <variant>
#include <vector>

namespace SimpleJSon {

    using JSONKey = std::variant<std::string, unsigned short>;


    class IJSON_Item {
    public:
        virtual ~IJSON_Item() = default;

        virtual std::string ToString(int depth)   = 0;
        virtual std::string ToString(int depth, bool pretty) = 0;

        virtual std::shared_ptr<IJSON_Item> &operator[](unsigned short) = 0;
        virtual std::shared_ptr<IJSON_Item> &operator[](const std::string &) = 0;


        virtual void for_each_key(const std::function<void(const std::string&, std::shared_ptr<IJSON_Item>)>& fn) = 0;
        virtual void for_each_index(const std::function<void(unsigned short, std::shared_ptr<IJSON_Item>)>& fn) = 0;
        virtual void for_each(const std::function<void(const JSONKey&, std::shared_ptr<IJSON_Item>)>& fn) = 0;

        virtual bool Exists(unsigned short) = 0;

        virtual bool Exists(const std::string &) = 0;

        virtual void GetValue(double &value) = 0;
        virtual void GetValue(int &value) = 0;
        virtual void GetValue(unsigned int &value) = 0;
        virtual void GetValue(int64_t &value) = 0;
        virtual void GetValue(std::string &value) = 0;
        virtual void GetValue(bool &value) = 0;

        virtual std::vector<std::shared_ptr<IJSON_Item>> GetArray() = 0;
        // Declare operator<< as a friend function
         friend std::ostream& operator<<(std::ostream& os, IJSON_Item& item);


    };


}


#endif

