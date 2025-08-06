// *******************************************************
// String Utils
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// Basic JSon object, all Json objects derived from
//


#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <cstdlib>

#include "../include/StringUtils.hpp"

namespace SimpleJSon
{
    bool StringUtils::IsWhiteSpace (char c)
    {
        return ( c == ' ' || c == '\n'  || c == '\r' ||  c == '\t');
    }

    std::string StringUtils::LongToHexString(unsigned long decimalValue)
    {
        std::stringstream stream;
        
        stream << std::setfill('0') << std::setw(4) << std::hex << decimalValue;
        return stream.str();
    }

    std::string StringUtils::Trim(const std::string& inString)
    {
        int size =static_cast<int>(inString.size());
        int p1 = 0;
        int p2 = size -1;
        
        // trim
        for(;p1 < size && IsWhiteSpace(inString[p1]); p1++);
        for(;p2 > p1 && IsWhiteSpace(inString[p2]); p2--);
        
        if(p2 < p1)
        {
            return "";
        }
        
        return inString.substr(p1,p2-p1 + 1);
    }

    std::string StringUtils::JsonStringToString(const std::string& value)
    {
        std::string retString;
       
        
        for(int i = 0; i < value.length();  i++)
        {
            char c = value[i];
            
            if(c == '\\')
            {
               c = value[++i];
               switch(c)
               {
                   case('\\'):
                       retString += '\\';
                      break;
                   case('b'):
                       retString += '\b';
                       break;
                   case('r'):
                       retString += '\r';
                       break;
                   case('n'):
                       retString += '\n';
                       break;
                   case('t'):
                       retString += '\t';
                       break;
                   case('/'):
                       retString += '/';
                       break;
                   case('u'):
                       {
                           i++;
                           std::string hexStr = value.substr(i,4);
                           i+=3;
                           char * p;
                      
                           long n = std::strtol( hexStr.c_str(), & p, 16 );
                      
                           if ( * p != 0 )
                           {
                              throw(std::runtime_error("invalid"));
                           }
                        
                           if( n < 0x9f)
                           {
                               retString += char(n);
                           }
                           else if( n <= 0x7FF)
                           {
                               retString += (char)(0b11000000 | (0b00011111 & (n >> 6)));
                               retString += (char)(0b10000000 | (0b00111111 & n));
                           }
                           else if(n <= 0xFFFF)
                           {
                               retString += (char)(0b11100000 | (0b00001111 & (n >> 12)));
                               retString += (char)(0b10000000 | (0b00111111 & (n >> 6)));
                               retString += (char)(0b10000000 | (0b00111111 & n));
                           }
                           else if(n <= 0x1FFFFF)
                           {
                               retString += (char)(0b11110000 | (0b00000111 & (n >> 18)));
                               retString += (char)(0b10000000 | (0b00111111 & (n >> 12)));
                               retString += (char)(0b10000000 | (0b00111111 & (n >> 6)));
                               retString += (char)(0b10000000 | (0b00111111 & n));
                           }
                           else
                           {
                               throw(std::runtime_error("invalid"));
                           }
                       }
                       break;
                       
                    default:
                       throw(std::runtime_error("invalid"));
                       break;
                       
               }
            }
            else{
                retString += c;
            }
           
         
        }
        
        return retString;
    }

    std::string StringUtils::StringToJsonString(const std::string& value)
    {
        std::string retString;
        
        for(int i = 0; i < value.length();  i++)
        {
            char c = value[i];
            switch(c)
            {
                case '"':
                    retString += "\\\"";
                    break;
                case '\\':
                    retString += "\\\\";
                    break;
                case '\b':
                    retString += "\\b";
                    break;
                case '\f':
                    retString += "\\f";
                    break;
                case '\n':
                    retString += "\\n";
                    break;
                case '\r':
                    retString += "\\r";
                    break;
                case '\t':
                    retString += "\\t";
                    break;
                case '/':
                    retString += "/";
                    break;
                default:
                    if(!(0b10000000 & c))
                    {
                        retString += c;
                    }
                    else{
                        // Non-ASCII characters
                           unsigned long code  = 0;
                           if ((c & 0b11100000  )        == 0b11000000) {
                               // 2-byte UTF-8 character
          
                               code = ((c & 0b00011111) << 6);
                               
                               auto b2 = value[++i];
     
                               code += (b2 & 0b00111111);
                               
                           } else if ((c & 0b11110000  ) == 0b11100000) {
                               // 3-byte UTF-8 character
                               
                               code = ((c & 0b00000111) << 12);
                               
                               auto b2 = value[++i] & 0b00111111;
                               auto b3 = value[++i] & 0b00111111;
                                      //   10111101        10111101
                   
                               // check for invalid 0x10xxxxxx
                               code += (b2 << 6);
                               code += b3;
                           } else if ((c & 0b11111000  ) == 0b11110000) {
                               // 4-byte UTF-8 character
                            
                               code = ((c & 0b00000111) << 18);
                               
                               auto b2 = value[++i] & 0b00011111;
                               auto b3 = value[++i] & 0b00011111;
                               auto b4 = value[++i] & 0b00011111;
        
                               code += (b2 << 12);
                               code += (b3 << 6);
                               code += b4;
                           }
                           else{
                               throw(std::runtime_error("invalid byte"));
                           }

                        retString += "\\u" + LongToHexString(code);
                        
                    }
            }
        }
        return retString;
    }

    std::vector<std::string> StringUtils::Split(const std::string& string, char sep)
    {
        
        std::vector<std::string> items;
        std::string newItem;
        int leftBracketSquare = 0;
        int leftBracketCircle = 0;
        int leftBracketCurl = 0;
        bool inString = false;
        for(auto c:string)
        {
            if(!inString) {
                if (c == '(') leftBracketCircle += 1;
                if (c == ')') leftBracketCircle -= 1;
                if (c == '[') leftBracketSquare += 1;
                if (c == ']') leftBracketSquare -= 1;
                if (c == '{') leftBracketCurl += 1;
                if (c == '}') leftBracketCurl -= 1;
            }
            if(c == '"') inString = !inString;

            // error leftBracketSquare or leftBracketCircle < 0
            
            if(c == sep && leftBracketCircle == 0 && leftBracketSquare == 0 && leftBracketCurl == 0 && !inString)
            {
                
                items.push_back(Trim(newItem));
                newItem = "";
            }else{
                newItem += c;
            }
        }
        items.push_back(Trim(newItem));
        return items;
    }
}


