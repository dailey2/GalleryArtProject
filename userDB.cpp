#include <vector>
#include <iostream>
#include <mariadb/conncpp.hpp>
#include "userDB.h"
#include "userInfo.h"


userDB::userDB() {
  	// Instantiate Driver
  	driver = sql::mariadb::get_driver_instance();
  	
 	// Configure Connection
  	// The URL or TCP connection string format is
  	// ``jdbc:mariadb://host:port/database``.
  	sql::SQLString url(db_url);

    // Use a properties map for the other connection options
  	sql::Properties my_properties({{"user", user}, {"password",pass}});
  	// Save properties in object
  	properties = my_properties;

    // Establish Connection
  	std::unique_ptr<sql::Connection> my_conn(driver->connect(db_url, properties));
    
    // Check success
    if (!my_conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
   	}	
   	
   	// Save connection in object
   	conn = std::move(my_conn);
   	
}

// Pulls user info from database when they attempt to register or log in to see if the username already exists.
bool userDB::usernameExists(string username) {
	
    // Make sure the connection is still valid
    if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
   	}	
    // Create a new Statement
	std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
    
    // Execute query
    sql::ResultSet *res = stmnt->executeQuery("SELECT * FROM users WHERE username = '"+username+"'");
	
	if(res->next()){
		return true;
	}else{
		return false;
	}
}

// Pulls user info from database when they attempt to register to see if the email already exists.
bool userDB::emailExists(string email) {
	
    // Make sure the connection is still valid
    if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
   	}	
    // Create a new Statement
	std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
    
    // Execute query
    sql::ResultSet *res = stmnt->executeQuery("SELECT * FROM users WHERE email = '"+email+"'");
	
	if(res->next()){
		return true;
	}else{
		return false;
	}
}

// Pulls user info from database when they attempt to log in to see if the password exists.
// Change this to compare username and password
bool userDB::passwordExists(string password) {
	
    // Make sure the connection is still valid
    if (!conn) {
   		cerr << "Invalid database connection" << endl;
   		exit (EXIT_FAILURE);
   	}	
    // Create a new Statement
	std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
    
    // Execute query
    sql::ResultSet *res = stmnt->executeQuery("SELECT * FROM users WHERE password = '"+password+"'");
	
	if(res->next()){
		return true;
	}else{
		return false;
	}
}

// Registers a user when they attempt to sign up.
void userDB::registerUser(std::string first, std::string last, std::string email, std::string username, std::string password){

    if (!conn) {
        std::cerr << "Invalid database connection" << std::endl;
        exit (EXIT_FAILURE);
    }

    std::unique_ptr<sql::Statement> stmnt(conn->createStatement());

    stmnt->executeQuery("INSERT INTO users(firstName,lastName,email,username,password) VALUES ('" + first + "','" + last + "','" + email + "','" + username + "','" + password + "')");
}

// Logs in a user when they attempt to sign up.
userInfo userDB::logInUser(std::string username, std::string password){

    if (!conn) {
        std::cerr << "Invalid database connection" << std::endl;
        exit (EXIT_FAILURE);
    }

    std::unique_ptr<sql::Statement> stmnt(conn->createStatement());

    std::unique_ptr<sql::ResultSet> res(stmnt->executeQuery("SELECT * FROM users WHERE username = '" + username + "' AND password = '" + password + "'"));

    userInfo entry;
    
    // Get user info
    if (res->next()) {
        entry = userInfo(res->getString("firstName"), res->getString("lastName"), res->getString("email"),
        res->getString("username"), res->getString("password"), res->getString("ID"));
    }
    return entry;
}

// Fetch entry by ID
userInfo userDB::fetchEntry(std::string id){

    if (!conn) {
        std::cerr << "Invalid database connection" << std::endl;
        exit (EXIT_FAILURE);
    }

    std::unique_ptr<sql::Statement> stmnt(conn->createStatement());

    std::unique_ptr<sql::ResultSet> res(stmnt->executeQuery("SELECT * FROM users WHERE ID = '" + id + "'"));
    
    userInfo entry;

    // Get first entry
    if (res->next()) {
        entry = userInfo(res->getString("firstName"), res->getString("lastName"), res->getString("email"),
        res->getString("username"), res->getString("password"), res->getString("ID"));
    }
    return entry;
}
