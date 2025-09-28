#include "djangocpp/config/composite.h"

using std::nullopt;
using std::optional;
using std::string;
using std::unique_ptr;
using std::vector;

void djangocpp::config::CompositeConfig::add_source(unique_ptr<ConfigSource> source)
{
    sources.emplace_back(std::move(source));
}

optional<string> djangocpp::config::CompositeConfig::get(const string &key) const
{
    for (const auto &source : sources)
    {
        auto value = source->get(key);
        if (value.has_value())
        {
            return value;
        }
    }

    return nullopt;
}