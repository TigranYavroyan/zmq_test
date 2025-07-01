#include <config.h>
#include <errno.h>
#include <iostream>

Config::Config (const std::string& path) {
    std::ifstream conf_file(path);

    if (!conf_file.is_open())
        throw std::invalid_argument(strerror(errno));

    conf = json::parse(conf_file);
}

std::string Config::operator[] (const std::string& key) const {
    auto it = conf.find(key);

    if (it == conf.end())
        throw std::invalid_argument("No value for " + key + " key");

    if (it->is_string())
        return it->get<std::string>();
    else
        return it->dump();  // For non-strings, get string form
}

nlohmann::json Config::get_config () const {
    return conf;
}
