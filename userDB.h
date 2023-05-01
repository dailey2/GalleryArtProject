#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
/* uncomment for applications that use vectors */
#include <vector>

//#include "mysql_connection.h"
//#include "mysql_driver.h"
#include <mariadb/conncpp.hpp>

//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//#include <cppconn/prepared_statement.h>
#include "userInfo.h"

#ifndef USERDB_H
#define USERDB_H

#define DB_URL "jdbc:mariadb://localhost:3306/GalleryArtProject"
#define USER "root"
#define PASS "newpassword"

using namespace std;

class userDB {

public:
    userDB();
    userInfo fetchEntry(string id);
    bool usernameExists(string username);
    bool emailExists(string email);
    bool passwordExists(string email);
    void registerUser(string first,string last,string email,string username,string password);
    userInfo logInUser(string username,string password);

private:
    const string db_url=DB_URL;
    const string user=USER;
    const string pass=PASS;
    sql::Driver* driver;
    sql::Properties properties;
    std::unique_ptr<sql::Connection> conn;

};

#endif /* USERDB_H */
