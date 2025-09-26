#include "http.h"

class Middleware
{
public:
    virtual ~Middleware() = default;

    virtual std::shared_ptr<Response> process_request(std::shared_ptr<Request> req) { return nullptr; }
};

// Example middleware that logs requests

class LoggingMiddleware : public Middleware
{
public:
    std::shared_ptr<Response> process_request(std::shared_ptr<Request> req) override
    {
        std::cout << "[LOG] Incoming " << req->method << " " << req->path << '\n';

        return nullptr;
    }
};

// List of installed middleware instances

const std::vector<std::shared_ptr<Middleware>> middlewares = {
    std::make_shared<LoggingMiddleware>(),
};
