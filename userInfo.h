#include <mariadb/conncpp.hpp>
#include <string>

#ifndef USERINFO_H
#define USERINFO_H

class userInfo {
public:
    userInfo();
    userInfo(const std::string& f, const std::string& l, const std::string& e, const std::string& u, const std::string& p, const std::string& I);
    std::string text();
    std::string json();

    std::string first;
    std::string last;
    std::string email;
    std::string username;
    std::string password;
    std::string ID;

private:

};

#endif
