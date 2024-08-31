// CommandLine.h
#pragma once
#include <string>
#include <unordered_map>

class CommandLine {
public:
    static CommandLine& Get();

    void Initialize(int argc, char* argv[]);
    bool HasArgument(const std::string& arg) const;

private:
    CommandLine() = default;
    std::unordered_map<std::string, std::string> arguments;
};
