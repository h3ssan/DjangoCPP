#include "http.h"

#include "app.h"
#include "settings.h"

void handle_request(const httplib::Request &req, httplib::Response &res)
{
    auto request = std::make_shared<Request>(Request{
        .method = req.method,
        .path = req.path,
        .headers = {},
        .body = req.body});
    for (const auto &header : req.headers)
    {
        request->headers[header.first] = header.second;
    }

    Application app = get_shared_application();
    std::shared_ptr<Response> response = app(request);

    res.status = response->status;
    for (const auto &header : response->headers)
    {
        res.set_header(header.first, header.second);
    }
    res.body = response->body;
}

void run_server()
{
    httplib::Server svr;

    svr.Get(".*", handle_request);
    svr.Post(".*", handle_request);
    svr.Put(".*", handle_request);
    svr.Patch(".*", handle_request);
    svr.Delete(".*", handle_request);
    svr.Options(".*", handle_request);

    std::cout << "Starting server at http://" << Settings::Server::HOST << ":" << Settings::Server::PORT << std::endl;
    svr.listen(Settings::Server::HOST.c_str(), Settings::Server::PORT);
}
