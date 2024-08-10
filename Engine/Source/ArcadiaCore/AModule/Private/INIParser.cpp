#include "INIParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

bool INIParser::parse(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    std::string currentSection;
    while (std::getline(file, line)) {
        // Remove leading and trailing whitespace
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        if (line.empty() || line[0] == ';') {
            continue; // Skip empty lines and comments
        }

        if (line[0] == '[' && line.back() == ']') {
            // Section header
            currentSection = line.substr(1, line.size() - 2);
        } else {
            // Key-value pair
            size_t equalPos = line.find('=');
            if (equalPos != std::string::npos) {
                std::string key = line.substr(0, equalPos);
                std::string value = line.substr(equalPos + 1);

                // Remove leading and trailing whitespace
                key.erase(0, key.find_first_not_of(" \t"));
                key.erase(key.find_last_not_of(" \t") + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);

                if (!currentSection.empty()) {
                    data_[currentSection][key] = value;
                }
            }
        }
    }

    return true;
}

std::vector<std::string> INIParser::getCommaSeparatedList(const std::string& section, const std::string& key) const {
    std::vector<std::string> result;
    auto sectionIt = data_.find(section);
    if (sectionIt != data_.end()) {
        auto keyIt = sectionIt->second.find(key);
        if (keyIt != sectionIt->second.end()) {
            std::string value = keyIt->second;

            // Split the value by commas
            std::stringstream ss(value);
            std::string item;
            while (std::getline(ss, item, ',')) {
                // Remove leading and trailing whitespace
                item.erase(0, item.find_first_not_of(" \t"));
                item.erase(item.find_last_not_of(" \t") + 1);
                if (!item.empty()) {
                    result.push_back(item);
                }
            }
        }
    }
    return result;
}
