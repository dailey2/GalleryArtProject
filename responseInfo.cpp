#include "responseInfo.h"

responseInfo::responseInfo() {
}

responseInfo::responseInfo(const std::string& a, const std::string& e, const std::string& I) {
    artwork = a;
    emotion = e;
    ID = I;
}

std::string responseInfo::text() {
    std::string result = ID + ". ";
    result += artwork + " ";
    result += emotion;
    return result;
}

std::string userInfo::json() {
    std::string result = "{\"ID\":\"" + ID + "\",";
    result += "\"artwork\":\"" + artwork + "\",";
    result += "\"emotion\":\"" + emotion + "\"}";
    return result;
}