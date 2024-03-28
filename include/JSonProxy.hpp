// *******************************************************
// JSonProxy
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Proxy class
//

#ifndef JSON_PROXY_HPP
#define JSON_PROXY_HPP

#include <iostream>
#include <memory>
#include <type_traits>
#include "JSonNull.hpp"
#include "JSonObject.hpp"
#include "JSonArray.hpp"
#include "JSonNumber.hpp"
#include "JSonBoolean.hpp"
#include "JSonString.hpp"

namespace SimpleJSon
{
    class JsonProxy
    {
    private:
        std::mutex                      m_mtx;
        std::shared_ptr<IJSonItem>      m_pItem;
        std::shared_ptr<JSonArray>      m_pParentArray;
        std::shared_ptr<JSonObject>     m_pParentObject;
        std::string                     m_parentKey;
        unsigned short                  m_parentIndex;

        void UpdateParentWithCurrentItem();

    public:

        static std::shared_ptr<IJSonItem> CreateBlankHead()
        {
            return nullptr;
        }


        explicit JsonProxy(std::shared_ptr<IJSonItem> item);

        JsonProxy(std::shared_ptr<IJSonItem> item,
                  std::shared_ptr<JSonObject> parentObject,
                  std::string parentKey
                  ) ;

        JsonProxy(std::shared_ptr<IJSonItem> item,
                  std::shared_ptr<JSonArray> parentArray,
                  unsigned short parentIndex
        ) ;

        JsonProxy& operator=(const std::shared_ptr<IJSonItem>& jsonItem);

        template<typename T>
        JsonProxy& operator=(T item)
        {
            SetValue(item);
            return *this;
        }

        template<typename T>
        void SetValue(T value)
            {
                if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, const char*> || std::is_same_v<T, char*> || std::is_same_v<T, char[]>)
                {
                    m_pItem = std::make_shared<JSonString>(std::string(value));
                }
                else if constexpr (std::is_same_v<T, double> || std::is_same_v<T, float> || std::is_same_v<T, int> || std::is_same_v<T, long>)
                {
                    m_pItem = std::make_shared<JSonNumber>(value);
                }
                else if constexpr (std::is_same_v<T, bool>)
                {
                    m_pItem = std::make_shared<JSonBoolean>(value);
                }
                else
                {
                    throw std::runtime_error("Unsorted Type");
                }

                UpdateParentWithCurrentItem();
            }
         

        template<typename T>
        void GetValue(T &value)
            {
            
                std::shared_ptr<IJSonItem> item;
                
                if(m_pParentArray != nullptr)
                {
                    item = (*m_pParentArray)[m_parentIndex];
                }
                else if(m_pParentObject != nullptr)
                {
                    item = (*m_pParentObject)[m_parentKey];
                }
            

                if(item)
                {
                    item->GetValue(value);
                    
                    
                // Handle unsupported data types
                }
                else
                {
                    throw std::runtime_error("item not found");
                }
                
            }
        
        
        JsonProxy operator[](const std::string& key);
        
        JsonProxy operator[](unsigned short index);

        operator std::string() const;

        [[nodiscard]] std::shared_ptr<IJSonItem> GetItem() const;
    };
}


#endif

