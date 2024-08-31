// Engine/Source/ArcadiaCore/Public/Memory/Memory.h
#pragma once

#include <memory>

// Memory allocation and smart pointers
template<typename T>
using TSharedPtr = std::shared_ptr<T>;

template<typename T>
using TUniquePtr = std::unique_ptr<T>;
