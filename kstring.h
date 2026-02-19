#pragma once

#include <iostream>

// size_t is already defined in the iostream header
using SizeType = unsigned long long;

class KString
{
    SizeType sz = 0;
    char* buffer = nullptr;
public:
    /**
     * Constructs an empty KString.
     */
    KString();

    /**
     * Constructs a KString from an array of chars.
     */
    KString(const char* str);

    ~KString();
    KString(const KString& other);
    KString& operator=(const KString& other);
    KString(KString&& other);
    KString& operator=(KString&& other);

    /**
     * Returns the character at the specified index.
     */
    char operator[](SizeType index) const;

    /**
     * Returns the size of the KString, excluding the final null-byte.
     */
    SizeType size() const;
};

/**
 * Transfers all KString characters into the output stream,
 * one after the other.
 */
std::ostream& operator<<(std::ostream& os, const KString& kstring);
