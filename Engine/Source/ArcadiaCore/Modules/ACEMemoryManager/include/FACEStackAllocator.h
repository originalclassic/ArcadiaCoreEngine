#pragma once
#include "FACEAllocator.h"
#include <cstddef> // For size_t

class FACEStackAllocator : public FACEAllocator {
public:
    explicit FACEStackAllocator(size_t size);
    ~FACEStackAllocator() override;

    void* Allocate(size_t size) override;
    void Deallocate(void* pMemory) override;

private:
    void* ACE_pMemoryBlock;   // Pointer to the start of the allocated memory
    size_t ACE_TotalSize;     // Total size of the memory block
    size_t ACE_Offset;        // Current offset in the memory block

    // Disallow copying
    FACEStackAllocator(const FACEStackAllocator&) = delete;
    FACEStackAllocator& operator=(const FACEStackAllocator&) = delete;
};
