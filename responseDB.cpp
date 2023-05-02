#include <vector>
#include <iostream>
#include <mariadb/conncpp.hpp>
#include "responseDB.h"
#include "responseInfo.h"


responseDB::responseDB() {
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

// Submits a response to the database
bool responseDB::submitResponse(std::string artwork, std::string emotion){

    if (!conn) {
        std::cerr << "Invalid database connection" << std::endl;
        exit (EXIT_FAILURE);
    }

    std::unique_ptr<sql::Statement> stmnt(conn->createStatement());

    bool success = stmnt->execute("INSERT INTO responses(artwork,emotion) VALUES ('" + artwork + "','" + emotion + "')");

    return success;
}

