#include "JSONParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool JSONParser::parse(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open JSON file: " << filePath << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // Remove surrounding braces
    if (content.front() == '{') content.erase(content.begin());
    if (content.back() == '}') content.erase(content.end() - 1);

    parseObject(content);

    return true;
}

void JSONParser::parseObject(const std::string& jsonString) {
    std::string::size_type start = 0;
    while (start < jsonString.size()) {
        // Find key
        auto keyStart = jsonString.find('"', start);
        if (keyStart == std::string::npos) break;
        auto keyEnd = jsonString.find('"', keyStart + 1);
        if (keyEnd == std::string::npos) break;
        std::string key = jsonString.substr(keyStart + 1, keyEnd - keyStart - 1);

        // Find value
        auto valueStart = jsonString.find(':', keyEnd) + 1;
        if (valueStart == std::string::npos) break;
        auto valueEnd = jsonString.find_first_of(",}", valueStart);
        std::string value = jsonString.substr(valueStart, valueEnd - valueStart);

        value = trim(value);
        if (value.front() == '"') value = extractValue(value);
        else if (value.front() == '[') arrayData_[key] = extractArray(value);
        else data_[key] = value;

        start = valueEnd;
    }
}

std::string JSONParser::trim(const std::string& str) const {
    auto start = str.find_first_not_of(" \n\r\t");
    auto end = str.find_last_not_of(" \n\r\t");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

std::string JSONParser::extractValue(const std::string& str) const {
    // Remove surrounding quotes
    return str.substr(1, str.size() - 2);
}

std::vector<std::string> JSONParser::extractArray(const std::string& str) const {
    std::vector<std::string> result;
    std::string trimmed = trim(str.substr(1, str.size() - 2)); // Remove surrounding brackets

    size_t start = 0;
    while (start < trimmed.size()) {
        auto end = trimmed.find(',', start);
        if (end == std::string::npos) end = trimmed.size();
        std::string value = trimmed.substr(start, end - start);
        result.push_back(trim(value));
        start = end + 1;
    }

    return result;
}

std::string JSONParser::getString(const std::string& key) const {
    auto it = data_.find(key);
    if (it != data_.end()) {
        return it->second;
    }
    return "";
}

std::vector<std::string> JSONParser::getArray(const std::string& key) const {
    auto it = arrayData_.find(key);
    if (it != arrayData_.end()) {
        return it->second;
    }
    return {};
}

std::vector<std::string> JSONParser::getDependencies() const {
    return getArray("dependencies");
}
