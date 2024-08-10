#pragma once

#include <string>
#include <map>
#include <vector>

class JSONParser {
public:
    // Parses a JSON file and stores the data in internal structures
    bool parse(const std::string& filePath);

    // Getters for the parsed data
    std::string getString(const std::string& key) const;
    std::vector<std::string> getArray(const std::string& key) const;

    // Example function to handle dependencies
    std::vector<std::string> getDependencies() const;

private:
    // Helper methods
    void parseObject(const std::string& jsonString);
    std::string trim(const std::string& str) const;
    std::string extractValue(const std::string& str) const;
    std::vector<std::string> extractArray(const std::string& str) const;

    std::map<std::string, std::string> data_;
    std::map<std::string, std::vector<std::string>> arrayData_;
};
