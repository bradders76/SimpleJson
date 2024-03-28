// JSON_UnitTest_MockJSonItems
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 28
//
// Mock JSonItem
//

#ifndef SIMPLEJSON_UNITTEST_MOCK_JSON_ITEM_H
#define SIMPLEJSON_UNITTEST_MOCK_JSON_ITEM_H

#endif //SIMPLEJSON_UNITTEST_MOCK_JSON_ITEM_H

#include <gmock/gmock.h>
#include "../include/JSON.hpp"

class MockJSonItem : public SimpleJSon::JSON_BaseItem {
public:
    MOCK_METHOD2(ToString, std::string(int depth, bool pretty));
    MOCK_METHOD1(GetValue, void(double &value));
    MOCK_METHOD1(GetValue, void(std::string &value));
    MOCK_METHOD1(GetValue, void(bool &value));
    MOCK_METHOD1(Exists, bool(unsigned short));
    MOCK_METHOD1(Exists, bool(const std::string&));

    MOCK_METHOD1(BracketOp, std::shared_ptr<SimpleJSon::IJSON_Item> & (unsigned short));
    MOCK_METHOD1(BracketOp, std::shared_ptr<SimpleJSon::IJSON_Item> &(const std::string&));

    std::shared_ptr<SimpleJSon::IJSON_Item>& operator[](unsigned short index){ return BracketOp(index);};
    std::shared_ptr<SimpleJSon::IJSON_Item>& operator[](const std::string& index){ return BracketOp(index);};
};
