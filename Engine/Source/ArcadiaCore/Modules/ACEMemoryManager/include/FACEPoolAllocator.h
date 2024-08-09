#pragma once
#include "FACEAllocator.h"
#include <cstddef> // For size_t

class FACEPoolAllocator : public FACEAllocator {
public:
    FACEPoolAllocator(size_t objectSize, size_t objectCount);
    ~FACEPoolAllocator() override;

    void* Allocate(size_t size) override;
    void Deallocate(void* pMemory) override;

private:
    void* ACE_pMemoryBlock;  // Pointer to the start of the memory block
    void** ACE_pFreeList;    // Pointer to the list of free blocks
    size_t ACE_ObjectSize;   // Size of each object
    size_t ACE_ObjectCount;  // Number of objects in the pool
    size_t ACE_FreeCount;    // Number of free blocks available

    // Disallow copying
    FACEPoolAllocator(const FACEPoolAllocator&) = delete;
    FACEPoolAllocator& operator=(const FACEPoolAllocator&) = delete;
};
