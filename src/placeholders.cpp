#include <Types.hpp>

extern "C" void __cxa_pure_virtual() { while (1); }
inline void* operator new(UINT64, LPVOID ptr) noexcept {
    return ptr;
}

inline void operator delete(LPVOID, LPVOID) noexcept {
    // Ничего не делаем, так как placement delete не нужен
}