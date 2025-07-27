//
// Created by Bradley Crouch on 27/07/2025.
//

#ifndef SIMPLEJSON_TYPEHELPER_H
#define SIMPLEJSON_TYPEHELPER_H
#include "IJSON_item.hpp"

namespace SimpleJSon::TypeHelper {

    template<class T>
    bool IsType(const std::shared_ptr<IJSON_Item>& item) {
        return std::dynamic_pointer_cast<T>(item) != nullptr;
    }

    template<class T>
    std::shared_ptr<T> GetValue(const std::shared_ptr<IJSON_Item>& item) {
        return std::dynamic_pointer_cast<T>(item);
    }

}

#endif
