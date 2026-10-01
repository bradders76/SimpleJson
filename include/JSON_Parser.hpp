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
#include <filesystem>

#include "JSON_baseItem.hpp"

namespace SimpleJSon
{
    void ParseJson(const std::string &inString, std::shared_ptr<IJSON_Item> &head);
    void ParseJson(const std::filesystem::path &inPath, std::shared_ptr<IJSON_Item> &head);
}

#endif

