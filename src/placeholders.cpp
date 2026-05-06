/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

// Этот файл распространяется под лицензией Mozilla Public License 2.0.

#include <Types.hpp>

extern "C" void __cxa_pure_virtual() { while (1); }
inline void* operator new(UINT64, LPVOID ptr) noexcept {
    return ptr;
}

inline void operator delete(LPVOID, LPVOID) noexcept {
    // Ничего не делаем, так как placement delete не нужен
}