#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

#include "httplib.h"
#include "userDB.h"
#include "userInfo.h"
#include "responseDB.h"
#include "responseInfo.h"

using namespace httplib;
using namespace std;

const int port = 5005;

int main(void) { 
    Server svr;
    userDB udb;
    responseDB rdb;

    // "/" just returnsAPI name */
    svr.Get("/", [](const Request & /*req*/, Response &res) {
        res.set_header("Access-Control-Allow-Origin","*");
        res.set_content("ArtProject API", "text/plain");
    });

    // Service to log in users
    svr.Get(R"(/artProject/logIn/(.*)/(.*))", [&](const Request& req, Response& res) {
        res.set_header("Access-Control-Allow-Origin","*");
        string username = req.matches[1];
        string password = req.matches[2];
        string result;

        if(udb.userExists(username,password)){
            userInfo user = udb.logInUser(username, password);
            result = "{\"status\":\"success\",\"user\":\"" + username + "\"}";
            res.set_content(result, "text/json");
        } else {
            result = "{\"status\":\"not registered\"}";
            res.set_content(result, "text/json");
        }
    });

    //Service to register new users
    svr.Get(R"(/artProject/register/(.*)/(.*)/(.*)/(.*)/(.*))", [&](const Request& req, Response& res) {
        res.set_header("Access-Control-Allow-Origin","*");
        string first = req.matches[1];
        string last = req.matches[2];
        string email = req.matches[3];
        string username = req.matches[4];
        string password = req.matches[5];

        // Check to see if username or email exists before completing registration
        bool usernameSuccess = !udb.usernameExists(username);
        bool emailSuccess = !udb.emailExists(email);
        bool passwordSuccess = password.length() > 6;
		string result;
		
        if (usernameSuccess && emailSuccess && passwordSuccess){
            udb.registerUser(first, last, email, username, password);
            result = "{\"status\":\"success\"}";
        } else {
			result = "{\"status\":\"error\",";
			if (!usernameSuccess) result += "\"username_error\":\"Username already exists.\",";
			if (!emailSuccess) result += "\"email_error\":\"Email already in use.\",";
			if (!passwordSuccess) result += "\"password_error\":\"Password is too short. Must be at least 7 characters.\",";
			result.pop_back(); // Remove the trailing comma
			result += "}";
		}
		res.set_content(result, "text/json");
    });
    
    // Service to submit responses
    svr.Get(R"(/artProject/submit/(.*)/(.*))", [&](const Request& req, Response& res) {
        res.set_header("Access-Control-Allow-Origin","*");
        string artwork = req.matches[1];
        string emotion = req.matches[2];

        // Change submitResponse function to return a boolean indicating success or failure!!
    	bool success = rdb.submitResponse(artwork, emotion);

    	string result;

    	if (success) {
    		
        	result = "{\"status\":\"success\"}";
    	} else {
        	result = "{\"status\":\"error\"}";
    	}
    	res.set_content(result, "text/json");
    });

	//Require users to register 
  	cout << "Server listening on port " << port << endl;
  	svr.listen("0.0.0.0", port);

} // End main

