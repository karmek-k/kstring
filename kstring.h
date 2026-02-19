#pragma once

#include <cstddef>

class KString
{
public:
    /**
     * Constructs an empty KString.
     */
    KString() = default;

    /**
     * Constructs a KString from an array of chars.
     */
    KString(const char* str);

    /**
     * Returns the character at the specified index.
     */
    char operator[](std::size_t index) const;

    /**
     * Returns the size of the KString.
     */
    std::size_t size() const;
};
