#pragma once

using size_t = unsigned long long;

class KString
{
    size_t sz;
    char* buffer;
public:
    /**
     * Constructs an empty KString.
     */
    KString() = default;

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
    char operator[](size_t index) const;

    /**
     * Returns the size of the KString, excluding the final null-byte.
     */
    size_t size() const;
};
