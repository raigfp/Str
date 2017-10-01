#include "Str.h"

#include <cstring>
#include <cctype>
#include <memory>
#include <istream>
#include <ostream>
#include <algorithm>

using std::istream;
using std::ostream;

using std::strlen;
using std::uninitialized_copy;
using std::strncmp;
using std::max;

void Str::create() {
    data = avail = limit = 0;
}

void Str::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    avail = limit = uninitialized_copy(i, j, data);
}

void Str::create(const char* s) {
    create(s, s + strlen(s));
}

void Str::uncreate() {
    if (data) {
        iterator it = limit;
        while (it != data) {
            alloc.destroy(--it);
        }

        alloc.deallocate(data, limit - data);
    }

    data = avail = limit = 0;
}

void Str::grow() {
    size_type new_size = std::max(2 * (limit - data), std::ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

void Str::unchecked_append(const char& val) {
    alloc.construct(avail++, val);
}

Str& Str::operator=(const Str& rhs) {
    if (&rhs != this) {
        uncreate();

        create(rhs.begin(), rhs.end());
    }

    return *this;
}

Str& Str::operator+=(const Str& rhs) {
    for (Str::const_iterator iter = rhs.begin(); iter != rhs.end(); ++iter) {
        this->push_back(*iter);
    }

    return *this;
}

Str operator+(const Str& s1, const Str& s2) {
    Str s = s1;
    s += s2;
    return s;
}

std::ostream& operator<<(std::ostream& os, const Str& s) {
    for (Str::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
        os << *iter;
    }

    return os;
}

istream& operator>>(istream& is, Str& s) {
    s.clear();

    char c;
    while(is.get(c) && isspace(c)); // skip spaces

    if (is) {
        do s.push_back(c);
        while (is.get(c) && !isspace(c));

        if (is) {
            is.unget();
        }
    }

    return is;
}

bool operator>(const Str& lhs, const Str& rhs) {
    Str::size_type max_size = max(lhs.size(), rhs.size());
    return strncmp(lhs.begin(), rhs.begin(), max_size) > 0;
}

bool operator<(const Str& lhs, const Str& rhs) {
    Str::size_type max_size = max(lhs.size(), rhs.size());
    return strncmp(lhs.begin(), rhs.begin(), max_size) < 0;
}
