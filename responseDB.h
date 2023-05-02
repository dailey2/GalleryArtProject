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
    void submitResponse(std::string artwork, std::string emotion);

private:
    const std::string db_url = "jdbc:mariadb://localhost:3306/GalleryArtProject";
    const std::string user = "root";
    const std::string pass = "newpassword";
    sql::Driver* driver;
    sql::Properties properties;
    std::unique_ptr<sql::Connection> conn;
};

#endif /* USERDB_H */

