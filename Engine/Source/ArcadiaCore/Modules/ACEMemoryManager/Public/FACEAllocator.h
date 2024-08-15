#pragma once
#include <cstddef> // For size_t

class FACEAllocator {
public:
    virtual ~FACEAllocator() = default;

    virtual void* Allocate(size_t size) = 0;
    virtual void Deallocate(void* pMemory) = 0;
};
