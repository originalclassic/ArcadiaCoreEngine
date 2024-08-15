// src/BuildTool.cpp
#include "BuildTool.h"
#include "BuildFileParser.h"
#include <iostream>
#include <cstdlib> //For System()

void BuildTool::Run(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: BuildTool <path to .Build.cs file>" << std::endl;
        return;
    }

    BuildFileParser parser;
    parser.Parse(argv[1]);


    std::system("g++ -c src/BuildTool.cpp -o BuildTool.o");
    std::system("g++ -c src/BuildFileParser.cpp -o BuildFileParser.o");
    std::system("g++ BuildTool.o BuildFileParser.o -o BuildTool");

    // TODO: Implement the build process using parsed data
}
