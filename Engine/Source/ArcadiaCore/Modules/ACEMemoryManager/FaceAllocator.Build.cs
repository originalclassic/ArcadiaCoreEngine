// FACEAllocator.Build.cs

using System;
using System.IO;

public class FACEAllocator : ModuleRules
{
    public FACEAllocator(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.StaticLibrary;
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                "Engine/Source/ArcadiaCore/Modules/FACEAllocator/Public"
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
                "Engine/Source/ArcadiaCore/Modules/FACEAllocator/Private"
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "ACELogger"
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
