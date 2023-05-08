#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>


#include "httplib.h"
#include "dynamicArtDB.h"
#include "dynamicArtInfo.h"

using namespace httplib;
using namespace std;
using json = nlohmann::json;

const int port = 5005;

dynamicArtDB obj; // Create a global instance of the dynamicArtDB class

int main() {
	httplib::Server svr;
    // Vector to store applicable emotions
	vector<std::string> emotions = {"Happiness", "Sadness", "Fear", "Disgust", "Anger", "Surprise"};
	
	// API to get the percentages of each emotion from the responses database
	svr.Get(R"(/dynamicArt/getEmotionPercentages/)", [&](const Request& req, Response& res) {
		res.set_header("Access-Control-Allow-Origin", "*");
		json result;

		for (const auto& e : emotions) {
			int count = obj.getEmotionCount(e);
			result[e] = count;
		}
		res.set_content(result.dump(), "application/json");
	});

    svr.listen("localhost", 8080);

    return 0;
}
