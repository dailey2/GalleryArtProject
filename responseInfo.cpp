#include "responseInfo.h"

responseInfo::responseInfo() {
}

responseInfo::responseInfo(sql::SQLString a, sql::SQLString e, sql::SQLString I) {
    artwork = a;
    emotion = e;
    ID = I;
}

string responseInfo::text() {
    string result = ID + ". ";
    result += artwork + " ";
    result += emotion;
    return result;
}

string responseInfo::json() {
    string result = "{\"ID\":\"" + ID + "\",";
    result += "\"artwork\":\"" + artwork + "\",";
    result += "\"emotion\":\"" + emotion + "\"}";
    return result;
}