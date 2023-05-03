#include "dynamicArtInfo.h"

dynamicArtInfo::dynamicArtInfo() {
}

dynamicArtInfo::dynamicArtInfo(sql::SQLString e, sql::SQLString I) {
    emotion = e;
    ID = I;
}

string responseInfo::text() {
    string result = ID + ". ";
    result += emotion;
    return result;
}

string responseInfo::json() {
    string result = "{\"ID\":\"" + ID + "\",";
    result += "\"emotion\":\"" + emotion + "\"}";
    return result;
}