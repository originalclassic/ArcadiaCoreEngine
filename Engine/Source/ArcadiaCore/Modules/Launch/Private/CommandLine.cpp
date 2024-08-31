// CommandLine.cpp
#include "CommandLine.h"

CommandLine& CommandLine::Get() {
    static CommandLine instance;
    return instance;
}

void CommandLine::Initialize(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        size_t equalPos = arg.find('=');
        if (equalPos != std::string::npos) {
            std::string key = arg.substr(0, equalPos);
            std::string value = arg.substr(equalPos + 1);
            arguments[key] = value;
        } else {
            arguments[arg] = "";
        }
    }
}

bool CommandLine::HasArgument(const std::string& arg) const {
    return arguments.find(arg) != arguments.end();
}
