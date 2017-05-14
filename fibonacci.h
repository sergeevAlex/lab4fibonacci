#ifndef FIBONACCI_FIBONACCI_H
#define FIBONACCI_FIBONACCI_H

#include <algorithm>
#include <iterator>
template<typename T>
class const_iterator;

template<typename T>
class fibonacci {
private:
    T first;
    T second;
    int length;
public:
    friend class const_iterator;
    fibonacci(T f, T s, int size);
    fibonacci(int size);
    T cbegin(){} // return-type stl:iterator!
    T cend(){}   // return-type stl:iterator!
    T at();
    void resize(int size);
    int size(){
        return length;
    }
};

template<typename T>
class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    T a0;
    T a1;
    int it_index;
    int num_index;

public:
    const_iterator(const fibonacci& a):a0(a.first), a1(a.second){

    }

};

/*
 * template<typename T> class A {
 *
 *   typedef T value_type;
 *
 * };
 *      A<int>::value_type x;
 *
 *
 * */


#endif //FIBONACCI_FIBONACCI_H
