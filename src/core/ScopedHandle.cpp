#include "ScopedHandle.hpp"
#include <utility> // for std::exchange

ScopedHandle::ScopedHandle(HANDLE h) noexcept : handle(h) {}

ScopedHandle::~ScopedHandle() noexcept {
    if (handle != INVALID_HANDLE_VALUE && handle != nullptr) {
        CloseHandle(handle);
    }
}

ScopedHandle::ScopedHandle(ScopedHandle&& other) noexcept : handle(std::exchange(other.handle, INVALID_HANDLE_VALUE)) {}

ScopedHandle& ScopedHandle::operator=(ScopedHandle&& other) noexcept {
    if (this != &other) {
        if (handle != INVALID_HANDLE_VALUE && handle != nullptr) {
            CloseHandle(handle);
        }
        handle = std::exchange(other.handle, INVALID_HANDLE_VALUE);
    }

    return *this;
}

HANDLE ScopedHandle::get() const noexcept {
    return handle;
}

ScopedHandle::operator bool() const noexcept {
    return handle != INVALID_HANDLE_VALUE && handle != nullptr;
}