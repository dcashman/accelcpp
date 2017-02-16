/*
 * 5 clases of iterators
 *  - read only <In> [==, !=, ++i, i++, *, ->]
 *  - write only <Out> [=, ++i, i++, *, ->]
 *  - rw sequential (previous two together) <For>
 *  - bidirectional (rw sequential plus reverse) <Bi>
 *  - random (bidirectional plus random access) <Ran>
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <class In1, class In2>
bool m_equal(In1 b, In1 e, In2 b2) {
    while (b != e) {
        if (*b++ != *b2++) {
            return false;
        }
    }
    return true;
}

template <class In1, class In2>
In1 m_search(In1 b, In1 e, In2 b2, In2 e2) {
    while (b != e) {
        if (m_equal(b2, e2, b))
            return b;
        else
            b++;
    }
    return e;
}

// find(b, e, t) alrady on p145
template <class In, class X>
In m_find(In begin, In end, const X& x) {
    while(begin != end && *begin != x)
        ++begin;
    return begin;
}

template <class In, class P>
In m_find_if(In begin, In end, P p) {
    while(begin != end && !p(*begin))
        ++begin;
    return begin;
}

// p146
template <class In, class Out>
Out m_copy(In begin, In end, Out dest) {
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

template <class In, class Out, class X>
Out m_remove_copy(In begin, In end, Out dest, const X& x) {
    while (begin != end) {
        if (*begin == x) {
            begin++;
            continue;
        }
        *dest++ = *begin++;
    }
    return dest;
}

template <class In, class Out, class P>
Out m_remove_copy_if(In begin, In end, Out dest, P p) {
    while (begin != end) {
        if (p(*begin)) {
            begin++;
            continue;
        }
        *dest++ = *begin++;
    }
    return dest;
}

template <class For, class X>
For m_remove(For b, For e, const X& x) {
    return m_remove_copy(b, e, b, x);
}

template <class In, class Out, class F>
Out m_transform(In b, In e, Out d, F f) {
    while (b != e)
        *d++ = f(*b++);
    return d;
}

template <class For, class P>
For m_partition(For b, For e, P p) {
    while (b != e) {
        For found = find_if(b, e, p);
        if (found == e)
            break;
        auto tmp = *found;
        *found = *b;
        *b = tmp;
        b++;
    }
    return b;
}

template <class In, class T>
T m_accumulate(In b, In e, T t) {
    while (b != e)
        t += *b++;
    return t;
}

int main() {
    // test equal
    vector<int> v1(6, 0);
    vector<int> v2(6, 1);

    if (m_equal(v1.begin(), v1.end(), v1.begin())
        && !m_equal(v1.begin(), v1.end(), v2.begin()))
        cout << "Test m_equal() PASSED" << endl;
    else
        cout << "Test m_equal() FAILED" << endl;

    // test search
    v1.resize(0);
    for (int i = 0; i < 6; i++)
        v1.push_back(i);
    if (m_search(v1.begin(), v1.end(), v2.begin() + 2, v2.end()) == v1.end()
        && m_search(v1.begin(), v1.end(), v1.begin() + 2, v1.end()) == v1.begin() + 2)
        cout << "Test m_search() PASSED" << endl;
    else
        cout << "Test m_search() FAILED" << endl;

    // test find
    if (m_find(v1.begin(), v1.end(), 3) == v1.begin() + 3)
        cout << "Test m_find() PASSED" << endl;
    else
        cout << "Test m_find() FAILED" << endl;

    // test find_if
    if (m_find_if(v1.begin(), v1.end(), [](int x) -> bool { if (x == 3) return true; else return false; }) == v1.begin() + 3)
        cout << "Test m_find() PASSED" << endl;
    else
        cout << "Test m_find() FAILED" << endl;

    // test copy
    v2.resize(0);
    m_copy(v1.begin(), v1.end(), back_inserter(v2));
    if (equal(v1.begin(), v1.end(), v2.begin()))
        cout << "Test m_copy() PASSED" << endl;
    else
        cout << "Test m_copy() FAILED" << endl;

    // test remove_copy
    v2.resize(0);
    m_remove_copy(v1.begin(), v1.end(), v2.begin(), 5);
    v1.pop_back();
    if (m_equal(v1.begin(), v1.end(), v2.begin()))
        cout << "Test m_remove_copy() PASSED" << endl;
    else
        cout << "Test m_remove_copy() FAILED" << endl;

    // test remove_copy
    v1.push_back(5);
    v2.resize(0);
    m_remove_copy_if(v1.begin(), v1.end(), v2.begin(),
                     [](int x) -> bool { if (x == 5) return true; else return false; });
    v1.pop_back();
    if (m_equal(v1.begin(), v1.end(), v2.begin()))
        cout << "Test m_remove_copy_if() PASSED" << endl;
    else
        cout << "Test m_remove_copy_if() FAILED" << endl;

    // test remove
    v1.push_back(5);
    m_remove(v1.begin(), v1.end(), 5);
    if (m_equal(v1.begin(), v1.end(), v2.begin()))
        cout << "Test m_remove() PASSED" << endl;
    else
        cout << "Test m_remove() FAILED" << endl;

    // test transform
    v2.resize(0);
    m_transform(v1.begin(), v1.end(), v2.begin(),
                [](int x) -> int { return 0; });
    v1.resize(0);
    for (int i = 0; i < 5; i++)
        v1.push_back(0);
    if (m_equal(v1.begin(), v1.end(), v2.begin()))
        cout << "Test m_transform() PASSED" << endl;
    else
        cout << "Test m_transform() FAILED" << endl;

    // test partition
    v1.resize(0);
    for (int i = 0; i < 6; i++)
        v1.push_back(i);
    m_partition(v1.begin(), v1.end(), [](int x) -> bool { if (x == 5) return true; else return false; });
    if (*v1.begin() == 5  && m_find(v1.begin() + 1, v1.end(), 5) == v1.end())
        cout << "Test m_partition() PASSED" << endl;
    else
        cout << "Test m_partition() FAILED" << endl;

    // test accumulate
    v1.resize(0);
    for (int i = 0; i < 6; i++)
        v1.push_back(i);
    int accum = 0;
    accum = m_accumulate(v1.begin(), v1.end(), accum);
    if (accum == 15)
        cout << "Test m_accumulate() PASSED" << endl;
    else
        cout << "Test m_accumulate() FAILED" << endl;

    return 0;
}
