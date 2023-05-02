#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <mariadb/conncpp.hpp>
#include "responseInfo.h"

#ifndef RESPONSEDB_H
#define RESPONSEDB_H

class responseDB {
public:
    responseDB();
    bool submitResponse(string artwork, string emotion);

private:
    const string db_url = "jdbc:mariadb://localhost:3306/GalleryArtProject";
    const string user = "root";
    const string pass = "newpassword";
    sql::Driver* driver;
    sql::Properties properties;
    std::unique_ptr<sql::Connection> conn;
};

#endif /* RESPONSEDB_H */

