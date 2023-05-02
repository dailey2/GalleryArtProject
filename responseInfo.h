#include <mariadb/conncpp.hpp>
#include <string>

#ifndef RESPONSEINFO_H
#define RESPONSEINFO_H

class userInfo {
public:
    userInfo();
    userInfo(const std::string& a, const std::string& e, const std::string& I);
    std::string text();
    std::string json();

    std::string artwork;
    std::string emotion;
    std::string ID;

private:

};

#endif