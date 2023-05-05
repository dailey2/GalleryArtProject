#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

#include "httplib.h"
#include "dynamicArtDB.h"
#include "dynamicArtInfo.h"

using namespace httplib;
using namespace std;

const int port = 5005;

dynamicArtDB obj; // Create a global instance of the dynamicArtDB class

int main() {
    httplib::Server svr;

    svr.Get("/dynamicArt/getEmotionPercentages", [&](const httplib::Request& req, httplib::Response& res) {
        obj.getEmotionCount(""); // Call the getEmotionCount method to populate the percentages map

        // Build a JSON object from the emotionPercentages map
        json result;
        for (const auto &entry : myDatabase.emotionPercentages) {
            result[entry.first] = entry.second;
        }

        res.set_content(result.dump(), "application/json");
    });

    svr.listen("localhost", 8080);

    return 0;
}