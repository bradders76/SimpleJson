// *******************************************************
// JSonParser
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// JSon Parser class
//

#include <memory>
#include <iostream>

#include "../include/JSonObject.hpp"
#include "../include/JSonArray.hpp"
#include "../include/JSonString.hpp"
#include "../include/JSonBoolean.hpp"
#include "../include/JSonNumber.hpp"
#include "../include/StringUtils.hpp"


namespace SimpleJSon
{
    void ParseJson(std::string inString, std::shared_ptr<IJSonItem> &head)
    {
        int size = static_cast<int>(inString.size());
        int p1 = 0;
        int p2 = size -1;
        
        // trim
        for(;p1 < size && StringUtils::IsWhiteSpace(inString[p1]); p1++);
        for(;p2 > 0 && StringUtils::IsWhiteSpace(inString[p2]); p2--);
        
        if(p2 < p1)
        {
            std::cout << "Its empty" << std::endl;
            return;
        }
        
        auto subString  = inString.substr(p1,p2-p1 + 1);
        auto c1         = inString[p1];
        auto c2         = inString[p2];
        
        if(c1 == '{' && c2 == '}')
        {
            subString =  subString.substr(1, subString.length() - 2);


            auto object = std::make_shared<JSonObject>();
            auto items  = StringUtils::Split(subString, ',');
            
            for(auto &item:items)
            {
                auto subObject = StringUtils::Split(item, ':');
                            
                std::shared_ptr<IJSonItem> o;
                
                ParseJson(subObject[1], o);
                 
                auto id = subObject[0].substr(1, subObject[0].length() - 2 );
                object->AddItem(id, o);
            }
            
            head = object;
        }
        else if(c1 == '['  && c2 == ']')
        {
            subString =  subString.substr(1, subString.length() - 2);

            auto array = std::make_shared<JSonArray>();
            auto items = StringUtils::Split(subString, ',');
            
            unsigned short cnt = 0;
            for(auto &item:items)
            {
                std::shared_ptr<IJSonItem> o;
                
                ParseJson(item, o);
                array->AddItem(cnt++, o);
            }
          
            head = array;
        }
        else if(c1 == '\"' && c2 == '\"' )
        {
            
            subString =  subString.substr(1, subString.length() - 2);
            subString =  StringUtils::JsonStringToString(subString);

            head = std::make_shared<JSonString>(std::string(subString));
        }
        else if(isdigit(c1) || c1 == '-')
        {
            head = std::make_shared<JSonNumber>(std::stod(subString));
        }
        else if(subString == "true")
        {
            head = std::make_shared<JSonBoolean>(true);
        }
        else if(subString == "false")
        {
            head = std::make_shared<JSonBoolean>(false);
        }
        else if(subString == "null")
        {
            head = std::make_shared<JSonNull>();
        }
        else{
            throw(std::invalid_argument("invalid token"));
        }
    }
}


