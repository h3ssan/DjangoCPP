#include "djangocpp/router.h"

void Router::add_route(const string &method, const string &path, Handler handler)
{
    routes.push_back({method, path, handler});
}

Handler Router::get_dispatcher() const
{
    return [routes = this->routes](std::shared_ptr<Request> req) -> std::shared_ptr<Response>
    {
        for (const auto &route : routes)
        {
            if (route.method == req->method && route.path == req->path)
            {
                return route.handler(req);
            }
        }

        return std::make_shared<Response>(Response{
            .status = 404,
            .headers = {{"Content-Type", "text/plain"}},
            .body = "Not Found"});
    };
}