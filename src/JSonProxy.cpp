// *******************************************************
// JSonProxy
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Proxy Class, used to allow simple access to json dataset
//
//  auto proxy = SimpleJSon::JsonProxy(head);
//
//  proxy["object"]["bool"]         = true;
//  proxy["object"]["number"]       = 1;
//  proxy["object"]["string"]       = "test";
//  proxy["object"][1]              = 1; // array index 1


#include <utility>
#include "../include/JSonProxy.hpp"

namespace SimpleJSon
{

    JsonProxy::JsonProxy(std::shared_ptr<IJSonItem> item)
     : m_pItem(std::move(item)), m_pParentArray(nullptr), m_pParentObject(nullptr), m_parentIndex(0){}

    JsonProxy::JsonProxy(std::shared_ptr<IJSonItem> item,
              std::shared_ptr<JSonObject> parentObject,
              std::string parentKey
              ) : m_pItem(std::move(item)), m_pParentArray(nullptr), m_pParentObject(std::move(parentObject)), m_parentIndex(0), m_parentKey(std::move(parentKey)) {}

    JsonProxy::JsonProxy(std::shared_ptr<IJSonItem> item,
                         std::shared_ptr<JSonArray> parentArray,
                         unsigned short parentIndex
    ) : m_pItem(std::move(item)), m_pParentArray(std::move(parentArray)), m_pParentObject(nullptr), m_parentIndex(parentIndex){}

    JsonProxy& JsonProxy::operator=(const std::shared_ptr<IJSonItem>& jsonItem)
     {
         m_pItem = jsonItem;
         return *this;
     }

    JsonProxy JsonProxy::operator[](const std::string& key)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        if(m_pItem == nullptr || std::dynamic_pointer_cast<JSonNull>(m_pItem)) {
            auto object = std::make_shared<JSonObject>();
            m_pItem = object;
            object->AddItem(key, std::make_shared<JSonNull>());

            UpdateParentWithCurrentItem();
            return {(*m_pItem)[key], object, key};
        }

        auto object = std::dynamic_pointer_cast<JSonObject>(m_pItem);
        if (object == nullptr) {
            throw (std::invalid_argument("Object assigned to different type"));
        }

         if (!object->Exists(key)) {
             object->AddItem(key, std::make_shared<JSonNull>());
         }

        UpdateParentWithCurrentItem();

         return {(*m_pItem)[key], object, key};
    }

    JsonProxy JsonProxy::operator[](unsigned short index)
    {
        const std::lock_guard<std::mutex> lock(m_mtx);

        if(m_pItem == nullptr || std::dynamic_pointer_cast<JSonNull>(m_pItem)) {
            auto array = std::make_shared<JSonArray>();
            m_pItem = array;
            array->AddItem(index, std::make_shared<JSonNull>());

            UpdateParentWithCurrentItem();
            return {(*m_pItem)[index], array, index};
        }

        auto array = std::dynamic_pointer_cast<JSonArray>(m_pItem);
        if (array == nullptr) {
            throw (std::invalid_argument("Array assigned to different type"));
        }

       if (!array->Exists(index)) {
           array->AddItem(index, std::make_shared<JSonNull>());
       }

        UpdateParentWithCurrentItem();

        return {(*m_pItem)[index], array, index};
    }

    void JsonProxy::UpdateParentWithCurrentItem()
    {
        if(m_pParentArray != nullptr)
        {
            (*m_pParentArray)[m_parentIndex] = m_pItem;
        }
        else if(m_pParentObject != nullptr)
        {
            (*m_pParentObject)[m_parentKey] = m_pItem;
        }
    }

    JsonProxy::operator std::string() const
    {
        if(m_pItem)
            return m_pItem->ToString(2);
        return "";
    }

    std::shared_ptr<IJSonItem> JsonProxy::GetItem() const
    {
        return m_pItem;
    }
}

