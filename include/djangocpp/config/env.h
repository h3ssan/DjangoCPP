#pragma once

#include "djangocpp/config.h"

#include <string>
#include <optional>

namespace djangocpp::config
{
    class Env : public ConfigSource
    {
    public:
        std::optional<std::string> get(const std::string &key) const override;
    };
}
