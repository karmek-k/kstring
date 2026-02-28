#include "kstring.h"

inline SizeType strlen(const char* str)
{
    SizeType length = 0;

    for (SizeType i = 0; str[i] != '\0'; ++i)
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
        throw InvalidStringException{};

    sz = strlen(str) + 1;
    buffer = new char[sz];

    for (SizeType i = 0; i < sz; ++i)
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

    char* new_buffer = new char[other.sz];

    for (SizeType i = 0; i < other.sz; ++i)
       new_buffer[i] = other.buffer[i];

    delete[] buffer;
    buffer = new_buffer;
    sz = other.sz;

    return *this;
}

KString::KString(const KString& other)
    : sz(other.sz), buffer(new char[other.sz])
{
    for (SizeType i = 0; i < sz; ++i)
        buffer[i] = other.buffer[i];
}

KString& KString::operator=(KString&& other)
{
    if (this == &other)
        return *this;

    SizeType temp_sz = sz;
    sz = other.sz;
    other.sz = temp_sz;

    char* temp_buffer = buffer;
    buffer = other.buffer;
    other.buffer = temp_buffer;

    return *this;
}

KString::KString(KString&& other)
    : sz(other.sz), buffer(other.buffer)
{
    other.sz = 0;
    other.buffer = nullptr;
}

char KString::operator[](SizeType index) const
{
    if (index >= size())
        throw IndexOutOfRangeException{};

    return buffer[index];
}

char& KString::operator[](SizeType index)
{
    if (index >= size())
        throw IndexOutOfRangeException{};

    return buffer[index];
}

SizeType KString::size() const
{
    return sz == 0 ? sz : sz - 1;
}

KString& KString::operator+=(char c)
{
    SizeType new_sz = (sz == 0) ? 2 : sz + 1;
    char* new_buffer = new char[new_sz];

    if (buffer != nullptr)
    {
        for (SizeType i = 0; i < sz - 1; ++i)
            new_buffer[i] = buffer[i];

        delete[] buffer;
    }

    new_buffer[new_sz - 2] = c;
    new_buffer[new_sz - 1] = '\0';

    sz = new_sz;
    buffer = new_buffer;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const KString& kstring)
{
    if (kstring.buffer != nullptr)
        os << kstring.buffer;

    return os;
}
