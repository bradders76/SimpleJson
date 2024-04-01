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

namespace SimpleJSon {

    class IJSON_Item {
    public:
        virtual std::string ToString(int depth)   = 0;
        virtual std::string ToString(int depth, bool pretty) = 0;

        virtual std::shared_ptr<IJSON_Item> &operator[](unsigned short) = 0;

        virtual std::shared_ptr<IJSON_Item> &operator[](const std::string &) = 0;

        virtual bool Exists(unsigned short) = 0;

        virtual bool Exists(const std::string &) = 0;

        virtual void GetValue(double &value) = 0;

        virtual void GetValue(std::string &value) = 0;

        virtual void GetValue(bool &value) = 0;

        // Declare operator<< as a friend function
         friend std::ostream& operator<<(std::ostream& os, IJSON_Item& item);
    };
}
#endif

