#ifndef CONFIG_H
#define CONFIG_H

#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

class Config {
private:
    json conf;
public:
    Config (const std::string& path = "config/config.json");
    std::string operator[] (const std::string& key) const;

    template <typename T>
    T get (const std::string& key) const;

    json get_config () const;
};

template <typename T>
T Config::get (const std::string& key) const {
    auto it = conf.find(key);

    if (it == conf.end())
        throw std::invalid_argument("No value for " + key + " key");

    return it->get<T>();
}

extern Config config;

#endif // CONFIG_H