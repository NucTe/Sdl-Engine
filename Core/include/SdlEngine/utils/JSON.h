#pragma once

#include <fstream>
#include <nlohmann/json.hpp>

class JSON {
public:
    JSON() = default;
    ~JSON() = default;
    nlohmann::json ReadFromFile(const std::string& filePath);
    nlohmann::json ReadFromString(const std::string& jsonString);

    void WriteToFile(const std::string& filePath, const nlohmann::json& jsonData);
    std::string WriteToString(const nlohmann::json& jsonData);
};
