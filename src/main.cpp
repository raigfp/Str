#include "Str.h"

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

using std::cout;
using std::endl;
using std::cin;
using std::sort;

bool compare(const Str& s1, const Str& s2) {
    return s1.tolower() > s2.tolower();
}

int main() {
    vector<Str> strings;

    Str s;
    while (cin >> s) {
        strings.push_back(s);
    }

    sort(strings.begin(), strings.end(), compare);

    for (vector<Str>::const_iterator iter = strings.begin(); iter != strings.end(); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}
