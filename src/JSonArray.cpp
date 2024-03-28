// *******************************************************
// JSonArray
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Array class
//


#include <utility>

#include "../include/JSonArray.hpp"

namespace SimpleJSon
{
    std::string JSonArray::ToString(int depth, bool pretty)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        JSonNull nullItem;
        
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

    std::shared_ptr<IJSonItem>& JSonArray::operator[](unsigned short index)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        if(m_array.find(index) != m_array.end())
        {
            return m_array[index];
        }

        throw std::runtime_error("Not Defined");
    }

    void JSonArray::AddItem(unsigned short index, std::shared_ptr<IJSonItem> pItem)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        m_array[index] = std::move(pItem);
    }

    bool JSonArray::Exists(unsigned short index)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        return m_array.find(index) != m_array.end();
    }
}
