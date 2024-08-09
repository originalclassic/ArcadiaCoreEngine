#pragma once
#include "FACEAllocator.h"
#include <cstddef> // For size_t

class FACEFreeListAllocator : public FACEAllocator {
public:
    FACEFreeListAllocator(size_t blockSize, size_t blockCount);
    ~FACEFreeListAllocator() override;

    void* Allocate(size_t size) override;
    void Deallocate(void* pMemory) override;

private:
    void* ACE_pMemoryBlock;   // Pointer to the start of the memory block
    void** ACE_pFreeList;     // Pointer to the list of free blocks
    size_t ACE_BlockSize;     // Size of each block
    size_t ACE_BlockCount;    // Number of blocks
    size_t ACE_FreeCount;     // Number of free blocks

    // Disallow copying
    FACEFreeListAllocator(const FACEFreeListAllocator&) = delete;
    FACEFreeListAllocator& operator=(const FACEFreeListAllocator&) = delete;
};
