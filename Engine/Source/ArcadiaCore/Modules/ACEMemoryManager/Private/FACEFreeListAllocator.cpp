#include "FACEFreeListAllocator.h"
#include <cstdlib>  // For malloc, free
#include <cassert>  // For assert
#include <cstring>  // For memset
#include <new>      // For std::bad_alloc

FACEFreeListAllocator::FACEFreeListAllocator(size_t blockSize, size_t blockCount)
    : ACE_BlockSize(blockSize), ACE_BlockCount(blockCount), ACE_FreeCount(blockCount) {

    // Align block size to pointer size
    if (ACE_BlockSize < sizeof(void*)) {
        ACE_BlockSize = sizeof(void*);
    }

    // Allocate a large block of memory
    ACE_pMemoryBlock = std::malloc(ACE_BlockSize * ACE_BlockCount);
    if (!ACE_pMemoryBlock) {
        throw std::bad_alloc();
    }

    // Initialize the free list
    ACE_pFreeList = static_cast<void**>(ACE_pMemoryBlock);
    void** pCurrent = ACE_pFreeList;
    for (size_t i = 0; i < ACE_BlockCount - 1; ++i) {
        *pCurrent = static_cast<void*>(static_cast<char*>(ACE_pMemoryBlock) + (i + 1) * ACE_BlockSize);
        pCurrent = static_cast<void**>(*pCurrent);
    }
    *pCurrent = nullptr; // End of the list
}

FACEFreeListAllocator::~FACEFreeListAllocator() {
    std::free(ACE_pMemoryBlock);
}

void* FACEFreeListAllocator::Allocate(size_t size) {
    if (size > ACE_BlockSize || ACE_FreeCount == 0) {
        return nullptr; // Size is too big or no free blocks
    }

    // Get a block from the free list
    void* pAllocatedMemory = ACE_pFreeList;
    ACE_pFreeList = static_cast<void**>(*ACE_pFreeList);
    --ACE_FreeCount;
    return pAllocatedMemory;
}

void FACEFreeListAllocator::Deallocate(void* pMemory) {
    if (pMemory == nullptr) {
        return;
    }

    // Add the block back to the free list
    void** pMemoryBlock = static_cast<void**>(pMemory);
    *pMemoryBlock = ACE_pFreeList;
    ACE_pFreeList = pMemoryBlock;
    ++ACE_FreeCount;
}
