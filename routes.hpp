#include "http.h"

std::map<std::pair<std::string, std::string>, Handler> routes = {
    { {"GET", "/"}, [](std::shared_ptr<Request> req) {
        return std::make_shared<Response>(Response {
            .status = 200,
            .headers = { {"Content-Type", "text/plain"} },
            .body = "Hello, World!"
        });
    }},
    { {"GET", "/whoami"}, [](std::shared_ptr<Request> req) {
        return std::make_shared<Response>(Response {
            .status = 200,
            .headers = { {"Content-Type", "text/plain"} },
            .body = "DjangoCPP"
        });
    }}
};