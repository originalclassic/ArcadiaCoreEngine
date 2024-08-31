#include "FACEPoolAllocator.h"
#include <cstdlib>  // For malloc, free
#include <cassert>  // For assert
#include <cstring>  // For memset
#include <new>

FACEPoolAllocator::FACEPoolAllocator(size_t objectSize, size_t objectCount)
    : ACE_ObjectSize(objectSize), ACE_ObjectCount(objectCount), ACE_FreeCount(objectCount) {

    // Align object size to pointer size
    if (ACE_ObjectSize < sizeof(void*)) {
        ACE_ObjectSize = sizeof(void*);
    }

    // Allocate a large block of memory
    ACE_pMemoryBlock = std::malloc(ACE_ObjectSize * ACE_ObjectCount);
    if (!ACE_pMemoryBlock) {
        throw std::bad_alloc();
    }

    // Initialize the free list
    ACE_pFreeList = static_cast<void**>(ACE_pMemoryBlock);
    void** pCurrent = ACE_pFreeList;
    for (size_t i = 0; i < ACE_ObjectCount - 1; ++i) {
        *pCurrent = static_cast<void*>(static_cast<char*>(ACE_pMemoryBlock) + (i + 1) * ACE_ObjectSize);
        pCurrent = static_cast<void**>(*pCurrent);
    }
    *pCurrent = nullptr; // End of the list
}

FACEPoolAllocator::~FACEPoolAllocator() {
    std::free(ACE_pMemoryBlock);
}

void* FACEPoolAllocator::Allocate(size_t size) {
    if (size > ACE_ObjectSize || ACE_FreeCount == 0) {
        return nullptr; // Size is too big or no free blocks
    }

    // Get a block from the free list
    void* pAllocatedMemory = ACE_pFreeList;
    ACE_pFreeList = static_cast<void**>(*ACE_pFreeList);
    --ACE_FreeCount;
    return pAllocatedMemory;
}

void FACEPoolAllocator::Deallocate(void* pMemory) {
    if (pMemory == nullptr) {
        return;
    }

    // Add the block back to the free list
    void** pMemoryBlock = static_cast<void**>(pMemory);
    *pMemoryBlock = ACE_pFreeList;
    ACE_pFreeList = pMemoryBlock;
    ++ACE_FreeCount;
}
