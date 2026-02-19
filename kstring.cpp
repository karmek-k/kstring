#include "kstring.h"

inline size_t strlen(const char* str)
{
    size_t length = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        ++length;

    return length;
}

KString::KString()
    : KString("")
{
}

KString::KString(const char* str)
{
    if (str == nullptr)
        throw "invalid string provided";

    sz = strlen(str) + 1;
    buffer = new char[sz];

    for (int i = 0; i < sz; ++i)
        buffer[i] = str[i];
}

KString::~KString()
{
    delete[] buffer;
    buffer = nullptr;
}

KString& KString::operator=(const KString& other)
{
    if (this == &other)
        return *this;

    sz = other.sz;
    delete[] buffer;
    buffer = new char[sz];

    for (int i = 0; i < sz; ++i)
       buffer[i] = other.buffer[i];

    return *this;
}

KString::KString(const KString& other)
{
    *this = other;
}

KString& KString::operator=(KString&& other)
{
    if (this == &other)
        return *this;

    sz = other.sz;
    delete[] buffer;
    buffer = other.buffer;

    other.sz = 0;
    other.buffer = nullptr;

    return *this;
}

KString::KString(KString&& other)
    : sz(other.sz), buffer(other.buffer)
{
    other.sz = 0;
    other.buffer = nullptr;
}

char KString::operator[](size_t index) const
{
    if (index > size())
        throw "index out of range";

    return buffer[index];
}

size_t KString::size() const
{
    return sz - 1;
}
