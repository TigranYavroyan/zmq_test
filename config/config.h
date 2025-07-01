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
    json get_config () const;
};

extern Config config;

#endif // CONFIG_H