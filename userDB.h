#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <mariadb/conncpp.hpp>
#include "userInfo.h"

#ifndef USERDB_H
#define USERDB_H

class userDB {
public:
    userDB();
    userInfo fetchEntry(std::string id);
    bool usernameExists(std::string username);
    bool emailExists(std::string email);
    void registerUser(std::string first, std::string last, std::string email, std::string username, std::string password);
    bool userExists(std::string username, std::string password);
    userInfo logInUser(std::string username, std::string password);

private:
    const std::string db_url = "jdbc:mariadb://localhost:3306/GalleryArtProject";
    const std::string user = "root";
    const std::string pass = "newpassword";
    sql::Driver* driver;
    sql::Properties properties;
    std::unique_ptr<sql::Connection> conn;
};

#endif /* USERDB_H */

