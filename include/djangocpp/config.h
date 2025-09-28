#pragma once

#include <string>
#include <optional>

namespace djangocpp::config
{
    class ConfigSource
    {
    public:
        virtual ~ConfigSource() = default;

        virtual std::optional<std::string> get(const std::string &key) const = 0;
    };
}
