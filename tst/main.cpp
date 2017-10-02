#define CATCH_CONFIG_MAIN

#include <cstring>

#include "catch.hpp"
#include "../src/Str.h"

using std::strlen;

bool cmp(const Str& s1, const char* s2) {
    if (s1.size() != strlen(s2)) {
        return false;
    }

    for (Str::size_type i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }

    return true;
}

TEST_CASE("Str") {
    SECTION("Should construct object using default constructor") {
        Str str;
        REQUIRE(str.begin() == nullptr);
        REQUIRE(str.end() == nullptr);
    }

    SECTION("Should construct object using string literal constructor") {
        Str str("hello");

        REQUIRE(cmp(str, "hello"));
    }

    SECTION("Should construct object using copy constructor") {
        Str str("hello");
        Str str_copy(str);

        REQUIRE(cmp(str_copy, "hello"));
    }

    SECTION("Should append another Str using `+=` operator") {
        Str str1("hello");
        Str str2("world");
        str1 += str2;

        REQUIRE(cmp(str1, "helloworld"));
    }

    SECTION("Should concat 2 Strs using `+` operator") {
        Str str1("hello");
        Str str2("world");
        Str str1str2  = str1 + str2;

        REQUIRE(cmp(str1str2, "helloworld"));
    }

    SECTION("Should push char using `push_back` member function") {
        Str str("hell");
        str.push_back('o');

        REQUIRE(cmp(str, "hello"));
    }

    SECTION("Should clear string using `clear` member function") {
        Str str("hello");
        str.clear();

        REQUIRE(str.begin() == nullptr);
        REQUIRE(str.end() == nullptr);
    }

    SECTION("Should assign value via `=` operator") {
        Str str1("hello");
        Str str2("world");

        str2 = str1;

        REQUIRE(cmp(str2, "hello"));
    }
}
