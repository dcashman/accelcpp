#include <vector>

#include "Str.h"

using namespace std;

Str::Str() {
    create();
}

Str::Str(const char *cp) {
        // must be NULL terminated!
        create(strlen(cp));
        memcpy(data, cp, strlen(cp));
}

Str::Str(size_type n, char c) {
    create(n, c);
};


template <class In> Str::Str(In b, In e) {
    create(e - b);
    Str::iterator it = data;
    while (b != e)
       *it++ = *b++;
}

Str::iterator Str::begin() {
    return data;
}

Str::iterator Str::end() {
    return data + sz;
}

bool Str::operator==(Str& rhs) {
    if (sz == rhs.sz)
        return memcmp(data, rhs.data, sz) == 0;
    return false;
}

bool Str::operator==(const Str& rhs) {
    if (sz == rhs.sz)
        return memcmp(data, rhs.data, sz) == 0;
    return false;
}

// TODO
bool Str::operator!=(Str& rhs) {
    return !(*this == rhs);
}

bool Str::operator!=(const Str& rhs) {
    return !(*this == rhs);
}

ostream& operator<<(ostream& os, const Str& s) {
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

Str& Str::operator +=(const Str& s) {
    size_type nsz = s.size() + sz;
    char *tmp = new char[nsz];
    memcpy(tmp, data, sz);
    memcpy(tmp + sz, s.data, s.size());
    uncreate();
    sz = nsz;
    data = tmp;
    return *this;
}

Str operator+(const Str& sl, const Str& sr) {
    Str r = sl;
    r += sr;
    return r;
}

istream& operator>>(istream& is, Str& s) {
    vector<char> new_str;
    char c;

    // read new str into vec to get size
    while (is.get(c) && isspace(c))
        ;

    if (is) {
        do {
            new_str.push_back(c);
        } while (is.get(c) && !isspace(c));

        if (is)
            is.unget();
    }

    // populate our string
    s.create(new_str.size());
    copy(new_str.begin(), new_str.end(), s.begin());

    return is;
}

/* implementaiton details */
void Str::create() {
    data = NULL;
    sz = 0;
}

void Str::create(size_type n) {
    data = new char[n];
    sz = n;
}

void Str::create(size_type n, char c) {
    create(n);
    memset(data, c, n);
}

void Str::uncreate() {
    delete data;
    sz = 0;
}
