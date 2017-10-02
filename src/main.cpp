#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#include "Str.h"

using std::vector;

using std::cout;
using std::endl;
using std::cin;
using std::sort;
using std::min;
using std::tolower;

bool cmp(const Str& s1, const Str& s2) {
    Str::size_type min_size = min(s1.size(), s2.size());

    for (Str::size_type i = 0; i < min_size; ++i) {
        if (tolower(s1[i]) > tolower(s2[i])) {
            return true;
        }

        if (tolower(s1[i]) < tolower(s2[i])) {
            return false;
        }
    }

    return s1.size() > s2.size();
}

int main() {
    vector<Str> strings;

    Str s;
    while (cin >> s) {
        strings.push_back(s);
    }

    sort(strings.begin(), strings.end(), cmp);

    for (auto& string : strings) {
        cout << string << endl;
    }

    return 0;
}
