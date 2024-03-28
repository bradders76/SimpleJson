// *******************************************************
// JSON_Array
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Array class
//

#ifndef JSON_ARRAY_HPP
#define JSON_ARRAY_HPP

#include "IJSON_item.hpp"
#include "JSON_Null.hpp"

#include <map>
#include <memory>

namespace SimpleJSon
{
    class JSON_Array : public JSON_BaseItem
    {
        private:
            std::mutex m_mtx;

            std::map<unsigned short, std::shared_ptr<IJSON_Item> > m_array;
        
        public:
            void AddItem(unsigned short index, std::shared_ptr<IJSON_Item> pItem);
                    
            bool Exists(unsigned short index) override;
        
            std::string ToString(int depth, bool pretty) override;
            
            std::shared_ptr<IJSON_Item>& operator[](unsigned short index) override;
    };
}


#endif

