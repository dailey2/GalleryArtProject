#include "userInfo.h"

userInfo::userInfo() {
}

userInfo::userInfo(sql::SQLString f, sql::SQLString l, sql::SQLString e, sql::SQLString u, sql::SQLString p, sql::SQLString I) {
    first = f;
    last = l;
    email = e;
    username = u;
    password = p;
    ID=I;
    
}

string userInfo::text() {
	string result = ID + ". ";
	result += first + " ";
	result += last + " ";
	result += email + " ";
	result += username + " ";
	result += password;
	return result;

}

string userInfo::json() {
	string result = "{\"ID\":\"" + ID + "\",";
	result += "\"first\":\"" + first + "\",";
	result += "\"last\":\"" + last + "\",";
	result += "\"email\":\"" + email + "\",";
	result += "\"username\":\"" + username + "\",";
	result += "\"password\":\"" + password + "\"}";
	return result;

}
