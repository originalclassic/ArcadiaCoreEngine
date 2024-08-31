#include "JSONParser.h"
#include <fstream>
#include <sstream>


#include "../../Modules/ACELogger/Public/ACELogger.h"

/**
 * \brief Parses a JSON file and stores the data in internal structures.
 * \param filePath The path to the JSON file.
 * \return True if the parsing was successful, false otherwise.
 */
bool JSONParser::parse(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        ACELogger::GetInstance().Log("Failed to open JSON file: " + filePath, LogLevel::Error);
        return false;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // Log the raw content of the JSON file for debugging purposes
    ACELogger::GetInstance().Log("Parsing JSON content: " + content, LogLevel::Debug);

    // Remove surrounding braces
    if (content.front() == '{') content.erase(content.begin());
    if (content.back() == '}') content.erase(content.end() - 1);

    parseObject(content);

    ACELogger::GetInstance().Log("Successfully parsed JSON file: " + filePath, LogLevel::Info);
    return true;
}

/**
 * @brief Parses a JSON object from the given string and stores the data in internal structures.
 *
 * This method parses a JSON object from the given string and extracts key-value pairs from it.
 * Each key-value pair is then stored in the internal data structures of the JSONParser class.
 * The JSON object is expected to be a valid JSON syntax with properly formatted keys and values.
 *
 * @param jsonString The string representation of the JSON object to parse.
 */
void JSONParser::parseObject(const std::string& jsonString) {
    std::string::size_type start = 0;
    while (start < jsonString.size()) {
        // Find key
        auto keyStart = jsonString.find('"', start);
        if (keyStart == std::string::npos) break;
        auto keyEnd = jsonString.find('"', keyStart + 1);
        if (keyEnd == std::string::npos) break;
        std::string key = jsonString.substr(keyStart + 1, keyEnd - keyStart - 1);

        // Log the extracted key for debugging
        ACELogger::GetInstance().Log("Extracted key: " + key, LogLevel::Debug);

        // Find value
        auto valueStart = jsonString.find(':', keyEnd) + 1;
        if (valueStart == std::string::npos) break;
        auto valueEnd = jsonString.find_first_of(",}", valueStart);
        std::string value = jsonString.substr(valueStart, valueEnd - valueStart);

        value = trim(value);
        if (value.front() == '"') value = extractValue(value);
        else if (value.front() == '[') arrayData_[key] = extractArray(value);
        else data_[key] = value;

        // Log the key-value pair for debugging
        ACELogger::GetInstance().Log("Parsed key-value pair: " + key + " : " + value, LogLevel::Debug);

        start = valueEnd;
    }
}

/**
 * @param str The string to be trimmed.
 * @return The trimmed string.
 */
std::string JSONParser::trim(const std::string& str) const {
    auto start = str.find_first_not_of(" \n\r\t");
    auto end = str.find_last_not_of(" \n\r\t");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

/**
 * @brief Extracts the value from a string by removing the surrounding quotes.
 *
 * @param str The string to extract the value from.
 * @return The extracted value.
 */
std::string JSONParser::extractValue(const std::string& str) const {
    // Remove surrounding quotes
    return str.substr(1, str.size() - 2);
}

/**
 * @brief Extracts elements from a JSON array string.
 *
 * This method takes a JSON array string and extracts the individual elements,
 * removing any leading or trailing whitespace, and returns them in a vector of strings.
 *
 * @param str The JSON array string to extract elements from.
 * @return A vector of strings containing the extracted elements.
 */
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

/**
 * @brief Retrieves a string value associated with the given key from the internal data structure.
 *
 * The method searches for the key in the internal `data_` map. If the key is found, the associated
 * string value is returned. If the key is not found, an empty string is returned.
 *
 * @param key The key to search for in the internal `data_` map.
 * @return The string value associated with the given key, or an empty string if the key is not found.
 */
std::string JSONParser::getString(const std::string& key) const {
    auto it = data_.find(key);
    if (it != data_.end()) {
        return it->second;
    }
    ACELogger::GetInstance().Log("Key not found: " + key, LogLevel::Warning);
    return "";
}

/**
 * @brief Gets the array associated with the specified key.
 *
 * If the key is found in the internal data structure, the array
 * associated with it is returned. Otherwise, an empty array is
 * returned.
 *
 * @param key The key to look for in the internal data structure.
 * @return The array associated with the specified key.
 */
std::vector<std::string> JSONParser::getArray(const std::string& key) const {
    auto it = arrayData_.find(key);
    if (it != arrayData_.end()) {
        return it->second;
    }
    ACELogger::GetInstance().Log("Array key not found: " + key, LogLevel::Warning);
    return {};
}

/**
 * \brief Get the dependencies of the parsed JSON data.
 *
 * This method retrieves the dependencies stored in the parsed JSON data
 * and returns them as a vector of strings.
 *
 * \return A vector of strings containing the dependencies.
 */
std::vector<std::string> JSONParser::getDependencies() const {
    return getArray("dependencies");
}
