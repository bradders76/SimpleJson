// *******************************************************
// BaseJsonItem
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
#include "IJSonItem.hpp"

namespace SimpleJSon
{
    class BaseJsonItem : public IJSonItem
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

        std::shared_ptr<IJSonItem>& operator[](unsigned short) override
        {
            throw std::runtime_error("Not Defined");
        }

        std::shared_ptr<IJSonItem>& operator[](const std::string&) override
        {
            throw std::runtime_error("Not Defined");
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

        virtual ~BaseJsonItem(){};
    };
}

#endif // JSON_BASE_ITEM_HPP
