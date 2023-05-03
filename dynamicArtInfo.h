#include <mariadb/conncpp.hpp>
#include <string>

#ifndef DYNAMICARTINFO_H
#define DYNAMICARTINFO_H

using namespace std;

class dynamicArtInfo {
public:
    dynamicArtInfo();
    dynamicArtInfo(sql::SQLString e, sql::SQLString I);
	string text();
    string json();

    string emotion;
    string ID;

private:

};

#endif