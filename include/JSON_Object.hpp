// *******************************************************
// JSON_Object
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Object class
//

#ifndef JSON_OBJECT_HPP
#define JSON_OBJECT_HPP

#include <memory>
#include <map>
#include <string>
#include <mutex>

#include "JSON_baseItem.hpp"
#include "JSON_Parser.hpp"

namespace SimpleJSon
{
    class JSON_Object : public JSON_BaseItem
    {
        private:
            std::mutex m_mtx;
        protected:
            std::map<std::string , std::shared_ptr<IJSON_Item> > m_map;
        
        public:
            void AddItem(const std::string& id, std::shared_ptr<IJSON_Item> pItem);

            bool Exists(const std::string& index) override;
        
            std::string ToString(int depth, bool pretty) override;
        
            std::shared_ptr<IJSON_Item>& operator[](const std::string &id) override;

    };
}

#endif

