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
#include "IJSON_item.hpp"
#include "JSON_Null.hpp"
#include "JSON_Object.hpp"
#include "JSON_Array.hpp"
#include "JSON_Number.hpp"
#include "JSON_Boolean.hpp"
#include "JSON_String.hpp"
#include "JSON_Proxy_Settings.hpp"
#include "TypeHelper.h"
#include <variant>
namespace SimpleJSon
{
    class JsonProxy
    {
    private:
        std::mutex                       m_mtx;
        std::shared_ptr<IJSON_Item>      m_pItem;
        std::shared_ptr<JSON_Array>      m_pParentArray;
        std::shared_ptr<JSON_Object>     m_pParentObject;

        std::string                      m_parentKey;
        unsigned short                   m_parentIndex;

        std::shared_ptr<JsonProxySettings> m_settings;


        void UpdateParentWithCurrentItem();

    protected:
        JsonProxy(std::shared_ptr<IJSON_Item> item,
                  std::shared_ptr<JSON_Object> parentObject,
                  std::shared_ptr<JsonProxySettings> settings,
                  std::string parentKey
        ) ;

        JsonProxy(std::shared_ptr<IJSON_Item> item,
                  std::shared_ptr<JSON_Array> parentArray,
                  std::shared_ptr<JsonProxySettings> settings,
                  unsigned short parentIndex
        ) ;

    public:
        static std::shared_ptr<IJSON_Item> CreateBlankHead()
        {
            return nullptr;
        }



        explicit JsonProxy(std::shared_ptr<IJSON_Item> item,  std::shared_ptr<JsonProxySettings> settings = nullptr);


        template<class T>
        bool IsType() const{
            return TypeHelper::IsType<T>(m_pItem);
        }

        template<class T>
        std::shared_ptr<T> GetValue(){
            return TypeHelper::GetValue<T>(m_pItem);
        }

        JsonProxy& operator=(const std::shared_ptr<IJSON_Item>& jsonItem);

        template<typename T>
        JsonProxy& operator=(T item)
        {
            SetValue(item);
            return *this;
        }

        std::vector<std::shared_ptr<IJSON_Item>> GetArray();


        template<typename T>
        void SetValue(T value)
            {
                if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, const char*> || std::is_same_v<T, char*> || std::is_same_v<T, char[]>)
                {
                    m_pItem = std::make_shared<JSON_String>(std::string(value));
                }
                else if constexpr (std::is_same_v<T, double> || std::is_same_v<T, float> || std::is_same_v<T, int> || std::is_same_v<T, long>)
                {
                    m_pItem = std::make_shared<JSON_Number>(value);
                }
                else if constexpr (std::is_same_v<T, bool>)
                {
                    m_pItem = std::make_shared<JSON_Boolean>(value);
                }
                else
                {
                    throw std::runtime_error("Unsupported Type");
                }

                UpdateParentWithCurrentItem();
            }
         

        template<typename T>
        void GetValue(T &value)
            {
            
                std::shared_ptr<IJSON_Item> item;
                
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
                    throw std::runtime_error("Item not found");
                }
                
            }

        void for_each_key(const std::function<void(const std::string&, std::shared_ptr<IJSON_Item>)>& fn);

        void for_each_index(const std::function<void(unsigned short, std::shared_ptr<IJSON_Item>)>& fn);

        void for_each(const std::function<void(const JSONKey&, std::shared_ptr<IJSON_Item>)>& fn);

        JsonProxy operator[](const std::string& key);
        
        JsonProxy operator[](unsigned short index);

        operator std::string() const;


        // Declare operator<< as a friend function
        friend std::ostream& operator<<(std::ostream& os, JsonProxy& item);

        [[nodiscard]] std::shared_ptr<IJSON_Item> GetItem() const;
    };
}


#endif

