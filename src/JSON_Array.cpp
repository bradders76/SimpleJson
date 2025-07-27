// *******************************************************
// JSON_Array
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Array class
//


#include <utility>

#include "../include/JSON_Array.hpp"

namespace SimpleJSon
{


    std::string JSON_Array::ToString(int depth, bool pretty)
    {
        std::lock_guard<std::mutex> lock(m_mtx);

        JSON_Null nullItem;
        
        if(m_array.empty()) return "";
        
        unsigned short endItem = m_array.rbegin()->first;
        
        std::string retString = "[";
        for(unsigned short i = 0; i <= endItem; i++)
        {
            if(m_array.find(i) == m_array.end())
            {
                retString += nullItem.ToString(depth, pretty);
                
            }else{
                retString += m_array[i]->ToString(depth,pretty);
            }
            
            if(i != endItem)
            {
                retString += ",";
            }
        }
        
        return retString + "]";
    }

    std::shared_ptr<IJSON_Item>& JSON_Array::operator[](unsigned short index)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        if(m_array.find(index) != m_array.end())
        {
            return m_array[index];
        }

        throw std::runtime_error("Not Defined");
    }

    void JSON_Array::AddItem(unsigned short index, std::shared_ptr<IJSON_Item> pItem)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        m_array[index] = std::move(pItem);
    }

    bool JSON_Array::Exists(unsigned short index)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        return m_array.find(index) != m_array.end();
    }

    void JSON_Array::for_each_index(const std::function<void(unsigned short, std::shared_ptr<IJSON_Item>)>& fn)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        for (auto &item: m_array) {
            fn(item.first, item.second);
        }
    }

    void JSON_Array::for_each(const std::function<void(const JSONKey&, std::shared_ptr<IJSON_Item>)>& fn)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);
        for (auto &item: m_array) {
            JSONKey key(item.first);
            fn(key, item.second);
        }
    }

    std::vector<std::shared_ptr<IJSON_Item>> JSON_Array::GetArray()
    {
        std::vector<std::shared_ptr<IJSON_Item>> returnArray;
        int cnt = 0;
        for (auto &item: m_array) {
            while(cnt < item.first)
            {
                returnArray.push_back(nullptr);
            }
            returnArray.push_back(item.second);
        }

        return returnArray;
    }

}
