#ifndef STR_H
#define STR_H

#include <cstddef>
#include <istream>
#include <ostream>

class Str {
 public:
    typedef size_t size_type;
	typedef char* iterator;

    Str();

    Str(const char* cp);

    Str(size_type n, char c);

    template <class In> Str(In b, In e);

    iterator begin();
    iterator end();

    char& operator[](size_type i) { return data[i]; };
    const char& operator[](size_type i) const { return data[i]; };

    // equality operators
    bool operator==(Str& rhs);
    bool operator==(const Str& rhs);

    bool operator!=(Str& rhs);
    bool operator!=(const Str& rhs);

    size_type size() const { return sz; };

	friend std::istream& operator>>(std::istream&, Str&);
    friend std::ostream& operator<<(std::ostream&, const Str&);

    Str& operator +=(const Str& s);

 private:
    char *data;
    size_type sz;

    // idea taken from Vec
	void create();
	void create(size_type);
	void create(size_type, char c);

	void uncreate();
};

Str operator +(const Str&, const Str&);

#endif // STR_H
