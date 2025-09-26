#pragma once

#include <memory>

#include "http.h"
#include "router.h"
#include "settings.h"

class Application
{
    Handler handler;

public:
    Application(Handler handler);

    std::shared_ptr<Response> operator()(std::shared_ptr<Request> req) const;
};

Application get_application();

Application get_shared_application();