#define CATCH_CONFIG_MAIN

#include <cstring>
#include "catch.hpp"
#include "../src/Str.h"

using std::strcmp;

TEST_CASE("Str") {
    SECTION("Should construct object using default constructor") {
        Str str;
        REQUIRE(str.begin() == NULL);
        REQUIRE(str.end() == NULL);
    }

    SECTION("Should construct object using string literal constructor") {
        Str str("hello");

        REQUIRE(strncmp(str.begin(), "hello", str.size()) == 0);
    }

    SECTION("Should construct object using copy constructor") {
        Str str("hello");
        Str str_copy(str);

        REQUIRE(strncmp(str_copy.begin(), "hello", str_copy.size()) == 0);
    }

    SECTION("Should append another Str using `+=` operator") {
        Str str1("hello");
        Str str2("world");
        str1 += str2;

        REQUIRE(strncmp(str1.begin(), "helloworld", str1.size()) == 0);
    }

    SECTION("Should concat 2 Strs using `+` operator") {
        Str str1("hello");
        Str str2("world");
        Str str1str2  = str1 + str2;

        REQUIRE(strncmp(str1str2.begin(), "helloworld", str1str2.size()) == 0);
    }

    SECTION("Should push char using `push_back` member function") {
        Str str("hell");
        str.push_back('o');

        REQUIRE(strncmp(str.begin(), "hello", str.size()) == 0);
    }

    SECTION("Should clear string using `clear` member function") {
        Str str("hello");
        str.clear();

        REQUIRE(str.begin() == NULL);
        REQUIRE(str.end() == NULL);
    }

    SECTION("Should return lowercase string using `tolower` member function") {
        Str str("Hello");
        Str str_lower = str.tolower();

        REQUIRE(strncmp(str_lower.begin(), "hello", str_lower.size()) == 0);
    }

    SECTION("Should allow access to chars via `[]` operator") {
        Str str("hello");

        REQUIRE(str[0] == 'h');
        REQUIRE(str[4] == 'o');
    }

    SECTION("Should assign value via `=` operator") {
        Str str1("hello");
        Str str2("world");

        str2 = str1;

        REQUIRE(strncmp(str2.begin(), "hello", str2.size()) == 0);
    }
}
