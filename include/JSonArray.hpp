// *******************************************************
// JSonArray
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Array class
//

#ifndef JSON_ARRAY_HPP
#define JSON_ARRAY_HPP

#include "IJSonItem.hpp"
#include "JSonNull.hpp"

#include <map>
#include <memory>

namespace SimpleJSon
{
    class JSonArray :  public BaseJsonItem
    {
        private:
            std::mutex m_mtx;

            std::map<unsigned short, std::shared_ptr<IJSonItem> > m_array;
        
        public:
            void AddItem(unsigned short index, std::shared_ptr<IJSonItem> pItem);
                    
            bool Exists(unsigned short index) override;
        
            std::string ToString(int depth, bool pretty) override;
            
            std::shared_ptr<IJSonItem>& operator[](unsigned short index) override;
    };
}


#endif

