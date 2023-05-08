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
    // Checks if a username is already being used
    bool usernameExists(string username);
    // Checks if an email is already being used
    bool emailExists(string email);
    // Registers users
    void registerUser(string first, string last, string email, string username, string password);
    // Checks to see if a user exists and password matches when logging in
    bool userExists(string username, string password);
    // Logs in users
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

