#ifndef STR_H
#define STR_H

#include <memory>
#include <istream>
#include <ostream>

class Str {
public:
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef std::size_t size_type;

    Str() { create(); }
    Str(const char* s) { create(s); }
    Str(const Str& s) { create(s.begin(), s.end()); }
    ~Str() { uncreate(); }

    size_type size() const { return avail - data; }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    void push_back(const char& val) {
        if (avail == limit) {
            grow();
        }

        unchecked_append(val);
    }
    void clear() { uncreate(); }
    Str tolower() const {
        Str s(*this);

        for (Str::iterator iter = s.begin(); iter != s.end(); ++iter) {
            *iter = std::tolower(*iter);
        }

        return s;
    }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    Str& operator=(const Str&);
    Str& operator+=(const Str&);

private:
    iterator data;
    iterator avail;
    iterator limit;

    std::allocator<char> alloc;

    void create();
    void create(const char*);
    void create(const_iterator, const_iterator);
    void uncreate();

    void grow();
    void unchecked_append(const char& val);
};

Str operator+(const Str&, const Str&);
std::ostream& operator<<(std::ostream&, const Str&);
std::istream& operator>>(std::istream&, Str&);
bool operator>(const Str&, const Str&);
bool operator<(const Str&, const Str&);

#endif // STR_H
