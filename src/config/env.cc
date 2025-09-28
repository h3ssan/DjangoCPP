#include "djangocpp/config/env.h"

#include <cstdlib>

using std::nullopt;
using std::optional;
using std::string;

optional<string> djangocpp::config::Env::get(const string &key) const
{
    const char *value = std::getenv(key.c_str());
    if (value == NULL)
    {
        return nullopt;
    }

    return string(value);
}