#include <algorithm>

#include "Vec.h"

using namespace std;

template <class T> Vec<T>::Vec() { create(); }

//template <class T> Vec<T>::Vec(size_type n, const T& t = T()) { create(n, t); }

template <class T> Vec<T>::Vec(const Vec& v) { create(v.begin(), v.end()); }

template <class T> Vec<T>::~Vec() { uncreate(); }

template <class T> void Vec<T>::push_back(const T& t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
}


template <class T> void Vec<T>::create() {
    data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    limit = avail = uninitialized_copy(i, j, data);
}

// invariant: data exists
// doesn't update data and avail pointers, though
template <class T> void Vec<T>::destroy_all() {
    iterator it = avail;
    while (it != data)
        alloc.destroy(--it);
}

template <class T> void Vec<T>::clear() {
    if (data) {
        destroy_all();
    }
    data = avail = 0;
}

template <class T> void Vec<T>::uncreate() {
    if (data) {
        destroy_all();
        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}

 template <class T> void Vec<T>::grow() {
     size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

     iterator new_data = alloc.allocate(new_size);
     iterator new_avail = uninitialized_copy(data, avail, new_data);

     uncreate();

     data = new_data;
     avail = new_avail;
     limit = data + new_size;
 }

 template <class T> void Vec<T>::unchecked_append(const T& val) {
     alloc.construct(avail++, val);
 }

template <class T> typename Vec<T>::iterator Vec<T>::erase(iterator pos) {
     ptrdiff_t dist = pos - data;
     copy(pos + 1, avail, pos);
     return data + dist;
 }
