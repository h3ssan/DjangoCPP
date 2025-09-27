#include "djangocpp/app.h"

#include "djangocpp/routes.hpp"
#include "djangocpp/middleware.hpp"
#include "djangocpp/settings.h"

Application::Application(Handler handler) : handler{handler} {}

std::shared_ptr<Response> Application::operator()(std::shared_ptr<Request> req) const
{
    for (const auto &middleware : middlewares)
    {
        const auto &response = middleware->process_request(req);
        if (response != nullptr)
        {
            return response;
        }
    }

    return handler(req);
}

Application get_application()
{
    Router router;

    for (const auto &route : routes)
    {
        router.add_route(
            route.first.first,
            route.first.second,
            route.second);
    }

    Handler base = router.get_dispatcher();

    return Application(base);
}

Application get_shared_application()
{
    static Application app = get_application();
    return app;
}