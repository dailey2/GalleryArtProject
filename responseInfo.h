#include <mariadb/conncpp.hpp>
#include <string>

#ifndef RESPONSEINFO_H
#define RESPONSEINFO_H

using namespace std;

class responseInfo {
public:
    responseInfo();
    responseInfo(sql::SQLString a, sql::SQLString e, sql::SQLString I);
	string text();
    string json();

    string artwork;
    string emotion;
    string ID;

private:

};

#endif