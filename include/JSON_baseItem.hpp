// *******************************************************
// JSON_BaseItem
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// Basic JSon object, all Json objects derived from
//

#ifndef JSON_BASE_ITEM_HPP
#define JSON_BASE_ITEM_HPP

#include <memory>
#include <string>
#include "IJSON_item.hpp"

namespace SimpleJSon
{
    class JSON_BaseItem : public IJSON_Item
    {
    public:
        std::string ToString(int depth) final
        {
            return ToString(depth, true);
        }

        std::string ToString(int depth, bool pretty) override
       {
           throw std::runtime_error("Not Defined");
       }

        std::shared_ptr<IJSON_Item>& operator[](unsigned short) override
        {
            throw std::runtime_error("Not Defined");
        }

        std::shared_ptr<IJSON_Item>& operator[](const std::string&) override
        {
            throw std::runtime_error("Not Defined");
        }

        void for_each_key(const std::function<void(const std::string&, std::shared_ptr<IJSON_Item>)>& fn) override
        {
            throw std::runtime_error("for_each_key not defined on this JSON type");
        }


        void for_each_index(const std::function<void(unsigned short, std::shared_ptr<IJSON_Item>)>& fn) override
        {
            throw std::runtime_error("for_each_index not defined on this JSON type");
        }

        void for_each(const std::function<void(const JSONKey&, std::shared_ptr<IJSON_Item>)>& fn)  override
        {
            throw std::runtime_error("for_each not defined on this JSON type");
        }

        bool Exists(unsigned short) override
        {
            throw std::runtime_error("Not Defined");
        }

        bool Exists(const std::string&) override
        {
            throw std::runtime_error("Not Defined");
        }

        void GetValue(double &value) override
        {
            throw std::runtime_error("Not Defined");
        }

        void GetValue(std::string &value) override
        {
            throw std::runtime_error("Not Defined");
        }

        void GetValue(bool &value) override
        {
            throw std::runtime_error("Not Defined");
        }

        virtual ~JSON_BaseItem(){};
    };
}

#endif // JSON_BASE_ITEM_HPP
