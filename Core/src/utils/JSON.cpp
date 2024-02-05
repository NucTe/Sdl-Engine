#include "SdlEngine/utils/JSON.h"

nlohmann::json JSON::ReadFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    std::string jsonString((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return nlohmann::json::parse(jsonString);
}

nlohmann::json JSON::ReadFromString(const std::string& jsonString) {
    return nlohmann::json::parse(jsonString);
}

void JSON::WriteToFile(const std::string& filePath, const nlohmann::json& jsonData) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + filePath);
    }

    file << std::setw(4) << jsonData;
}

std::string JSON::WriteToString(const nlohmann::json& jsonData) {
    return jsonData.dump(4);
}
