#include "userInfo.h"

userInfo::userInfo() {
}

userInfo::userInfo(const std::string& f, const std::string& l, const std::string& e, const std::string& u, const std::string& p, const std::string& I) {
    first = f;
    last = l;
    email = e;
    username = u;
    password = p;
    ID = I;
}

std::string userInfo::text() {
    std::string result = ID + ". ";
    result += first + " ";
    result += last + " ";
    result += email + " ";
    result += username + " ";
    result += password;
    return result;
}

std::string userInfo::json() {
    std::string result = "{\"ID\":\"" + ID + "\",";
    result += "\"first\":\"" + first + "\",";
    result += "\"last\":\"" + last + "\",";
    result += "\"email\":\"" + email + "\",";
    result += "\"username\":\"" + username + "\",";
    result += "\"password\":\"" + password + "\"}";
    return result;
}
