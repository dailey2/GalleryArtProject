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


string getusersJSON(string username, map<string,vector<string>> &messageMap) {
	/* retrieve json list of messages for this user */
	bool first = true;
	string result = ",\"users\":[";
	for (auto const& message :  messageMap) {
		if (not first) result += ",";
		result+="\"";
		result += message.first;
		result +="\"";
		first = false;;
	}
	result += "]}";
	messageMap[username].clear();
	return result;
}


int main(void) {
	Server svr;
	userDB udb;
	
	bool usernameSuccess = false;
	bool emailSuccess = false;
	bool passwordSuccess = false;

  	//bool registered = false;

  	/* "/" just returnsAPI name */
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
		vector<string> empty;
   		
   		if(udb.usernameExists(username) && ubd.passwordExists(password)){
   			ubd.logInUser(username,password);
			result = "{\"status\":\"success\",\"user\":\""+username+"\"}";
			res.set_content(result, "text/json");
		}else{
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
		
  	});

	
	//Service to register new users
   	svr.Get(R"(/artProject/register/(.*)/(.*)/(.*)/(.*)/(.*))", [&](const Request& req, Response& res) {
		
		res.set_header("Access-Control-Allow-Origin","*");
		string first = req.matches[1];
		string last = req.matches[2];
		string email = req.matches[3];
		string username = req.matches[4]
		string password = req.matches[5];
		
		// Check to see if username or email exists before completing registration
		if (!usernameExists(username) && !emailExists(email) && password.length() > 6){
			usernameSuccess = true;
			emailSuccess = true;
			passwordSuccess = true;
			udb.registerUser(first,last,email,username,password);
		}
		string result;

		if(usernameSuccess && emailSuccess && passwordSuccess){
			result = "{\"status\":\"success\"}";
		}else{
			result = "{\"status\":\"error\"}";
		}    
		res.set_content(result, "text/json");
  	});

	//Require users to register 
  	cout << "Server listening on port " << port << endl;
  	svr.listen("0.0.0.0", port);

} // End main