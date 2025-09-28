#pragma once

#include "djangocpp/config.h"

#include <string>
#include <optional>
#include <vector>
#include <memory>

namespace djangocpp::config
{
    class CompositeConfig
    {
    private:
        std::vector<std::unique_ptr<ConfigSource>> sources;

    public:
        ~CompositeConfig() = default;

        void add_source(std::unique_ptr<ConfigSource> source);
        std::optional<std::string> get(const std::string &key) const;
    };
}
