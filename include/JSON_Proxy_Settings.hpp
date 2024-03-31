// *******************************************************
//  JsonProxySettings
// *******************************************************
//
// Author: Bradley Crouch
// Copyright: © 2024 - March - 27
//
// Created by Bradley Crouch on 29/03/2024.
//

#ifndef SIMPLEJSON_JSON_PROXY_SETTINGS_H
#define SIMPLEJSON_JSON_PROXY_SETTINGS_H
#include <map>

namespace SimpleJSon {
    enum eJsonProxyOptions {
        eAllowObjectCreation,
        eAllowArrayCreation
    };

    class JsonProxySettings {
    private:
        std::map<int, bool> m_boolSettings;

    public:
        JsonProxySettings(bool allowCreation = true)
        {
            m_boolSettings[eJsonProxyOptions::eAllowObjectCreation] = allowCreation;
            m_boolSettings[eJsonProxyOptions::eAllowArrayCreation] = allowCreation;
        }

        bool getBoolSetting(eJsonProxyOptions option)
        {
            return m_boolSettings[option];
        }

        void setBoolSetting(eJsonProxyOptions option, bool value) {
            m_boolSettings[option] = value;
        }

    };
}

#endif //SIMPLEJSON_JSON_PROXY_SETTINGS_H
