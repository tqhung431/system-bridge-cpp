#pragma once
#include <windows.h>

class ScopedHandle {
private:
    HANDLE handle = INVALID_HANDLE_VALUE;

public:
    // Use explicit constructor to prevent implicit conversions
    explicit ScopedHandle(HANDLE h = INVALID_HANDLE_VALUE) noexcept;
    ~ScopedHandle() noexcept;

    // Delete copy constructor and copy assignment operator to prevent copying
    ScopedHandle(const ScopedHandle&) = delete;
    ScopedHandle& operator=(const ScopedHandle&) = delete;

    // Move constructor and move assignment operator for ownership transfer
    ScopedHandle(ScopedHandle&& other) noexcept;
    ScopedHandle& operator=(ScopedHandle&& other) noexcept;

    HANDLE get() const noexcept;
    explicit operator bool() const noexcept;
}
