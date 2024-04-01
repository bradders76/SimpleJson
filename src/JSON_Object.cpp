// *******************************************************
// JSON_Object
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Object class
//

#include "../include/JSON_Object.hpp"
#include "../include/StringUtils.hpp"
#include <iostream>
#include <utility>

namespace SimpleJSon
{
    std::ostream& operator<<(std::ostream& os, IJSON_Item& item) {
        return os << item.ToString(0, true);
    }

    void JSON_Object::AddItem(const std::string& id, std::shared_ptr<IJSON_Item> pItem)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        m_map[id] = std::move(pItem);
    }

    bool JSON_Object::Exists(const std::string& index)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        return m_map.find(index) != m_map.end();
    }

    std::string ToString(int depth, bool pretty = false);

    std::shared_ptr<IJSON_Item>& JSON_Object::operator[](const std::string &id)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        if( m_map.find(id) != m_map.end())
        {
            return m_map[id];
        }
        
        throw std::runtime_error("Not Defined");
    }

    std::string JSON_Object::ToString(int depth, bool pretty)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        std::string space(depth, '\t');
        std::string retString = "\n" + space + "{" + "\n";


        auto items = m_map.size();
        int cnt = 0;
        for(auto &item:m_map)
        {
            retString += space + "\t\"" +  StringUtils::StringToJsonString(item.first) + "\" : " + item.second->ToString(depth + 1, pretty);
       
            cnt ++;
            
            if(cnt  < items)
            {
                retString += ",";
            }
            
            retString += "\n";
        }
    
        return retString + space + "}";
    }
}
