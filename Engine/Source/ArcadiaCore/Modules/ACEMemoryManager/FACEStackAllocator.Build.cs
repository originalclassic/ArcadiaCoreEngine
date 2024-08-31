// FACEStackAllocator.Build.cs

using System;
using System.IO;

public class FACEStackAllocator : ModuleRules
{
    public FACEStackAllocator(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.StaticLibrary;
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                "Engine/Source/ArcadiaCore/Modules/FACEStackAllocator/Public"
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
                "Engine/Source/ArcadiaCore/Modules/FACEStackAllocator/Private"
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "ACELogger",
                "FACEAllocator" // Depends on the FACEAllocator module
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                // Add private dependencies if needed
            }
        );

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicDependencyModuleNames.Add("WindowsPlatform");
        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            PublicDependencyModuleNames.Add("LinuxPlatform");
        }
    }
}
