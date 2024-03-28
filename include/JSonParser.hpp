// *******************************************************
// JSonParser
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Parser class
//

#ifndef JSON_PARSER_HPP
#define JSON_PARSER_HPP

#include <memory>
#include "BaseItem.hpp"

namespace SimpleJSon
{
    void ParseJson(std::string inString, std::shared_ptr<IJSonItem> &head);
}

#endif

