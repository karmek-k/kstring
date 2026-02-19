#include "kstring.h"

KString::KString(const char* str)
{
    if (str == nullptr)
        throw "invalid string provided";

    sz = sizeof(str) / sizeof(char);
    buffer = new char[sz];
}

std::size_t KString::size() const
{
    return sz - 1;  // excluding the null-byte
}
