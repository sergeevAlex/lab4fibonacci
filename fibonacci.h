#ifndef FIBONACCI_FIBONACCI_H
#define FIBONACCI_FIBONACCI_H
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;
template<typename T>
class Const_iterator;

template<typename T>
class fibonacci {
private:
    T a;
    T b;
    int length;

public:
    friend class Const_iterator<T>;
    fibonacci( int size,T f, T s);
    fibonacci(int size);
    static void nextFibonacci(T& a,T& b);
    static void previuosFibonacci(T&a, T&b);
    static T calcFibonacci(T &a, T&b, int shift);
    T at(int index);
    Const_iterator<T> cbegin(){
        return Const_iterator<T>(*this);
    }
    Const_iterator<T> cend(){
        return Const_iterator<T>(length,*this);
    }
    void resize(int size);
    int size(){
        return length;
    }
};
template<typename T>
class Const_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    fibonacci<T> const& fi;
    T a,b;
    int it_index;
    int num_index;
public:
    Const_iterator(fibonacci<T> const& fa):fi(fa),a(fi.a),b(fi.b){//add size
        it_index = 0;
        num_index = 0;
    }

    Const_iterator(int index, fibonacci<T> const& fa):fi(fa),a(fi.a),b(fi.b){
        it_index = index;
        num_index = 0;
    }

    Const_iterator(Const_iterator const& yo):fi(yo.fi) {
        it_index = yo.it_index;
        num_index = yo.num_index;
        a = yo.a;
        b = yo.b;
    }

    T operator*(){
        int shift = it_index - num_index;
        switch(shift){
            case -1: {return a;}
            case 0:  {return b;}
            default: {
                num_index+=shift;
                return fi.calcFibonacci(a,b,shift);
            }
        }
    }

    Const_iterator& operator--(){
        it_index--;
    }

    Const_iterator operator--(int){
        it_index--;
    }

     Const_iterator& operator=(Const_iterator ci){
        num_index = ci.num_index;
        it_index = ci.it_index;
        a = ci.a;
        b = ci.b;
    }

    Const_iterator& operator++(){
       this->it_index++;
        return *this;
    }

    Const_iterator operator++(int){
        this->it_index++;
        return *this;
    }



    Const_iterator& operator-=(int index){
        this->it_index -= index;
        return (*this);
    }

    Const_iterator& operator+=(int index){//iterator&
       this->it_index += index;
        return (*this);
    }

    bool operator==(Const_iterator& it){
        return it.it_index==this->it_index;
    }

    bool operator<(const Const_iterator& it){
        return this->it_index<it.it_index;
    }
    bool operator>(const Const_iterator& it){
        return this->it_index>it.it_index;
    }

    bool operator>=(const Const_iterator& it){
        return this->it_index>=it.it_index;
    }

    bool operator<=(const Const_iterator& it){
        return this->it_index<=it.it_index;
    }

    T* operator->(){
        return &operator*();
    }

    bool operator!=(Const_iterator it){
        return this->it_index != it.it_index;
    }

    Const_iterator operator+(int index){
       this->it_index += index;
        return *this;
    }

    Const_iterator operator-(int index){
        this->it_index -= index;
       return *this;
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
