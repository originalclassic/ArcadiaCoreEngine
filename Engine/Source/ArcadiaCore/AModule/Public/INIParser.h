#pragma once

#include <string>
#include <map>
#include <vector>

class INIParser {
public:
    // Parses an INI file and stores the data in internal structures
    bool parse(const std::string& filePath);

    // Getters for the parsed data
    std::vector<std::string> getCommaSeparatedList(const std::string& section, const std::string& key) const;

private:
    std::map<std::string, std::map<std::string, std::string>> data_;
};
