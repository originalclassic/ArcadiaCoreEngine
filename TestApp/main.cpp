#include <iostream>
#include "ModuleManager.h"

int main() {
    ModuleManager manager;
    manager.LoadModule("Engine/Source/ArcadiaCore/Modules/ACEMemoryManager/ACEMemoryManager.amodule");

    // Example: Print a message indicating that the plugin loading test is complete
    std::cout << "Testing plugin loading..." << std::endl;

    return 0;
}
