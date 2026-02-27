#include "kstring.h"
#include <cassert>
#include <utility>

//
// Write your own string class:
//
// Do not use elements from the standard library.
//
// The class should be able to create an object
// based on a passed string constant.
//
// The class should have a method that returns the length of the string.
//
// The class should have an index operator that returns
// the specified letter.
//
// The class should have an operator method that allows
// adding additional characters to the string.
//
// Stream operators should be defined that
// allow objects to be output to the screen or to a file.
//

int main()
{
    {
        // KString()
        KString str;
        assert(str.size() == 0);
    }

    {
        // KString(const char*)
        KString str("abcde");
        assert(str.size() == 5);
        assert(str[0] == 'a');
        assert(str[4] == 'e');
    }

    {
        KString str("abcde");

        // KString(const KString&)
        KString str_copy(str);
        assert(str_copy.size() == 5);
        assert(str[0] == str_copy[0]);
    }

    {
        KString str("abcde");

        // KString(KString&&)
        KString str_move(std::move(str));
        assert(str_move.size() == 5);
    }

    {
        // operator<<
        KString str("aaaAAAbbb");
        std::cout << str << "\n";
    }

    {
        // operator+=
        KString str("aa");
        assert(str.size() == 2);

        str += 'b';
        assert(str.size() == 3);
        assert(str[2] == 'b');

        std::cout << str << "\n";
    }

    {
        // operator+= empty string
        KString str;
        assert(str.size() == 0);

        str += 'b';
        assert(str.size() == 1);
        assert(str[0] == 'b');
    }

    {
        // operator[]
        KString str("aa");
        assert(str[1] == 'a');

        str[1] = 'b';
        assert(str[1] == 'b');
    }
}
