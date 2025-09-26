#pragma once

#include "http.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Router
{
    struct Route
    {
        string method;
        string path;
        Handler handler;
    };
    vector<Route> routes;

public:
    void add_route(const string &method, const string &path, Handler handler);

    Handler get_dispatcher() const;
};