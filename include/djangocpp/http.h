#pragma once

#include <string>
#include <map>
#include <functional>

#include "httplib.h"
#include "settings.h"

using std::string;
using std::map;

struct Request {
    string method;
    string path;
    map<string, string> headers;
    string body;
};

struct Response {
    int status;
    map<string, string> headers;
    string body;
};

using Handler = std::function<std::shared_ptr<Response>(std::shared_ptr<Request> req)>;

void run_server();

void handle_request(const httplib::Request& req, httplib::Response& res);