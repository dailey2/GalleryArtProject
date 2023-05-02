#include <mariadb/conncpp.hpp>
#include <string>

#ifndef USERINFO_H
#define USERINFO_H

using namespace std;

class userInfo {
public:
    userInfo();
    userInfo(sql::SQLString f, sql::SQLString l, sql::SQLString e, sql::SQLString u, sql::SQLString p, sql::SQLString I);
	string text();
    string json();

    string first;
    string last;
    string email;
    string username;
    string password;
    string ID;

private:

};

#endif
