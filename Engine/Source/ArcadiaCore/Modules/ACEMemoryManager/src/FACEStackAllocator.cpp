#include "FACEStackAllocator.h"
#include <cstdlib>  // For malloc, free
#include <cassert>  // For assert
#include <new>

FACEStackAllocator::FACEStackAllocator(size_t size)
    : ACE_TotalSize(size), ACE_Offset(0) {
    ACE_pMemoryBlock = std::malloc(size);
    if (!ACE_pMemoryBlock) {
        throw std::bad_alloc();
    }
}

FACEStackAllocator::~FACEStackAllocator() {
    std::free(ACE_pMemoryBlock);
}

void* FACEStackAllocator::Allocate(size_t size) {
    if (ACE_Offset + size > ACE_TotalSize) {
        return nullptr; // Not enough space
    }
    void* pAllocatedMemory = static_cast<char*>(ACE_pMemoryBlock) + ACE_Offset;
    ACE_Offset += size;
    return pAllocatedMemory;
}

void FACEStackAllocator::Deallocate(void* /*pMemory*/) {
    // Stack allocators do not support deallocation of individual blocks
}
