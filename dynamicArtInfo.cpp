#include "dynamicArtInfo.h"

dynamicArtInfo::dynamicArtInfo() {
}

dynamicArtInfo::dynamicArtInfo(sql::SQLString e, sql::SQLString I) {
    emotion = e;
    ID = I;
}

string dynamicArtInfo::text() {
    string result = ID + ". ";
    result += emotion;
    return result;
}

string dynamicArtInfo::json() {
    string result = "{\"ID\":\"" + ID + "\",";
    result += "\"emotion\":\"" + emotion + "\"}";
    return result;
}