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
    userInfo fetchEntry(string id);
    bool usernameExists(string username);
    bool emailExists(string email);
    void registerUser(string first, string last, string email, string username, string password);
    bool userExists(string username, string password);
    userInfo logInUser(string username, string password);

private:
    const string db_url = "jdbc:mariadb://localhost:3306/GalleryArtProject";
    const string user = "root";
    const string pass = "newpassword";
    sql::Driver* driver;
    sql::Properties properties;
    std::unique_ptr<sql::Connection> conn;
};

#endif /* USERDB_H */

