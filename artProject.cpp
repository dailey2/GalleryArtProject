#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

#include "httplib.h"
#include "userDB.h"
#include "userInfo.h"

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

        if(udb.usernameExists(username) && udb.passwordExists(password)){
            userInfo user = udb.logInUser(username, password);
            result = "{\"status\":\"success\",\"user\":\"" + username + "\"}";
            res.set_content(result, "text/json");
        } else {
            result = "{\"status\":\"not registered\"}";
            res.set_content(result, "text/json");
        }
    });

    // Service to log out users
    svr.Get(R"(/artProject/logOut/(.*)/(.*))", [&](const Request& req, Response& res) {
        res.set_header("Access-Control-Allow-Origin","*");
        string username = req.matches[1];
        string password = req.matches[2];
        string result;

        // You can add any log out functionality here if needed.

        result = "{\"status\":\"success\",\"user\":\"" + username + "\",\"message\":\"Logged out\"}";
        res.set_content(result, "text/json");
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

        if (usernameSuccess && emailSuccess && passwordSuccess){
            udb.registerUser(first, last, email, username, password);
        }

        string result;

        if (usernameSuccess && emailSuccess && passwordSuccess){
            result = "{\"status\":\"success\"}";
        } else {
            result = "{\"status\":\"error\"}";
        }
        res.set_content(result, "text/json");
    });
    
    // Service to submit responses
    svr.Get(R"(/artProject/submit/(.*)/(.*))", [&](const Request& req, Response& res) {
        res.set_header("Access-Control-Allow-Origin","*");
        string artwork = req.matches[1];
        string emotion = req.matches[2];

        // Check to see if username or email exists before completing registration
        rdb.submitResponse(artwork,emotion);

        string result;
		
		// This code is from register user and needs changed
        //if (usernameSuccess && emailSuccess && passwordSuccess){
        //    result = "{\"status\":\"success\"}";
        //} else {
        //    result = "{\"status\":\"error\"}";
        //}
        //res.set_content(result, "text/json");
    });

	//Require users to register 
  	cout << "Server listening on port " << port << endl;
  	svr.listen("0.0.0.0", port);

} // End main

